// Arduino pin numbers
const int DOPin = 2;
const int AOPin = 0; //the microphone positive terminal will connect to analog pin A0 to be read
int sound;//the variable that will hold the value read from the microphone each time
int led1 = 8;//the code will flash the LED connected to pin 8
int led2 = 9;//the code will flash the LED connected to pin 9
int led3 = 10;//the code will flash the LED connected to pin 10
int led4 = 11;//the code will flash the LED connected to pin 11
int led5 = 12;//the code will flash the LED connected to pin 12

void setup(){
  Serial.begin(9600);//the arduino takes continuous readings from the microphone
  pinMode(DOPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop(){
  sound = analogRead(AOPin);//the arduino takes continuous readings from the microphone
  Serial.println(sound);
  
  if (sound > 31) {
    digitalWrite(led1, HIGH);
  }
    if (sound < 31) {
    digitalWrite(led1, LOW);
  }
    if (sound > 35) {
    digitalWrite(led2, HIGH);
  }
    if (sound < 35) {
    digitalWrite(led2, LOW);
  }
    if (sound > 40) {
    digitalWrite(led3, HIGH);
  }
    if (sound < 40) {
    digitalWrite(led3, LOW);
  }
    if (sound > 45) {
    digitalWrite(led4, HIGH);
  }
    if (sound < 45) {
    digitalWrite(led4, LOW);
  }
    if (sound > 50) {
    digitalWrite(led5, HIGH);
  }
    if (sound < 50) {
    digitalWrite(led5, LOW);
  } 
  delay(100);
}

