#include <DS3231_Simple.h>

DS3231_Simple Clock;

void setup() {
  
 
  Serial.begin(9600); delay(1000);
  Clock.begin();
  
  Serial.println();
  Serial.println(F("Example to show different built in print formats..."));
  Serial.println();  
}

void loop() 
{ 
  // For just printing the current date/time to a "Stream" such as Serial
  Serial.println("The currently (set) date and time is...");
  Clock.printTo(Serial);
  Serial.println();
  
  Clock.printDateTo_DMY(Serial);
  Serial.println();
  
  Clock.printDateTo_MDY(Serial);
  Serial.println();
  
  Clock.printDateTo_YMD(Serial);
  Serial.println();
  
  Clock.printTimeTo_HMS(Serial);
  Serial.println();
  
  Clock.printTimeTo_HM(Serial);
  Serial.println();
  
  Clock.print12HourTimeTo_HMS(Serial);
  Serial.println();
  
  Clock.print12HourTimeTo_HM(Serial);
  Serial.println();
    
  // If you want to print a specific date time...  
  Serial.println();
  Serial.println("This is how the 3rd of October in 2020 would look like at 14:17 and 33 seconds...");
  DateTime MyTimestamp;
  
  MyTimestamp.Day    = 3;
  MyTimestamp.Month  = 10;
  MyTimestamp.Year   = 20; 
  MyTimestamp.Hour   = 14;
  MyTimestamp.Minute = 17;
  MyTimestamp.Second = 33;
  
  
  Clock.printTo(Serial, MyTimestamp);
  Serial.println();
  
  Clock.printDateTo_DMY(Serial,MyTimestamp);
  Serial.println();
  
  Clock.printDateTo_MDY(Serial,MyTimestamp);
  Serial.println();
  
  Clock.printDateTo_YMD(Serial,MyTimestamp);
  Serial.println();
  
  Clock.printTimeTo_HMS(Serial,MyTimestamp);
  Serial.println();
  
  Clock.printTimeTo_HM(Serial,MyTimestamp);
  Serial.println();
  
  Clock.print12HourTimeTo_HMS(Serial,MyTimestamp);
  Serial.println();
  
  Clock.print12HourTimeTo_HM(Serial,MyTimestamp);
  Serial.println();
  
  Serial.println();
  
  Serial.println();
  Serial.print("End Of Program (RESET to run again)");
  while(1);
}