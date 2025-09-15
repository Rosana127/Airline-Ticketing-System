#include "flight_chaninfo.h"
#include "ui_flight_chaninfo.h"
#include"flight_add2.h"
#include"flight_delete.h"
#include"flight_change.h"
#include"managerticket.h"
#include"global.h"
flight_chaninfo::flight_chaninfo(QString flightNumber,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flight_chaninfo)
{
    ui->setupUi(this);
    on_search_clicked(flightNumber);


}

flight_chaninfo::~flight_chaninfo()
{
    delete ui;
}
void flight_chaninfo::on_search_clicked(QString flightNumber)
{

    // 连接到数据库
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

       while (query.next()) {
        // 填充 UI 控件
        ui->flightNumber->setText(flightNumber);
        managerairnumber=flightNumber;
        ui->airCompany->setText(query.value("AirlineCompany").toString());
        ui->aircraftModel->setText(query.value("AircraftModel").toString());
        ui->date->setText(query.value("Date").toString());
        // 处理出发时间
        ui->deparureTime->setText(query.value("DepartureTime").toString().mid(11,8));  // "2019-06-13 10:38:36"
        // 处理到达时间
        ui->arrivalTime->setText(query.value("ArrivalTime").toString().mid(11,8));  // "2019-06-13 10:38:36"

        ui->deparureCity->setText(query.value("DepartureCity").toString());
        ui->arrivalCity->setText(query.value("ArrivalCity").toString());
        ui->isDelayed->setText(query.value("IsDelayed").toString());
        ui->deparureAirport->setText(query.value("DepartureAirport").toString());
        ui->arrivalAirport->setText(query.value("ArrivalAirport").toString());

        // 根据 SeatType 填充价格和容量
        QString seatType = query.value("SeatType").toString();
        if (seatType == "经济舱") {
            ui->ecoPrice->setText(query.value("Price").toString());
            ui->ecoCapacity->setText(query.value("Capacity").toString());
        } else if (seatType == "头等舱") {
            ui->headPrice->setText(query.value("Price").toString());
            ui->headCapacity->setText(query.value("Capacity").toString());
        } else if (seatType == "商务舱") {
            ui->busPrice->setText(query.value("Price").toString());
            ui->busCapacity->setText(query.value("Capacity").toString());
        } }
}
//QString formatDateTime(const QString& date, const QString& departureTime)
//{
//    // 将日期和时间合并
//    QString dateTimeString = date + " " + departureTime;  // 合并日期和出发时间

//    // 使用 QDateTime 解析和格式化日期时间
//    QDateTime dateTime = QDateTime::fromString(dateTimeString, "yyyy-MM-dd HH:mm:ss");

//    // 检查是否解析成功
//    if (!dateTime.isValid()) {
//        qDebug() << "Invalid date and time format";
//        return QString();  // 返回空字符串表示解析失败
//    }

