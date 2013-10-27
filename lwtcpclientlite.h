#ifndef lwTCPClientLite_H
#define lwTCPClientLite_H

#include "HardwareSerial.h"
#include "lwgenericclient.h"
#include "conversion.h"


/*
    乐为TCP长连接的协议
    ===================

    连接tcp.lewei50.com 或者IP：42.121.128.216   端口号：9960

    update: //连接心跳包
        {"method": "update","gatewayNo": "01","userkey": "029b3884b91e4d00b514158ba1e2ac57"}&^!
    upload: //上传数据
        {"method": "upload","data":[{"Name":"SD","Value":"33"},{"Name":"WD","Value":"96.2"}]}&^!


    因为串口wifi模块能够直接将从UART收到的数据转发给指定的域名和端口，因此只需要前期设置好wifi模块，
    Arduino就可以使用Serial将上述格式的数据包通过wifi模块发到乐为服务器。

*/

/*
    版本历史

    201310231140    1.0可用版
*/


class lwTCPClientLite : public lwGenericClient
{
public:
    /** Default constructor */
    lwTCPClientLite(const char* userkey, const char* gateway) : lwGenericClient(userkey, gateway)
    {
        intervalUpdate = 50000;     //50s
        lastUpdate = millis();
        setLeadingChars();
    };

    virtual  void update();         //发心跳包
    virtual  void append(const char* sensor, bool value);
    virtual  void append(const char* sensor, int value);
    virtual  void append(const char* sensor, unsigned int value);
    virtual  void append(const char* sensor, long value);
    virtual  void append(const char* sensor, unsigned long value);
    virtual  void append(const char* sensor, double value,unsigned int digits=2);
    virtual  void append(const char* sensor, const char* value);

    virtual void upload();          //上传数据

protected:
    virtual void uploadValue();     //上传数据方法的执行部分
    virtual void clearCommand();
private:
    unsigned long lastUpdate;       //上次心跳包发送时间
    unsigned int intervalUpdate;    //心跳包发送间隔
    void setLeadingChars();
};

#endif // lwTCPClientLite_H
