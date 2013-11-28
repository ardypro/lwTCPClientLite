//#include <Arduino.h>
#include "lwtcpclientlite.h"
#include "conversion.h"
//#include "string.h"


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
    unsigned long t=millis();
    if((t-lastUpdate)>50000)
    {
        client.connect();
        lastUpdate=t;
    }

    if((t- lastUpload)>=10000)
    {
        client.append("test", l);
        client.upload();
        lastUpload=t;
        l++;
    }


}