//    // 格式化为所需的目标格式
//    return dateTime.toString("yyyy-MM-dd HH:mm:ss");
//}
void flight_chaninfo::on_add_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认修改", "是否确认修改？",
                                    QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QString airnumber = ui->flightNumber->text();

        QSqlQuery query;
        if (!query.exec("USE flightdb")) {
            qDebug() << "Failed to select database: " << query.lastError().text();
            return;
        }
        // 获取各个输入框中的数据
        QString flightNumber = ui->flightNumber->text();
        QString airCompany = ui->airCompany->text();
        QString aircraftModel = ui->aircraftModel->text();
        QString date = ui->date->text();
        QString departureTime = ui->deparureTime->text();
        QString arrivalTime = ui->arrivalTime->text();
        QString departureCity = ui->deparureCity->text();
        QString arrivalCity = ui->arrivalCity->text();
        QString isDelayed = ui->isDelayed->text();
        QString departureAirport = ui->deparureAirport->text();
        QString arrivalAirport = ui->arrivalAirport->text();
        QString ecoPrice = ui->ecoPrice->text();
        QString busPrice = ui->busPrice->text();
        QString headPrice = ui->headPrice->text();
        QString ecoCapacity = ui->ecoCapacity->text();
        QString busCapacity = ui->busCapacity->text();
        QString headCapacity = ui->headCapacity->text();

        // Check if any required field is empty
        if (flightNumber.isEmpty() || airCompany.isEmpty() || aircraftModel.isEmpty() ||
            date.isEmpty() || departureTime.isEmpty() || arrivalTime.isEmpty() ||
            departureCity.isEmpty() || arrivalCity.isEmpty() || isDelayed.isEmpty() ||
            departureAirport.isEmpty() || arrivalAirport.isEmpty()) {
            QMessageBox::warning(this, "错误", "请输入完整航班信息");
            return;  // Stop execution if any field is empty
        }


        // 创建SQL查询语句
        QString formattedDeparture = date + " " + departureTime + ":00";
        QString formattedArrival = date + " " + arrivalTime + ":00";

        // 使用预处理语句构建SQL查询，避免SQL注入
        QString queryString = QString("UPDATE flightinfo SET "
                                       "AirlineCompany = :AirlineCompany, "
                                       "ArrivalCity = :ArrivalCity, "
                                       "DepartureCity = :DepartureCity, "
                                       "AircraftModel = :AircraftModel, "
                                       "DepartureAirport = :DepartureAirport, "
                                       "ArrivalAirport = :ArrivalAirport, "
                                       "IsDelayed = :IsDelayed, "
                                       "DepartureTime = :DepartureTime, "
                                       "ArrivalTime = :ArrivalTime, "
                                       "Date = :Date, "
                                       "SeatType = :SeatType, "
                                       "Price = :Price, "
                                       "Capacity = :Capacity "
                                       "WHERE FlightNumber = :FlightNumber AND SeatType = :SeatType");

        // 开始事务
        QSqlDatabase db = QSqlDatabase::database();
        if (db.isOpen()) {
            QSqlQuery query(db);
            query.exec("USE flightdb");
            query.prepare(queryString);

            query.bindValue(":AirlineCompany", airCompany);
            query.bindValue(":ArrivalCity", arrivalCity);
            query.bindValue(":DepartureCity", departureCity);
            query.bindValue(":AircraftModel", aircraftModel);
            query.bindValue(":DepartureAirport", departureAirport);
            query.bindValue(":ArrivalAirport", arrivalAirport);
            query.bindValue(":IsDelayed", isDelayed);
            query.bindValue(":DepartureTime", formattedDeparture);
            query.bindValue(":ArrivalTime", formattedArrival);
            query.bindValue(":Date", date);
            query.bindValue(":FlightNumber", flightNumber);


            query.bindValue(":SeatType", "经济舱");
            query.bindValue(":Price", ecoPrice);
            query.bindValue(":Capacity", ecoCapacity);

            if (!query.exec()) {
                qDebug() << "Failed to insert economy class: " << query.lastError().text();
                db.rollback();  // 如果插入失败，回滚事务
                return;
            }

            // 插入“商务舱”
            query.bindValue(":SeatType", "商务舱");
            query.bindValue(":Price", busPrice);
            query.bindValue(":Capacity", busCapacity);
            if (!query.exec()) {
                qDebug() << "Failed to insert business class: " << query.lastError().text();
                db.rollback();  // 如果插入失败，回滚事务
                return;
            }

            // 插入“头等舱”
            query.bindValue(":SeatType", "头等舱");
            query.bindValue(":Price", headPrice);
            query.bindValue(":Capacity", headCapacity);
            if (!query.exec()) {
                qDebug() << "Failed to insert first class: " << query.lastError().text();
                db.rollback();  // 如果插入失败，回滚事务
                return;
            }

            // 提交事务
            db.commit();

            QString sql = QString("UPDATE ordertable SET IsChanged = 1 WHERE FlightNumber_lmh = '%1'").arg(flightNumber);
            Update1();
            // 执行SQL查询
            if (query.exec(sql)) {
                // 更新成功
                qDebug() << "Rows updated successfully.";
            } else {
                // 查询失败
                qDebug() << "Error updating rows:" << query.lastError().text();
            }


            QMessageBox::information(this, "成功", "航班信息修改成功！");
        } else {
            QMessageBox::warning(this, "数据库错误", "数据库未打开");
        }

        } else {
            // 用户点击了返回，什么也不做
            return;
        }
}


void flight_chaninfo::on_btndelete_clicked()
{
    this->hide();
    flight_delete* tmp=new flight_delete();
    tmp->show();
}
void flight_chaninfo::on_btnadd_clicked()
{
    this->hide();
    flight_add2* tmp=new flight_add2();
    tmp->show();
}

