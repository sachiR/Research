/*
 * First ever program in Arduino
 */
 
void setup() 
{// put your setup code here, to run once:
  pinMode(13, OUTPUT); //Pin 13 is supposed to be an output.
}

void loop() 
{// put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); //Turn on the voltage on pin 13 (LED on)
  delay(2000); //Wait for 1000 miliseconds (one second)
  digitalWrite(13, LOW); //Turn off the voltage on pin 13 (LED off)
  delay(2000); //Wait for 1000 miliseconds (one second)  
}
