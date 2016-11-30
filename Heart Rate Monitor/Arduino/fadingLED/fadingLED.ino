int LED=10; //The word “LED” stands for the number 9.
int brightness=0; //The word “brightness” stands for the value that is emitted
//at the PWM.The number “0” is only used as an initial value.
int fading=5; //”fading” sets up the speed of the fading.

void setup()
{
  pinMode(LED, OUTPUT);  //The pin with the LED is supposed to be an output.
}
 
void loop()
{
 analogWrite(LED, brightness); //The function analog is used to activate the PWM 
 //output on the pin with the LED. 
 //The value of the PWM is saved under the word "brightness". In this case it is "0"

  brightness = brightness + fading; //  Now we modify the value of the PWM output. We
//add the value of the fading to the value of the brightness. In this case:
//brightness = 0+5. The new value that is standing for brightness isn't 0 any
// longer but 5. When the program has ran through the loop part once it will
//start over again. The next pass the value will be 10. After that it will be
// 15... etc.

delay(25); //The LED should only stay bright for a really short time like 25
//milliseconds. If you reduce that time the fading will also get faster.

if (brightness == 0 || brightness == 255) {
  fading = -fading; 
}

}
 
