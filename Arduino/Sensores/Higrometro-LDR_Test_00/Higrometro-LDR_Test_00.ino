/*higrometro code */
#define sensor A1
int valor = 0;

/*LDR code Code to read values of light */  
int sensorPin = A0; // Input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor



void setup(){
Serial.begin(9600);
}

void loop(){
  // higrometro loop
int valor = map(analogRead(sensor), 0, 1023, 100, 0);
//se hace un mapeo de la lectura del sensor a porcentual
Serial.print("Humedad: ");
Serial.print(valor);
Serial.println("%");
delay(100);

// Ldr loop
sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); // prints the value coming from the sensor
delay(100);
}
