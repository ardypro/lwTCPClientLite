#ifndef IGET_H
#define IGET_H

/*
    从服务器获取数据接口
    v1.0    @ 2013-10-01
*/
//#include "Arduino.h"

class IGet
{
public:
    IGet() ;

    virtual void getValue(const char* sensor, bool &value)=0;
    virtual void getValue(const char* sensor, int &value)=0;
    virtual void getValue(const char* sensor, unsigned int &value)=0;
    virtual void getValue(const char* sensor, long &value)=0;
    virtual void getValue(const char* sensor, unsigned long &value)=0;
    virtual void getValue(const char* sensor, float &value)=0;
    virtual void getValue(const char* sensor, double &value)=0;
    virtual void getValue(const char* sensor, char* &value)=0;
};

#endif // IGET_H
