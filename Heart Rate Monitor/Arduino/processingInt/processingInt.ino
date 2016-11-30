void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()== 0);
  int val = Serial.read() - '0';
  Serial.println (val);
}
