#include "flight_change.h"
#include "ui_flight_change.h"
#include"flight_chaninfo.h"
#include"flight_add2.h"
#include"flight_delete.h"
#include"managerticket.h"
#include"global.h"
flight_change::flight_change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flight_change)
{
    ui->setupUi(this);
}

flight_change::~flight_change()
{
    delete ui;
}

void flight_change::on_pushButton_clicked()
{
    QString flightNumber=ui->lineEdit->text();
    QSqlQuery query;

    if (!query.exec("USE flightdb")) {
        qDebug() << "Failed to select database: " << query.lastError().text();
        return;
    }

    // 查询数据库，查找匹配的航班信息
    query.prepare("SELECT * FROM flightinfo WHERE FlightNumber = :flightNumber");
    query.bindValue(":flightNumber", flightNumber);

    if (!query.exec()) {
        qDebug() << "Failed to execute query: " << query.lastError().text();
        return;
    }
    if (query.next()) {
        this->hide();
        flight_chaninfo* tmp=new flight_chaninfo(ui->lineEdit->text());
//        tmp->show();
        homemanagermain->addWidget(tmp);
        homemanagermain->setCurrentIndex(homemanagermain->count() - 1);
    }else {
             QMessageBox::information(this, "失败", "不存在该航班号，请重新输入！");
    }
}

void flight_change::on_btnadd_clicked()
{
    this->hide();

}

void flight_change::on_btndelete_clicked()
{
    this->hide();
    flight_delete* tmp=new flight_delete();
    tmp->show();
}

void flight_change::on_btnchange_2_clicked()
{
    this->hide();
    managerticket* tmp=new managerticket();
    tmp->show();
}
