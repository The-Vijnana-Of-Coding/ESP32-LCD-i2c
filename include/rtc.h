#include <Arduino.h>

//***** - private libs - *****//
#include <isDebug.h>

//***** - NTP Time - *****//
time_t now; // this is the epoch
tm myTimeInfo;

//*************************************************//
//*******************Variables*********************//
//*************************************************//

//***** - NTP Time - *****//
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;

//*************************************************//
//********************Functions********************//
//*************************************************//

//#####  NTP Sync Function  ######//
void synchroniseWith_NTP_Time() {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    debugln("Syncing Time Now!");

    while (myTimeInfo.tm_year + 1900 < 2022) {
        time(&now);
        localtime_r(&now, &myTimeInfo);
        delay(200);
        debug(".");
    }
    debugln("\n Time Sync DONE!");
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////