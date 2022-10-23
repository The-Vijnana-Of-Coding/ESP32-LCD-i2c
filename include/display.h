#include <Arduino.h>
//***** - external libs - *****//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//*************************************************//
//********************Functions********************//
//*************************************************//

//#####  LCD Display Time Function  ######//
void displayLCDTime() {
    lcd.setCursor(0, 0);
    debugln(rtc.getTime("%a, %b %d"));
    lcd.print(rtc.getTime("%a, %b %d"));
    lcd.setCursor(0, 1);
    lcd.print(rtc.getTime("%H:%M:%S"));
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////