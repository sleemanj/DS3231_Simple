#include <DS3231_Simple.h>

DS3231_Simple Clock;

void setup() {
  
  
  Serial.begin(9600);  
  Serial.println();
  
  Clock.begin();
  
  // We will set 2 alarms, the first alarm will fire at the 30th second of every minute
  //  and the second alarm will fire every minute (at the 0th second)
  
  // First we will disable any existing alarms
  Clock.disableAlarms();
  
  // Get an initialized timestamp
  DateTime MyTimestamp = Clock.read();              
  
  // We want the alarm at this second
  MyTimestamp.Second   = 30;                       
  
  // And now add the alarm to happen when the second matches
  Clock.setAlarm(MyTimestamp, DS3231_Simple::ALARM_MATCH_SECOND); 
  
  // We will set the second alarm to match every minute, since there's 
  // no specific time/date data necessary for that we don't have to
  // supply any (but you could if you wanted just like the above).
  Clock.setAlarm(DS3231_Simple::ALARM_EVERY_MINUTE); 
  
  // See comments at bottom of file for more alarm types!
  
  Serial.println("Waiting for alarms...");
  
}

void loop() 
{ 
  // To check the alarms we just ask the clock
  uint8_t AlarmsFired = Clock.checkAlarms();
  
  // Then can check if either alarm is fired (there are 2 alarms possible in the chip)
  // by using a "bitwise and"
  if(AlarmsFired & 1)
  {
    Clock.printTo(Serial); Serial.println(": First alarm has fired!");
  }
  
  if(AlarmsFired & 2)
  {
    Clock.printTo(Serial); Serial.println(": Second alarm has fired!");
  }
    
}


 /* There are 2 different alarms possible in the chip, the first alarm has a
  * resolution of seconds, the second a resolution of minutes.
  * 
  * Which alarm gets modified by setAlarm() depends on the type of alarm
  * you want.
  * 
  * The following alarm types are available.
  * 
  *  (Alarm 1)
  *    ALARM_EVERY_SECOND  (Timestamp not required)                   
  *    ALARM_MATCH_SECOND                    
  *    ALARM_MATCH_SECOND_MINUTE             
  *    ALARM_MATCH_SECOND_MINUTE_HOUR        
  *    ALARM_MATCH_SECOND_MINUTE_HOUR_DATE   
  *    ALARM_MATCH_SECOND_MINUTE_HOUR_DOW    
  *    
  * (Alarm 2)
  *    ALARM_EVERY_MINUTE (Timestamp not required)                   
  *    ALARM_MATCH_MINUTE                    
  *    ALARM_MATCH_MINUTE_HOUR               
  *    ALARM_MATCH_MINUTE_HOUR_DATE          
  *    ALARM_MATCH_MINUTE_HOUR_DOW           
  *    
  * (Alarm 2)
  *    ALARM_HOURLY   (on the minute of the supplied timestamp *)
  *    ALARM_DAILY    (on the hour and minute *)            
  *    ALARM_WEEKLY   (on the hour and minute and day-of-week *)                             
  *    ALARM_MONTHLY  (on the hour and minute and day-of-month *)
  * 
  *  * If set without a timestamp, the current timestamp is used.
  */