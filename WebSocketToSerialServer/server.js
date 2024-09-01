/*
npm init -y
npm install serialport
npm install express
npm install ws
type nul > server.js
*/

/*******************Settings*******************/
const COM_PORT = 'COM4'
const COM_BAUDRATE = 9600;
/**********************************************/

const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');
const { Server } = require('ws');

printCOMPorts();

// Replace with your Arduino's serial port path
const port = new SerialPort({ path: COM_PORT, baudRate: COM_BAUDRATE });

// The ReadlineParser will emit data once a newline is received
const parser = port.pipe(new ReadlineParser());

// Set up WebSocket server
const wss = new Server({ port: 8080 });

wss.on('connection', function connection(ws) {
  console.log('A client connected');

  // When a WebSocket message is received
  ws.on('message', function incoming(message) {
    console.log('received from client: %s', message);
    // Write to the Arduino serial port
	//ws.send('Echo: ' + message);		//Habilitar para el echo.
    port.write(message + '\n', function(err) {
      if (err) {
        return console.log('Error on write: ', err.message);
      }
      console.log('message written to Arduino');
    });
  });

  // When data is received from the Arduino, send it to the client
  parser.on('data', function(data) {
    console.log('received from Arduino: ', data);
    ws.send(data);
  });
});

// Open errors will be emitted as an error event
port.on('error', function(err) {
  console.log('Error: ', err.message);
});


// Keep the script running
function keepAlive() {
  setTimeout(keepAlive, 1000);
}

async function printCOMPorts() {
  try {
    const ports = await SerialPort.list();
	console.log('Listing COM ports:');
    if (ports.length === 0) {
      throw new Error('No serial ports found');
    }

    for (const port of ports) {
      console.log(port); // Log the ports to see their details
    }
  } catch (error) {
    console.error('Error listing ports:', error);
  }
}

console.log('WebSocket server started on ws://localhost:8080');
//keepAlive();
