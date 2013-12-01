//#include <Arduino.h>
#include "lwtcpclientlite.h"
#include "HardwareSerial.h"
#include "conversion.h"
//#include "string.h"

//extern HardwareSerial Serial1;

const char* Userkey = "029b3884b91e4d00b514158ba1e2ac57";
const char* Gateway = "02";
int t = 0;
long l=0L;
double d=0.00f;

lwTCPClientLite client(Userkey, Gateway);
unsigned long lastUpload;
unsigned long lastUpdate;
void setup()
{
    //Serial1.begin(9600);

    Serial.begin(38400);
    client.connect();
    client.append("test", -1);
    client.upload();
    lastUpload=millis();
    lastUpdate=lastUpload;
    delay(10000);
}

int updates=1;
void loop()
{
    //unsigned long t=millis();
    if((millis()-lastUpdate)>=100)
    {
        client.connect();
        lastUpdate=millis();
    }

    //if((millis()- lastUpload)>=100)
    {
        client.append("test", l);
        client.upload();
        lastUpload=millis();
        l++;

        delay(100);
    }
}
