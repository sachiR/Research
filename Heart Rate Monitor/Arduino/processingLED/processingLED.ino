int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  //Have the arduino wait to receive input
  while (Serial.available() == 0);

  //Read he Input
  int Val = Serial.read() - '0';

  if (Val == 1) {
    Serial.println("LED is ON");
    digitalWrite(redPin, HIGH);
  } 
  else if (Val == 0) {
    Serial.println("LED is OFF");
    digitalWrite(redPin, LOW);
  }
  else {
    Serial.println("Invalid");
  }
  Serial.flush();

}
