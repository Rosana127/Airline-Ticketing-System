// global.cpp
#include "global.h"

// 全局变量定义
QString departPlace = "";  // 初始值为空字符串  出发地
QString arrivalPlace = ""; // 初始值为空字符串   到达地
QDate selectedDate = QDate::currentDate(); // 默认日期为当前日期
QString timeh="00:04:00";
QString g_userName = "刘先生";     //用户名
QString g_userPhone = "1111";   //用户手机号
QString seatType="经济舱";   //选中舱位
QString price=0;     //机票价格
double pricedb=0;    //写入数据库的数据
int flisingleHeight=150;    //flightsingle的单元格高度
QString airnumber="0";     //  航班号
QString managerairnumber="0";    // 管理员修改航班的号码
QStackedWidget* homepagemain=nullptr;
QStackedWidget* homemanagermain=nullptr;
int widthq=1340;
int heightq=991;
//QString sexValue="男";
