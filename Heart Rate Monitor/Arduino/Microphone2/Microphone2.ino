// Arduino pin numbers
const int DOPin = 2;
const int AOPin = 0; //the microphone positive terminal will connect to analog pin A0 to be read
int sound;//the variable that will hold the value read from the microphone each time
unsigned long duration;

void setup(){
  Serial.begin(9600);//the arduino takes continuous readings from the microphone
  //pinMode(DOPin, INPUT);
}

void loop(){
  sound = analogRead(AOPin);//the arduino takes continuous readings from the microphone
  delay(100);
  }
}

