int switchpin = 8;    // switch connected to pin 8

void setup()
{
  pinMode(switchpin, INPUT); // pin 0 as INPUT
  Serial.begin(9600); // start serial communication at 9600bps
}

void loop()
{
  if (digitalRead(switchpin) == HIGH) // if switch is ON
  {
    Serial.write(1); // send 1 to Processing
  }
  else
  {
    Serial.write(0); // otherwise send 0 to Processing
  }
  delay(100); // wait 100ms for next print
}
