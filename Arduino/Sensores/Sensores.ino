const int buttonPin = 2; // Pin number for the button
const int ledPin = 13; // Most Arduinos have an LED on pin 13
int lastButtonState = HIGH; // the previous state of the button
int currentButtonState; // the current state of the button

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Initialize the button pin as an input with an internal pull-up resistor
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // Turn on the LED
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  randomSeed(analogRead(0));
}

void loop() {

/*
  currentButtonState = digitalRead(buttonPin); // read the button state

  // compare the button state to its previous state
  if (currentButtonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (currentButtonState == LOW) {
      // if the current state is LOW then the button went from off to on:
      Serial.println("Button pressed");
    }
  
    // Delay a little bit to avoid bouncing
    delay(10);
 } 
 // save the current state as the last state, for next time through the loop
 lastButtonState = currentButtonState;
*/
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); //Leo la linea completa
    if (command == "LED ON") {
      digitalWrite(LED_BUILTIN, HIGH);  // Turn on the LED
      Serial.println("LED TURNED ON");
    } else if (command == "LED OFF") {
      digitalWrite(LED_BUILTIN, LOW);   // Turn off the LED
      Serial.println("LED TURNED OFF");
    } else if (command == "READ TEMP") {
      SendTemperature();
    } else if (command == "READ HUM") {
      SendHumidity();
    } else if (command == "READ LIGHT") {
      SendLight();
    }
  }
}

int SendTemperature()
{
  Serial.print(random(0, 40));
  Serial.println("ºC");
  //Serial.println("24ºC");
}

int SendHumidity()
{
  Serial.print(random(0, 100));
  Serial.println("%");
  //Serial.println("55%");
}

int SendLight()
{
  Serial.print(random(0, 1023));
  Serial.println("L");
}
