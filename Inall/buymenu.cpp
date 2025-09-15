#include "buymenu.h"
#include "ui_buymenu.h"
#include"flightinfopage.h"
#include"global.h"
#include"chooseair.h"
buymenu::buymenu(const QString &aircompany ,const QString &model,const QString number,const QString &departure, const QString &destination, const QString &departureTime, const QString &arriveTime,const QString price_,QWidget *parent):
    QWidget(parent),
    ui(new Ui::buymenu)
{
    ui->setupUi(this);
    ui->companyEdit->setText(aircompany);
    ui->numberEdit->setText(number);
    ui->modelEdit->setText(model);
    ui->departTime->setText(departureTime);
    ui->departAir->setText(departure);
    ui->arrivalAir->setText(destination);
    ui->arrivalTime->setText(arriveTime);

    // 连接数据库
      QSqlQuery query;
      if (!query.exec("USE flightdb")) {
          qDebug() << "Failed to select database: " << query.lastError().text();
          return;
      } else {
          qDebug() << "Database selected successfully";
      }

      // 查询所有座位类型的菜单
      QStringList seatTypes = {"经济舱", "商务舱", "头等舱"};
      foreach (const QString &seatType, seatTypes) {
          qDebug()<<seatType<<number;
          query.prepare("SELECT SeatType, Capacity, booktickets, Price FROM flightinfo WHERE FlightNumber = ? AND SeatType = ?");
          query.addBindValue(number);
          query.addBindValue(seatType);

          if (query.exec() && query.next()) {
              QString seatType = query.value("SeatType").toString();
              int capacity = query.value("Capacity").toInt();
              int bookedTickets = query.value("booktickets").toInt();
              int leftTic=capacity-bookedTickets;
              QString price = query.value("Price").toString();


              qDebug()<<price;

              // 根据座位类型创建菜单
              if (seatType == "经济舱") {
                      ui->model->setText("经济舱");
                      ui->price->setText( QString("￥%1").arg(price));
                      ui->leftTicket->setText( QString("余票：%1张").arg(leftTic));
              } else if (seatType == "商务舱") {
                  ui->model_bus->setText("商务舱");
                  ui->price_bus->setText( QString("￥%1").arg(price));
                  ui->leftTicket_bus->setText( QString("余票：%1张").arg(leftTic));
              } else if (seatType == "头等舱" ) {
                  ui->model_head->setText("头等舱");
                  ui->price_head->setText( QString("￥%1").arg(price));
                  ui->leftTicket_head->setText( QString("余票：%1张").arg(leftTic));
              }
          }else {
              qDebug() << "Query failed: " << query.lastError().text();
          }
}
}
buymenu::~buymenu()
{
    delete ui;
}

void buymenu::on_pushButton_2_clicked()
{
    this->hide();
    chooseAir *chooseAirWindow = new chooseAir();
    chooseAirWindow->resize(static_cast<int>(widthq), static_cast<int>(heightq));
    homepagemain->addWidget(chooseAirWindow);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);

}

void buymenu::on_buy_clicked()
{
    this->hide();
    seatType="经济舱";
    price=ui->price->text().mid(1,-1);
    airnumber=ui->numberEdit->text();
    FlightInfoPage* tmp=new FlightInfoPage();
        tmp->resize(static_cast<int>(widthq), static_cast<int>(heightq));
    homepagemain->addWidget(tmp);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
}

void buymenu::on_buy_bus_clicked()
{
    this->hide();
    seatType="商务舱";
    price=ui->price_bus->text().mid(1,-1);
    airnumber=ui->numberEdit->text();
    FlightInfoPage* tmp=new FlightInfoPage();
        tmp->resize(static_cast<int>(widthq), static_cast<int>(heightq));
    homepagemain->addWidget(tmp);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
}

void buymenu::on_buy_head_clicked()
{
    this->hide();
    seatType="头等舱";
    price=ui->price_head->text().mid(1,-1);
    airnumber=ui->numberEdit->text();
    FlightInfoPage* tmp=new FlightInfoPage();
        tmp->resize(static_cast<int>(widthq), static_cast<int>(heightq));
    homepagemain->addWidget(tmp);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
}
