// LED Traffic Light Simulation
// This program simulates a traffic light system with a pedestrian crossing button.

const int redLightPin = 12;   // Red LED connected to GPIO 23
const int yellowLightPin = 14; // Yellow LED connected to GPIO 22
const int greenLightPin = 21;  // Green LED connected to GPIO 21
const int buttonPin = 1;      // Pedestrian crossing button connected to GPIO 19

void setup() {
   pinMode(redLightPin, OUTPUT);
   pinMode(yellowLightPin, OUTPUT);
   pinMode(greenLightPin, OUTPUT);
   pinMode(buttonPin, INPUT_PULLUP);  // Use INPUT_PULLUP for button
  // Initialize the LED pins as outputs
  // TODO: Set the button pin as INPUT
}

void loop() {
  // TODO: Implement the traffic light sequence
  // Use delays for light timing: Red, Yellow, Green
  
  // TODO: Implement pedestrian crossing logic
  // Change light sequence when button is pressed
  if (digitalRead(buttonPin) == LOW) {  // Button is pressed
    digitalWrite(redLightPin, LOW);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
  } else {  // Button is not pressed
    digitalWrite(redLightPin, HIGH);    // turn on LED1 
    delay(200);                  // wait for 200ms
    digitalWrite(yellowLightPin, HIGH);    // turn on LED2
    delay(200);                  // wait for 200ms       
    digitalWrite(greenLightPin, HIGH);    // turn on LED3 
    delay(200);                  // wait for 200ms
    digitalWrite(redLightPin, LOW);     // turn off LED1
    delay(300);                  // wait for 300ms
    digitalWrite(yellowLightPin, LOW);     // turn off LED2
    delay(300);                  // wait for 300ms
    digitalWrite(greenLightPin, LOW);     // turn off LED3
    delay(300);                  // wait for 300ms before running the sequence again
  }
}

