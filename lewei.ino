//#include <Arduino.h>
#include "lwtcpclientlite.h"
#include "conversion.h"
//#include "string.h"


const char* Userkey = "029b3884b91e4d00b514158ba1e2ac57";
const char* Gateway = "01";
int t = 0;
long l=0L;
double d=0.00f;

lwTCPClientLite client(Userkey, Gateway);

void DELEAY()
{
    delay(20000);
}

void testAppend()
{
    lwTCPClientLite client(Userkey, Gateway);
    client.update();

    delay(15000);

    char* fc;
    fc=(char*) malloc(1);

    const char* sensor="WD";
    const char* h="SD";
    const char* ydl="YDL";

    client.append(h,d);
    client.append(sensor,t);
    client.append(ydl,l);

    client.upload();

    t++;
    d+=0.1;
    l+=10;

    converter.FreeAndNil(fc);

}


void setup()
{
    Serial.begin(38400);
    //client.lastTime = 200;


    testAppend();
    DELEAY();
}

void loop()
{
    testAppend();
    DELEAY();

}
