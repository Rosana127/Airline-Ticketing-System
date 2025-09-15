// global.h
#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QDate>
#include<QStackedWidget>
extern QString departPlace;
extern QString arrivalPlace;
extern QDate selectedDate;
extern QString g_userName ;
extern QString g_userPhone ;
extern int flisingleHeight;
extern QString seatType;
extern QString price;
extern QString airnumber;
extern QString timeh;
extern double pricedb;
extern QString managerairnumber;
extern QStackedWidget* homepagemain;
extern int widthq;
extern int heightq;
extern QStackedWidget* homemanagermain;
//extern QString sexValue;


/*  global.cpp
QString departPlace = "";  // 初始值为空字符串  出发地
QString arrivalPlace = ""; // 初始值为空字符串   到达地
QDate selectedDate = QDate::currentDate(); // 默认日期为当前日期
QString g_userName = "Mary";     //用户名
QString g_userPhone = "130130130";   //用户手机号
QString seatType="经济舱";   //选中舱位
QString price="0";     //机票价格
int flisingleHeight=150;    //flightsingle的单元格高度
QString airnumber="0";     //  航班号*/


#endif // GLOBAL_H
