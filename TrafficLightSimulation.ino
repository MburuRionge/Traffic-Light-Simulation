// define pin numbers fo the LEDs and the button
const int redLightPin = 8;
const int yellowLightPin = 9;
const int greenLightPin = 10;
const int buttonPin = 2; //button is connected to pin2

// Variable to track button press state
volatile bool buttonPresses = false;

// Setup function
void setup() {
  //initialize the LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pimMode(greenLightPin, OUTPUT);

  // initialize the button pin as input with internal pull-up
  pinMode(buttonPin, INPUT_PULLUP);

  // Attach an interrupt to the button press
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);

  // start serial communication (optional for debugging)
  Serial.begin(9600);
}

// Main loop
void loop() {
  if (buttonPressed) {
    // pedestrian crossing logic
    Serial.println("Pedestrian button pressed! Changing sequence...");

    // stop normal sequence and turn on the red light for crossing
    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
    delay(5000);

    // After pedestrian crossing reset hte button state and return to normal sequence
    buttonPressed = false;
  } else {
    // Normal traffic light sequence
    digitalWrite(redLightPin, HIGH);  // red light on
    delay(5000);                      // wait 5 seconds
    digitalWrite(redLightPin, LOW);   // red light off

    digitalWrite(yellowLightPin, HIGH);  //Yellow light on
    delay(2000);
    digitalWrite(yellowLightPin, LOW);

    digitalWrite(greenLightPin, HIGH);
    delay(5000);
    digitalWrite(greenLightPin, LOW);

    digitalWrite(yellowLightPin, HIGH);  //Yellow light on
    delay(2000);
    digitalWrite(yellowLightPin, LOW);
  }
}

// interrupt service routine (ISR) for button press
void buttonInterrupt() {
  buttonPressed = true;
}