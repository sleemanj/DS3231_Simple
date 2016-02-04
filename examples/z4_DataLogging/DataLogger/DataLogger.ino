#include <DS3231_Simple.h>

DS3231_Simple Clock;

void setup() {
  
  
  Serial.begin(9600);  
  Serial.println();
  
  Clock.begin();
    
  // Erase the contents of the EEPROM
  Clock.formatEEPROM();
  
  // First we will disable any existing alarms
  Clock.disableAlarms();
  
  // And now add the alarm to happen every second
  Clock.setAlarm(DS3231_Simple::ALARM_EVERY_SECOND); 
  
  Serial.println(F("Logging value of analogRead(A1), enter any character to dump the log."));
  
}

void loop() 
{ 
  if(Clock.checkAlarms())
  {
    // Time to log a data point
    Clock.writeLog(analogRead(A1));
    Serial.print('.');
  }
  
  if(Serial.available())
  {
    while(Serial.available()) Serial.read();
    dumpLog();
  }
}

void dumpLog()
{
  unsigned int loggedData;
  DateTime     loggedTime;
  
  // Note that reading a log entry also deletes the log entry
  // so you only get one-shot at reading it, if you want to do
  // something with it, do it before you discard it!
  unsigned int x = 0;
  while(Clock.readLog(loggedTime,loggedData))
  {
    if(x == 0)
    {
      Serial.println();
      Serial.println(F("Date,analogRead(A1)"));
    }
    
    x++;
    Clock.printTo(Serial,loggedTime);
    Serial.print(',');
    Serial.println(loggedData);
  }
  Serial.println();
  Serial.print(F("# Of Log Entries Found: "));
  Serial.println(x);
  Serial.println();
}