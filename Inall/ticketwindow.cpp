#include "ticketwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSqlQuery>
#include <QDebug>
#include <QFont>

TicketWindow::TicketWindow(const QString& orderID, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    userNameLabel = new QLabel(this);
    flightNumberLabel = new QLabel(this);
    seatNumberLabel = new QLabel(this);
    departureGateLabel = new QLabel(this);
    departureCityLabel = new QLabel(this);
    departureAirportLabel = new QLabel(this);
    arrivalCityLabel = new QLabel(this);
    arrivalAirportLabel = new QLabel(this);
    boardingStatusLabel = new QLabel(this);

    layout->addWidget(userNameLabel);
    layout->addWidget(flightNumberLabel);
    layout->addWidget(seatNumberLabel);
    layout->addWidget(departureGateLabel);
    layout->addWidget(departureCityLabel);
    layout->addWidget(departureAirportLabel);
    layout->addWidget(arrivalCityLabel);
    layout->addWidget(arrivalAirportLabel);
    layout->addWidget(boardingStatusLabel);

    loadTicketDetails(orderID);  // 加载电子登机牌的详情
}

TicketWindow::~TicketWindow()
{
}

void TicketWindow::loadTicketDetails(const QString& orderID) {
    QSqlQuery query;
    query.prepare("SELECT o.UserName, o.FlightNumber, o.SeatNumber, o.DepartureGate, "
                  "f.DepartureCity, f.DepartureAirport, f.ArrivalCity, f.ArrivalAirport, "
                  "o.DepartureTime, o.IsDelayed "
                  "FROM orders o "
                  "JOIN flightinfo f ON o.FlightNumber = f.FlightNumber "
                  "WHERE o.OrderID = :orderID");
    query.bindValue(":orderID", orderID);
    query.exec();

    if (query.next()) {
        userNameLabel->setText("用户名: " + query.value("UserName").toString());
        flightNumberLabel->setText("航班号: " + query.value("FlightNumber").toString());
        seatNumberLabel->setText("座位号: " + query.value("SeatNumber").toString());
        departureGateLabel->setText("登机口: " + query.value("DepartureGate").toString());
        departureCityLabel->setText("出发城市: " + query.value("DepartureCity").toString());
        departureAirportLabel->setText("出发机场: " + query.value("DepartureAirport").toString());
        arrivalCityLabel->setText("到达城市: " + query.value("ArrivalCity").toString());
        arrivalAirportLabel->setText("到达机场: " + query.value("ArrivalAirport").toString());

        QDateTime departureTime = query.value("DepartureTime").toDateTime();  // 获取起飞时间
        bool isDelayed = query.value("IsDelayed").toBool();  // 获取航班是否延误

        // 根据航班延误情况更新登机状态
        if (isDelayed) {
            boardingStatusLabel->setText("飞机晚点，请及时查看收件箱获取新信息");
        } else {
            updateBoardingStatus(departureTime);  // 更新登机状态
        }
    } else {
        qDebug() << "No ticket details found for order ID: " << orderID;
    }
}

void TicketWindow::updateBoardingStatus(const QDateTime& departureTime) {
    QDateTime currentTime = QDateTime::currentDateTime();  // 获取当前时间
    qint64 timeDiff = currentTime.msecsTo(departureTime);  // 当前时间与起飞时间的时间差（毫秒）

    // 创建一个 QFont 对象，设置粗体和较大的字号
    QFont font = boardingStatusLabel->font();
    boardingStatusLabel->setFont(font);  // 设置到 QLabel 上

    if (timeDiff > 0) {
        // 起飞前
        if (timeDiff > 60 * 60 * 1000) {  // 起飞前一个小时
            boardingStatusLabel->setText("待登机");
        } else if (timeDiff > 30 * 60 * 1000) {  // 起飞前半小时到一小时
            boardingStatusLabel->setText("登机中");
        } else {  // 起飞前半个小时以内
            boardingStatusLabel->setText("已登机");
        }
    } else {
        boardingStatusLabel->setText("航班已起飞");
    }
}
