/*  NOTE: ESP32-LCD-i2c project
    Target: ESP32 Dev kit
    Author: Mark Caton
*/

#include <Arduino.h>
//***** - external libs - *****//
#include <WiFi.h>
//***** - private libs - *****//
#include <Timing.h>
#include <credentials.h>
#include <display.h>
#include <isDebug.h>
#include <rtc.h>

extern LiquidCrystal_I2C lcd;

//*************************************************//
//*******************Variables*********************//
//*************************************************//

//***** - Wifi - *****//
byte wifiCount = 0;
const byte wifiCountLimit = 11;

//*************************************************//
//********************Functions********************//
//*************************************************//

//#####  Connect to wifi Function  ######//
void wifiConnect() {
    if (WiFi.status() != WL_CONNECTED && wifiCount < wifiCountLimit) {
        debug('.');
        wifiCount++;
        delay(250);
        wifiConnect();
    } else if (WiFi.status() == WL_CONNECTED) {
        debugln();
        debug("Local IP: ");
        debugln(WiFi.localIP());
        debug("RRSI: ");
        debugln(WiFi.RSSI());
        wifiCount = 0;
        delay(250);
    }
}
/////////////////////////////////////////////////////

//##### Main Setup Function ######//
void setup() {
    //***** - Serial - *****//
    Serial.begin(115200);
    //***** - Wifi - *****//
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    debugln("Connecting to WiFi ..");
    wifiConnect();
    //***** - Screen - *****//
    lcd.init();
    lcd.backlight();
    //***** - Time - *****//
}
/////////////////////////////////////////////////////

//##### Main Loop Function ######//
void loop() {
    //***** - CHECK FOR WIFI - *****//
    if (WiFi.status() != WL_CONNECTED) {
        debugln();
        debug("Reattempting connection to WiFi ..");
        wifiConnect();
    }
    //***** - CALL MAIN TIMING FUNCTION - *****//
    mainTiming();
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////