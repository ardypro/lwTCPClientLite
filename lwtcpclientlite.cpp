#include "lwTCPClientLite.h"
#include "HardwareSerial.h"

#include "stdio.h"
#include <string.h>

#define leadingCMD "{\"method\": \"upload\",\"data\":["
#define endingCMD "]}&^!"


void CMD_Composite(char* &cmd,const char* s,const char* v)
{
    //{"Name":"SD","Value":"33"},
    converter.appendChar(cmd,"{\"Name\":\"");
    converter.appendChar(cmd, s);
    converter.appendChar(cmd,"\",\"Value\":\"");
    converter.appendChar(cmd,v);
    converter.appendChar(cmd,"\"},");
}

void lwTCPClientLite::append(const char* sensor, bool value)
{
    append(sensor, (int)value);
};

void lwTCPClientLite::append(const char* sensor, int value)
{
    char* i;
    converter.intToStr(value, i);
    CMD_Composite(cmdJSON,sensor,i);
    converter.FreeAndNil(i);
};

void lwTCPClientLite::append(const char* sensor, unsigned int value)
{
    char* u ;
    converter.uintToStr(value,u);
    CMD_Composite(cmdJSON,sensor,u);
    converter.FreeAndNil(u);
};

void lwTCPClientLite::append(const char* sensor, long value)
{
    char* l;
    converter.longToStr(value, l);
    CMD_Composite(cmdJSON,sensor,l);
    converter.FreeAndNil(l);
};

void lwTCPClientLite::append(const char* sensor, unsigned long value)
{
    char* u;
    converter.ulongToStr(value,u);
    CMD_Composite(cmdJSON,sensor, u);
    converter.FreeAndNil(u);
};

void lwTCPClientLite::append(const char* sensor, double value,unsigned int digits)
{
    char* f;
    //f= (char*) malloc(1); //test only
    converter.floatToStr(value, digits,f);
    CMD_Composite(cmdJSON,sensor,f);
    converter.FreeAndNil(f);
};

void lwTCPClientLite::append(const char* sensor, const char* value)
{
    CMD_Composite(cmdJSON,sensor,value);
};


void lwTCPClientLite::upload()
{
    lwGenericClient::upload();  //如果不写这一句，基类中同名函数被隐藏；如果没有其它操作，则可以不声明此函数，实例调用upload的时候，直接调用基类的同名方法
};

void lwTCPClientLite::update()
{
    // TODO (Ardypro#1#): 后面改为跟interval有关
    if(true)
    {
        char* cmd;
        int len = strlen(userKey) + strlen(gateWay) + 51;
        cmd = (char*) malloc(len);
        snprintf(cmd, len, "{\"method\":\"update\",\"gatewayNo\":\"%s\",\"userkey\":\"%s\"}&^!", gateWay, userKey);

        DEBUG.print(cmd);
    }
}

void lwTCPClientLite::uploadValue()
{
    //DEBUG.print((char*)"Uploading...\n\t\n");
    int len;
    len=strlen(cmdJSON);
    cmdJSON[len-1]='\0';

    converter.appendChar(cmdJSON, endingCMD);
    DEBUG.print(cmdJSON);
}

void lwTCPClientLite::clearCommand()
{
    lwGenericClient::clearCommand();
    setLeadingChars();
}

void lwTCPClientLite::setLeadingChars()
{
    converter.appendChar(cmdJSON, leadingCMD);
}
