#include "inboxwindow2.h"
#include "ui_inboxwindow2.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>  // 引入 QDateTime
#include <QSqlError>  // 修正为正确的大小写
#include"global.h"
inboxWindow2::inboxWindow2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inboxWindow2)
{
    ui->setupUi(this);
    if (messageList == nullptr) {
        qDebug() << "messageList is not initialized!";
    }

    messageList =ui->listWidget;

    if (!messageList) {
        qDebug() << "Failed to create QListWidget!";
        return;
    }

//    messageList->setGeometry(10, 10, 400, 300);  // 设置消息列表的位置和大小

    loadMessages();  // 加载延误信息
}

inboxWindow2::~inboxWindow2()
{
    delete ui;
}
void inboxWindow2::loadMessages() {
    QSqlQuery query;

    // 使用 OR 来并列 IsDelayed 和 IsChanged 的条件
    query.prepare("SELECT o.UserName, o.FlightNumber_lmh, o.OrderId, o.IsChanged, o.IsDelayed "
                  "FROM ordertable o "
                  "WHERE (o.IsDelayed = 1 OR o.IsChanged = 1) AND o.UserName = :userName");
    query.bindValue(":userName", g_userName);  // 绑定全局变量 g_userName

    qDebug() << "SQL Query: " << query.lastQuery();

    if (!query.exec()) {
        qDebug() << "Failed to execute query: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString passengerName = query.value("PassengerName").toString();
        QString flightNumber = query.value("FlightNumber_lmh").toString();
        QString orderID = query.value("OrderId").toString();
        bool isChanged = query.value("IsChanged").toBool();  // 获取IsChanged字段
        bool isDelayed = query.value("IsDelayed").toBool();  // 获取IsDelayed字段

        // 根据IsChanged字段生成消息
        if (isChanged) {
            QString changeMessage = QString("尊敬的用户 %1：您好，由于航班变动，您的订单编号为%2的%3 航班信息更新。"
                                            "请查询该次航班获取最新消息！")
                                        .arg(passengerName)
                                        .arg(orderID)
                                        .arg(flightNumber);
            messageList->addItem(changeMessage);  // 添加航班信息变动的消息
        }

        // 根据IsDelayed字段生成消息
        if (isDelayed) {
            QString delayMessage = QString("尊敬的用户 %1：您好，由于天气原因，您的订单编号为%2的%3 航班延误起飞。"
                                           "请查询该次航班获取最新消息！")
                                       .arg(passengerName)
                                       .arg(orderID)
                                       .arg(flightNumber);
            messageList->addItem(delayMessage);  // 添加航班延误的消息
        }
    }
}
