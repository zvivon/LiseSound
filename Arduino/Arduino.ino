

const int BUTTON_PIN_0 = 12;
const int sensor1 = 3;
const int sensor2 = 5;
//int pirState1 = LOW;             
int val = 0;

void setup() {

  // Set up the first button.
  pinMode(BUTTON_PIN_0, INPUT_PULLUP);

  // Set up the second button.
  pinMode(sensor1, INPUT_PULLUP);
  
  // Start our Serial device.
  Serial.begin(9600);
}

void loop() {

  // Read the first button value.
  int buttonValue_0 = digitalRead(BUTTON_PIN_0);

  // Read the second button value.
  int sensor1Value = digitalRead(sensor1);
  int sensor2Value = digitalRead(sensor2);

  Serial.print(buttonValue_0);
  Serial.print(",");

  // Send the first button value.
  // This can only send values between 0 - 1.
  Serial.print(sensor1Value);
  Serial.print(",");

  // Send the second button value.
  // This can only send values between 0 - 1.
  Serial.print(sensor2Value);

  // Send the line feed character indicating that we are done sending this "packet".
  Serial.print('\n');

  // Delay to make sure the serial buffers aren't overwhelmed.
  delay(20);
}

