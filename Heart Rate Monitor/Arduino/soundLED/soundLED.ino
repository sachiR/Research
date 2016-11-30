// Arduino pin numbers
const int DO_pin = 2;
const int AO_pin = 0;
int sound;
int led2 = 9;
int led3 = 10;
int led4 = 11;

void setup() {
  pinMode(DO_pin, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {

    if (sound > 50) {
    digitalWrite(led2, HIGH);
  }
    if (sound < 50) {
    digitalWrite(led2, LOW);
  }
    if (sound > 100) {
    digitalWrite(led3, HIGH);
  }
    if (sound < 100) {
    digitalWrite(led3, LOW);
  }
    if (sound > 150) {
    digitalWrite(led4, HIGH);
  }
    if (sound < 150) {
    digitalWrite(led4, LOW);
  }
  sound = analogRead(AO_pin);
  Serial.print(digitalRead(DO_pin));
  Serial.print("-");
  Serial.println(analogRead(AO_pin));

 
  
}
