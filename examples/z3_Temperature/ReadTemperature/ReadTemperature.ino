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
  // Temperature can be read as a rounded integer value, or a floating point
  //   float is more precise but takes a bunch of memory and flash space  
  byte  MyIntegerTemperature;
  float MyFloatTemperature;
  
  // Ask the clock for the data.
  MyIntegerTemperature = Clock.getTemperature();
  MyFloatTemperature   = Clock.getTemperatureFloat();
  
  // And use it
  Serial.println("Note that temperature is updated every 64 seconds by the DS3231.");
  
  Serial.print("Integer Temperature: "); Serial.println(MyIntegerTemperature);
  Serial.print("Float Temperature:   "); Serial.println(MyFloatTemperature);
  Serial.println();
  delay(65000);
}