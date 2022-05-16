#include <LiquidCrystal_I2C.h>


#include <Wire.h> 
#include <PMsensor.h>
PMsensor PM;
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  Serial.begin(9600);
   /////(infrared LED pin, sensor pin)  /////
  PM.init(3, A0);       // 3번을 2번으로 바꾼다.  
}
void loop() {
  Serial.println("=================================");
  Serial.println("Read PM2.5");
float filter_Data = PM.read(0.1);
  float noFilter_Data = PM.read();
  lcd.init();
        lcd.backlight();
        lcd.setCursor(3,0);
        lcd.print("Filter :");
        lcd.print(filter_Data);
        Serial.println(filter_Data);
        Serial.print("noFilter : ");
  Serial.println(noFilter_Data);
        delay(1000);
}
  
  