void flight_chaninfo::on_pushButton_clicked()
{
    this->hide();
    flight_change* tmp=new flight_change();
    tmp->show();
}

void flight_chaninfo::on_isDelayed_textChanged(const QString &arg1)
{
    // 获取文本框中的FlightNumber值
    QString flightNumber = ui->flightNumber->text();

    // 检查文本框中的值是否为1
    if (flightNumber == "1") {
        // 创建一个SQL查询对象
        QSqlQuery query;

        // SQL语句：将IsDelayed列为1的所有行更新
        QString sql = QString("UPDATE ordertable SET IsDelayed = 1 WHERE FlightNumber = '%1'").arg(flightNumber);

        // 执行SQL查询
        if (query.exec(sql)) {
            // 更新成功
            qDebug() << "Rows updated successfully.";
        } else {
            // 查询失败
            qDebug() << "Error updating rows:" << query.lastError().text();
        }



        sql = QString("UPDATE flightinfo SET IsDelayed = 1 WHERE FlightNumber = '%1'").arg(flightNumber);

        // 执行SQL查询
        if (query.exec(sql)) {
            // 更新成功
            qDebug() << "Rows updated successfully.";
        } else {
            // 查询失败
            qDebug() << "Error updating rows:" << query.lastError().text();
        }
    }


}
void Update1(){
    QSqlQuery query;  // 使用数据库连接创建查询对象
    query.exec("USE flightdb");

//    query.prepare("SELECT IsDelayed FROM flightinfo WHERE FlightNumber = :flightNumber");
//    query.bindValue(":flightNumber", airnumber);
//    QString isDelayed;
//    if (query.exec()) {
//        // 如果查询成功，打印 IsDelayed 的值
//        if (query.next()) {
//            isDelayed = query.value(0).toString();  // 获取查询结果中的 IsDelayed 列
//            qDebug() << "IsDelayed:" << isDelayed;
//        } else {
//            qDebug() << "No matching flight found.";
//        }
//    } else {
//        qDebug() << "Query execution failed:" << query.lastError();
//    }
    query.prepare("SELECT DepartureCity, ArrivalCity, Date, DepartureTime, Price, IsDelayed "
                      "FROM flightinfo WHERE FlightNumber = :flightNumber");
        query.bindValue(":flightNumber", managerairnumber);

        if (query.exec()) {
            // 如果查询成功，获取查询结果
            if (query.next()) {
                QString departureCity = query.value(0).toString();
                QString arrivalCity = query.value(1).toString();
                QString date = query.value(2).toString();
                QString departureTime = query.value(3).toString().mid(11,8);
                double price = query.value(4).toDouble();
                QString isDelayed = query.value(5).toString();

                qDebug()<<departureCity<<arrivalCity<<date<<departureTime<<price<<isDelayed;
                // 更新 orderTable 中 FlightNumber_lmh = 'managerairnumber' 的对应行
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE orderTable SET DepartureCity = :departureCity, "
                                    "ArrivalCity = :arrivalCity, FlightDate = :date, "
                                    "FlightTime = :departureTime, Price = :price, "
                                    "IsDelayed = :isDelayed WHERE FlightNumber_lmh = :flightNumber_lmh");

                // 将查询结果绑定到更新语句
                updateQuery.bindValue(":departureCity", departureCity);
                updateQuery.bindValue(":arrivalCity", arrivalCity);
                updateQuery.bindValue(":date", date);
                updateQuery.bindValue(":departureTime", departureTime);
                updateQuery.bindValue(":price", price);
                updateQuery.bindValue(":isDelayed", isDelayed);
                updateQuery.bindValue(":flightNumber_lmh", managerairnumber);

                if (updateQuery.exec()) {
                    qDebug() << "Order table updated successfully.";
                } else {
                    qDebug() << "Failed to update order table:" << updateQuery.lastError();
                }
            } else {
                qDebug() << "No matching flight found in flightinfo.";
            }
        } else {
            qDebug() << "Failed to execute query:" << query.lastError();
        }
}
void flight_chaninfo::on_btnchange_2_clicked()
{
    this->hide();
    managerticket* tmp=new managerticket();
    tmp->show();
}
