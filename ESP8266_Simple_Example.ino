#include <ESP8266WiFi.h>       // Built-in
#include <time.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("yourSSID", "yourPASSWORD");
  SetupTime();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(GetTime());
}

void SetupTime() {
  configTime(0, 0, "pool.ntp.org");
  setenv("TZ", "BST,M3.5.0/2,M10.5.0/2", 0);  // https://github.com/nayarsystems/posix_tz_db
  time_t tnow = time(nullptr);
  delay(750); // Requires ~ 750mS for time to start, sometimes longer
  tnow = time(nullptr);
  Serial.println(ctime(&tnow)); // prints 'Tue Jan 30 15:37:59 2018'
}

String GetTime(){
  time_t tnow = time(nullptr);
  return String(ctime(&tnow)); // returns "Tue Jan 30 15:37:59 2018"
}

