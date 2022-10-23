#include <Arduino.h>

// external libs
#include <ESP32Time.h>
#include <isDebug.h>

extern void displayLCDTime();
extern void synchroniseWith_NTP_Time();

//***** - RTC/Time Objects - *****//
ESP32Time rtc;
tm timeNow;

//*************************************************//
//*******************Variables*********************//
//*************************************************//

//***** - Time - *****//
time_t prev_time1 = 0;
time_t prev_time10 = 0;


//*************************************************//
//********************Functions********************//
//*************************************************//

//#####  get RTC time and convert to epoch  ######//
time_t getTimeEpoch() { // create now epoch time
    timeNow.tm_year = rtc.getYear() - 1900; // This is year-1900
    timeNow.tm_mon = rtc.getMonth();
    timeNow.tm_mday = rtc.getDay();
    timeNow.tm_hour = rtc.getHour(true); // 24hr format
    timeNow.tm_min = rtc.getMinute();
    timeNow.tm_sec = rtc.getSecond();
    time_t timeNowEpoch = mktime(&timeNow);
    return timeNowEpoch;
}
//////////////////////////////////////////////////////////////////////////

//#####  mainTiming function  ######//
void mainTiming() {
    // add time specific tasks here

    // do something every 1 sec
    if (getTimeEpoch() - prev_time1 >= 1) {
        debugln("-------Time Now-------");
        debugln(rtc.getTime("%A, %B %d %Y %H:%M:%S")); // (String) returns time with specified format
        debugln("----------------------");
        displayLCDTime();
        prev_time1 = getTimeEpoch();
    }
    if (getTimeEpoch() - prev_time10 >= 10) {
        prev_time10 = getTimeEpoch();

        synchroniseWith_NTP_Time();
    }
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
