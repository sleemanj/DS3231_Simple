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
  DateTime MyDateAndTime;
  
  // Ask the clock for the data.
  MyDateAndTime = Clock.read();
  
  // And use it
  Serial.print("Hour: ");   Serial.println(MyDateAndTime.Hour);
  Serial.print("Minute: "); Serial.println(MyDateAndTime.Minute);
  Serial.print("Second: "); Serial.println(MyDateAndTime.Second);
  Serial.print("Year: ");   Serial.println(MyDateAndTime.Year);
  Serial.print("Month: ");  Serial.println(MyDateAndTime.Month);
  Serial.print("Day: ");    Serial.println(MyDateAndTime.Day);
  
  Serial.print("End Of Program (RESET to run again)");
  while(1);
}