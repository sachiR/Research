byte b = 0;

void setup() {
 Serial.begin(9600);

}

void loop() {
  for (int j = 0; j <360; j++){
    Serial.println(sin(j * (PI / 180)));
    Serial.println("0");
  }

}
