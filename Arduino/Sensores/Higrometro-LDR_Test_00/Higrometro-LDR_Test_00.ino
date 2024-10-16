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
  int valor = analogRead(sensor);
  /* int valor = map(analogRead(sensor), 0, 1023, 100, 0);
  -- usada antes para hacr un mapeo de la lectura del sensor a porcentua */
  Serial.print(valor);
  Serial.println("%");
  delay(100);
  
  // Ldr loop
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.print(sensorValue); // prints the value coming from the sensor
  Serial.println("L");
  delay(100);
}
