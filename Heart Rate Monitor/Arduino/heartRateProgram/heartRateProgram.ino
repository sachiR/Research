// Arduino ppg Signal
#include <firFilter.h>
firFilter Filter;
int value;
int filtered;
void setup()
{
 Serial.begin(7200);
 Filter.begin();
}
void loop()
{
 value = analogRead(A0);
 filtered= Filter.run(value);
/* Serial.print("In: ");
 Serial.print(value);
 Serial.print(" - Out: ");*/
 Serial.println(filtered);
 delay(2); //make it readable
