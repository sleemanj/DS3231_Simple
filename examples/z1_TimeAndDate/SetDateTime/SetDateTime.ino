#include <DS3231_Simple.h>

DS3231_Simple Clock;

void setup() {
  
  
  Serial.begin(9600);
  Clock.begin();
  
  Serial.println();
  Serial.println();
}

void loop() 
{ 
  // Create a variable to hold the data 
  DateTime MyTimestamp;
  
  // Load it with the date and time you want to set, for example
  //   Saturday the 3rd of October 2020 at 14:17 and 33 Seconds...
  MyTimestamp.Day    = 3;
  MyTimestamp.Month  = 10;
  MyTimestamp.Year   = 20; 
  MyTimestamp.Hour   = 14;
  MyTimestamp.Minute = 17;
  MyTimestamp.Second = 33;
  
  // Then write it to the clock
  Clock.write(MyTimestamp);
  
  // And use it, we will read it back for example...  
  Serial.print("The time has been set to: ");
  Clock.printTo(Serial);
  Serial.println();
  
  // Remember, once you set the time, the clock remembers it and keeps
  // running even if you reset or turn off your Arduino, as long as
  // the clock has battery power.
  
  Serial.print("End Of Program (RESET to run again)");
  while(1);
}