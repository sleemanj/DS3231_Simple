#include <DS3231_Simple.h>

DS3231_Simple Clock;

void setup() {
 
  Serial.begin(9600);
  Clock.begin();
  Clock.promptForTimeAndDate(Serial);

}

void loop() {    
  Clock.printDateTo_YMD(Serial);
  Serial.print(' ');
  Clock.printTimeTo_HMS(Serial);
  Serial.println();
  
  delay(1000);
}