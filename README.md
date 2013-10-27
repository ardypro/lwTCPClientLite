lwTCP Client lite for Arduino
=============================

(从lwSerialWifiLite改名而来)


私有的乐为TCP长连接模块类库，不被官方支持

引用接口，将乐为服务分解成三个基本的接口，IGet接口负责从服务器下载数据，IPost接口用来上传传感器数据，IControllable接口负责反向控制功能。

lwTCPClientLite library只实现了IPost接口。
