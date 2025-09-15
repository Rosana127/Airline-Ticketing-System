#include "flight_delete.h"
#include "ui_flight_delete.h"
#include"flight_add2.h"
#include"flight_change.h"
#include"managerticket.h"
flight_delete::flight_delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flight_delete)
{
    ui->setupUi(this);


}

flight_delete::~flight_delete()
{
    delete ui;
}

void flight_delete::on_pushButton_clicked()
{
    QString airnumber=ui->lineEdit->text();
    // 连接数据库
    QSqlQuery query;
    if (!query.exec("USE flightdb")) {
        qDebug() << "Failed to select database: " << query.lastError().text();
    } else {
        qDebug() << "Database selected successfully";
    }
    // 查询表中是否存在相同的航班号
    query.prepare("SELECT COUNT(*) FROM flightinfo WHERE FlightNumber = :airnumber");
    query.bindValue(":airnumber", airnumber);

    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count > 0) {
        // 如果找到了航班号，执行删除操作
        query.prepare("DELETE FROM flightinfo WHERE FlightNumber = :airnumber");
        query.bindValue(":airnumber", airnumber);

        if (query.exec()) {
            // 删除成功，弹出提示框
            QMessageBox::information(this, "删除成功", "成功删除航班号为 " + airnumber + " 的记录！");
        } else {
            // 删除失败，弹出错误提示框
            QMessageBox::warning(this, "删除失败", "删除失败，请重试！");
        }
    } else {
        // 如果没有找到航班号，弹出提示框
        QMessageBox::information(this, "未查询到航班", "未找到航班号为 " + airnumber + " 的记录！");
    }
}
void flight_delete::on_btnadd_clicked()
{
    this->hide();
    flight_add2* tmp=new flight_add2();
    tmp->show();
}

void flight_delete::on_btnchange_clicked()
{
    this->hide();
     flight_change*tmp=new flight_change();
     tmp->show();

}

void flight_delete::on_btnchange_2_clicked()
{
    this->hide();
    managerticket* tmp=new managerticket();
    tmp->show();
}
