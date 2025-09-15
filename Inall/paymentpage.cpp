#include "paymentpage.h"
#include "ui_paymentpage.h"
#include "database.h"  // 引入数据库类头文件
#include <QSqlError>  // 引入 QSqlError 类
#include <QSqlDatabase>  // 引入 QSqlDatabase 类
#include <QSqlQuery>  // 如果你正在执行数据库查询，也需要引入 QSqlQuery
#include"homepage.h"
#include"global.h"
#include"inquire.h"
PaymentPage::PaymentPage(const QString &flightNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentPage),
    flightNumber(flightNumber)
{
    ui->setupUi(this);

    // 连接按钮点击事件
    connect(ui->btnWeChat, &QPushButton::clicked, this, &PaymentPage::onWeChatButtonClicked);
    connect(ui->btnAlipay, &QPushButton::clicked, this, &PaymentPage::onAlipayButtonClicked);
    connect(ui->btnBankCard, &QPushButton::clicked, this, &PaymentPage::onBandCardButtonClicked);
}

PaymentPage::~PaymentPage()
{
    delete ui;
}

void PaymentPage::setPassengerInfo(const QString &name, const QString &id, const QString &phone) {
    passengerName = name;
    idNumber = id;
    phoneNumber = phone;
}

void PaymentPage::onWeChatButtonClicked() {
    QMessageBox::information(this, "支付", "通过微信支付中...");
    processPayment();
}

void PaymentPage::onAlipayButtonClicked() {
    QMessageBox::information(this, "支付", "通过支付宝支付中...");
    processPayment();
}

void PaymentPage::onBandCardButtonClicked() {
    QMessageBox::information(this, "支付", "通过银行卡支付中...");
    processPayment();
}

void PaymentPage::processPayment() {
    QMessageBox::information(this, "支付成功", "支付已成功完成！");
    saveOrderToDatabase();

    // 隐藏支付按钮
    ui->btnWeChat->hide();
    ui->btnAlipay->hide();
    ui->btnBankCard->hide();
}

void PaymentPage::saveOrderToDatabase() {
    // 确保数据库连接已经打开
    // if (!Database::getInstance().connectToDatabase()) {
    //     QMessageBox::critical(this, "错误", "数据库连接失败，请重试！");
    //     return;
    // }
    QSqlQuery query;  // 使用数据库连接创建查询对象
    //query.exec("USE flightdb");

    query.prepare("SELECT IsDelayed FROM flightinfo WHERE FlightNumber = :flightNumber");
    query.bindValue(":flightNumber", airnumber);
    QString isDelayed;
    if (query.exec()) {
        // 如果查询成功，打印 IsDelayed 的值
        if (query.next()) {
            isDelayed = query.value(0).toString();  // 获取查询结果中的 IsDelayed 列
            qDebug() << "IsDelayed:" << isDelayed;
        } else {
            qDebug() << "No matching flight found.";
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError();
    }
    query.prepare("INSERT INTO ordertable (PassengerName, UserName,  IdNumber, PhoneNumber, FlightNumber_lmh, OrderTime, DepartureCity, ArrivalCity, FlightDate, FlightTime, TicketType, Price,IsChanged,IsDelayed) "
                  "VALUES (:passengerName, :username,  :idNumber, :phoneNumber, :flightNumber, :orderTime, :departureCity, :arrivalCity, :flightDate, :flightTime, :ticketType, :price,:ischanged,:isdelayed)");

    query.bindValue(":passengerName", passengerName);
    query.bindValue(":username", g_userName);
    query.bindValue(":idNumber", idNumber);
    query.bindValue(":phoneNumber", phoneNumber);
    query.bindValue(":flightNumber", flightNumber);
    query.bindValue(":orderTime", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":departureCity", departPlace); // 出发地
    query.bindValue(":arrivalCity", arrivalPlace);  // 到达地
    query.bindValue(":flightDate", selectedDate.toString("yyyy-MM-dd"));  // 航班日期
    query.bindValue(":flightTime", timeh);           // 默认时间
    query.bindValue(":ticketType", seatType);       // 舱位类型（例如：经济舱）
    query.bindValue(":price", price.toDouble());               // 机票价格
    query.bindValue(":ischanged", 0);               // 机票价格
    query.bindValue(":isdelayed", isDelayed);

    qDebug()<<timeh<<price.toDouble();
    if (!query.exec()) {
        qDebug() << "订单保存失败:" << query.lastError().text();
        QMessageBox::critical(this, "错误", "订单保存失败，请重试！");
        return;
    }

    QString queryString = QString("UPDATE flightinfo "
                                  "SET booktickets = booktickets + 1 "
                                  "WHERE FlightNumber = '%1' AND SeatType = '%2'")
                                  .arg(airnumber)
                                  .arg(seatType);

    query.exec(queryString);

    QMessageBox::information(this, "成功", "交易成功，订单已保存");
    this->hide();
    qDebug() << "订单已成功保存："
             << "姓名：" << passengerName
             << "身份证：" << idNumber
             << "手机号：" << phoneNumber
             << "航班号：" << flightNumber;
    inquire* tmp=new inquire();
    homepagemain->addWidget(tmp);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
}


