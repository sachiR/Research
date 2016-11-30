int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 12;

void setup()
{ //We are starting with the setup
pinMode(led1, OUTPUT); //Pin 8 is defined as output
pinMode(led2, OUTPUT); //Pin 9 is defined as output
pinMode(led3, OUTPUT); //Pin 10 is defined as output
pinMode(led4, OUTPUT); //Pin 11 is defined as output
pinMode(led5, OUTPUT); //Pin 12 is defined as output

}
void loop()
{ //The main part starts
digitalWrite(led1, HIGH); //turn on the LED on pin 8
delay(1000); //wait for 1000 milliseconds
digitalWrite(led1, LOW); //turn off the LED on pin 8

digitalWrite(led2, HIGH); //turn on the LED on pin 9
delay(1000); //wait for 1000 milliseconds
digitalWrite(led2, LOW); //turn off the LED on pin 9

digitalWrite(led3, HIGH); //turn on the LED on pin 10
delay(1000); //wait for 1000 milliseconds
digitalWrite(led3, LOW); //turn off the LED on pin 10

digitalWrite(led4, HIGH); //turn on the LED on pin 11
delay(1000); //wait for 1000 milliseconds
digitalWrite(led4, LOW); //turn off the LED on pin 11

digitalWrite(led5, HIGH); //turn on the LED on pin 12
delay(1000); //wait for 1000 milliseconds
digitalWrite(led5, LOW); //turn off the LED on pin 12
}
