#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#define SERIALDEBUG

#ifdef SERIALDEBUG
#include "HardwareSerial.h"
#else
#include "stdio.h"
#endif

class debuglog
{
public:
    debuglog() {}
    virtual ~debuglog() {}

    void println(char* msg="")
    {
        print(msg);
        doubleNewline();
    }

    void println(long msg)
    {
        print(msg);
        doubleNewline();
    }

    void println(double msg)
    {
        print(msg);
        doubleNewline();
    }

    void print(char* msg)
    {
#ifdef SERIALDEBUG
        Serial.println(msg);
#else
        printf("%s", msg);
#endif
    }

    void print(long msg)
    {
#ifdef SERIALDEBUG
        Serial.println(msg);
#else
        printf("%ld",msg);
#endif
    }

    void print(double msg)
    {
#ifdef SERIALDEBUG
        Serial.println(msg);
#else
        printf("%f",msg);
#endif
    }

protected:
private:
    void doubleNewline()
    {
#ifdef SERIALDEBUG
        Serial.println("");
        Serial.println("");
#else
        printf("\n");
        printf("\n");
#endif
    }
};


static debuglog DEBUG;

#endif // DEBUGLOG_H
