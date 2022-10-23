#define isDebug true // if defined true, print is enabled, false is disabled

#if isDebug == true
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif