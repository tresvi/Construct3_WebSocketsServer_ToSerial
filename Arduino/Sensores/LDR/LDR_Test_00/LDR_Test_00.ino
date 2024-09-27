
/*Code to read values of light sensed by a LDR*/  

int sensorPin = A0; // Input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
Serial.begin(9600); 
}

void loop() {
sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); // prints the value coming from the sensor
delay(100);
}
