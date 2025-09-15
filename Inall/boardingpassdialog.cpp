#include "boardingpassdialog.h"
#include "ui_boardingpassdialog.h"
#include <QSqlQuery>
#include <QDebug>

BoardingPassDialog::BoardingPassDialog(const QString &userName, const QString &flightNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoardingPassDialog)
{
    ui->setupUi(this);

    // 调用函数加载电子登机牌的数据
    loadBoardingPassData(userName, flightNumber);
}

BoardingPassDialog::~BoardingPassDialog()
{
    delete ui;
}

void BoardingPassDialog::loadBoardingPassData(const QString &userName, const QString &flightNumber)
{
    // 数据库查询
    QSqlQuery query;
    query.prepare("SELECT o.SeatNumber, o.DepartureGate, f.DepartureCity, f.DepartureAirport, "
                  "f.ArrivalCity, f.ArrivalAirport "
                  "FROM orders o "
                  "JOIN flightinfo f ON o.FlightNumber = f.FlightNumber "
                  "WHERE o.UserName = :userName AND o.FlightNumber = :flightNumber");

    query.bindValue(":userName", userName);
    query.bindValue(":flightNumber", flightNumber);

    if (query.exec() && query.next()) {
        // 获取数据并设置到 UI 标签中
        ui->label_UserName->setText(userName);
        ui->label_FlightNumber->setText(flightNumber);
        ui->label_SeatNumber->setText(query.value("SeatNumber").toString());
        ui->label_DepartureGate->setText(query.value("DepartureGate").toString());
        ui->label_DepartureCity->setText(query.value("DepartureCity").toString());
        ui->label_DepartureAirport->setText(query.value("DepartureAirport").toString());
        ui->label_ArrivalCity->setText(query.value("ArrivalCity").toString());
        ui->label_ArrivalAirport->setText(query.value("ArrivalAirport").toString());
    } else {
        qDebug() << "Error loading boarding pass data:" << query.lastError();
    }
}
