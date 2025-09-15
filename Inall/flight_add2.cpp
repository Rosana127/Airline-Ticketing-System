#include "flight_add2.h"
#include "ui_flight_add2.h"
#include"flight_delete.h"
#include"flight_change.h"
#include"managerticket.h"
flight_add2::flight_add2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flight_add2)
{
    ui->setupUi(this);
    QList<QLineEdit*> lineEdits = {ui->flightNumber, ui->airCompany,ui->aircraftModel,ui->date,ui->deparureTime,ui->arrivalTime,
                                  ui->deparureCity,ui->arrivalCity,ui->isDelayed,ui->deparureAirport,ui->arrivalAirport,ui->ecoPrice,
                                  ui->busPrice,ui->headPrice,ui->ecoCapacity,ui->busCapacity,ui->headCapacity};

        // 为每个 QLineEdit 控件安装事件过滤器
        for (QLineEdit* lineEdit : lineEdits) {
            lineEdit->setStyleSheet("font-family: 'SimSun';"
                                    "font-size: 22px;"
                                    "color: #101010;"
                                    "background-color: #FFFFFF;"
                                    "border-bottom: 2px solid #D5D5D5;");
            lineEdit->installEventFilter(this); // 安装事件过滤器
        }
}

flight_add2::~flight_add2()
{
    delete ui;
}
bool flight_add2::eventFilter(QObject *watched, QEvent *event)
{
    // 判断事件是双击事件，并且是 QLineEdit 控件
    if (event->type() == QEvent::MouseButtonDblClick) {
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(watched);  // 将事件源转换为 QLineEdit
        if (lineEdit) {
            lineEdit->clear();  // 双击后清空文本
            lineEdit->setStyleSheet("font-family: 'SimSun';"
                                    "font-size: 22px;"
                                    "color: #101010;"
                                    "background-color: #FFFFFF;"
                                    "border-bottom: 2px solid #7E7F7F;");
            lineEdit->setReadOnly(false);  // 双击后让 QLineEdit 变为可编辑
            return true;  // 事件已处理
        }
    }

    // 交给基类处理其他事件
    return QWidget::eventFilter(watched, event);
}
void flight_add2::insertFlightDataToDatabase()
{
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

    // SQL 插入语句的模板
     QString queryString = QString("INSERT INTO flightinfo (FlightNumber, AirlineCompany, ArrivalCity, DepartureCity, AircraftModel, DepartureAirport, ArrivalAirport, IsDelayed, DepartureTime, ArrivalTime,Date,booktickets,SeatType, Price, Capacity) "
                                   "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', 0,:SeatType, :Price, :Capacity)")
                            .arg(flightNumber)
                            .arg(airCompany)
                            .arg(arrivalCity)
                            .arg(departureCity)
                            .arg(aircraftModel)
                            .arg(departureAirport)
                            .arg(arrivalAirport)
                            .arg(isDelayed)
                            .arg(formattedDeparture)
                            .arg(formattedArrival)
                            .arg(date);
    // SQL 插入语句
    // 连接数据库
    QSqlQuery query;
    if (!query.exec("USE flightdb")) {
        qDebug() << "Failed to select database: " << query.lastError().text();
    } else {
        qDebug() << "Database selected successfully";
    }

      // 开始事务
//       db.transaction();

       // 插入“经济舱”
       query.prepare(queryString);
       query.bindValue(":SeatType", "经济舱");
       query.bindValue(":Price", ecoPrice);  // 明确指定为 QVariant(int)
       query.bindValue(":Capacity", ecoCapacity);
       if (!query.exec()) {
           qDebug() << "Failed to insert economy class: " << query.lastError().text();
//           db.rollback();  // 如果插入失败，回滚事务
           return;
       }
       // 插入“头等舱”
       query.prepare(queryString);
       query.bindValue(":SeatType", "头等舱");
       query.bindValue(":Price", headPrice);
       query.bindValue(":Capacity", headCapacity);
       if (!query.exec()) {
           qDebug() << "Failed to insert first class: " << query.lastError().text();
//           db.rollback();  // 如果插入失败，回滚事务
           return;
       }

       // 插入“商务舱”
       query.prepare(queryString);
       query.bindValue(":SeatType", "商务舱");
       query.bindValue(":Price", busPrice);
       query.bindValue(":Capacity", busCapacity);
       if (!query.exec()) {
           qDebug() << "Failed to insert business class: " << query.lastError().text();
//           db.rollback();  // 如果插入失败，回滚事务
           return;
       }
       // 提交事务
//       db.commit();

       // 提示成功
       QMessageBox::information(this, "成功", "航班信息已成功添加！");
}


void flight_add2::on_add_clicked()
{
    insertFlightDataToDatabase();
}
//QString flight_add2::formatDateTime(const QString& date, const QString& departureTime)
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
void flight_add2::on_btndelete_clicked()
{
    this->hide();
    flight_delete* tmp=new flight_delete();
    tmp->show();
}

void flight_add2::on_btnchange_clicked()
{
    this->hide();
    flight_change*tmp=new flight_change();
    tmp->show();
}

void flight_add2::on_btnchange_2_clicked()
{
    this->hide();
    managerticket* tmp=new managerticket();
    tmp->show();
}
