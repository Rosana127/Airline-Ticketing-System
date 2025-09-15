#include "flightinfopage.h"
#include "ui_flightinfopage.h"
#include "passengerinfopage.h" // 包含乘客信息页面头文件
#include"global.h"
FlightInfoPage::FlightInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlightInfoPage)
{
    ui->setupUi(this);
    ui->Type->setText(QString("%1 - %2 - %3 %4").arg(airnumber).arg(departPlace).arg(arrivalPlace).arg(seatType));
    if(seatType=="经济舱"){
        ui->luggage1t->setText("20KG/人，不限件数\n 单件体积不超过100*60*40CM");
        ui->luggagehand->setText("每人限1件,每件8公斤\n 单件体积不超过55*40*20CM");
    }
    // 根据航班类型显示产品信息
    else if (seatType=="商务舱") {
        ui->luggage1t->setText("30KG/人，不限件数\n 单件体积不超过100*60*40CM");
        ui->luggagehand->setText("每人限1件,每件8公斤\n 单件体积不超过55*40*20CM");
    } else{
        ui->luggage1t->setText("40KG/人，不限件数\n 单件体积不超过100*60*40CM");
        ui->luggagehand->setText("不限件数,每件8公斤\n 单件体积不超过55*40*20CM");
}


        ui->price->setText( QString("￥%1").arg(price));
    // 连接“同意”按钮点击事件
    connect(ui->btnAgree, &QPushButton::clicked, this, &FlightInfoPage::onAgreeButtonClicked);
}

void FlightInfoPage::onAgreeButtonClicked()
{
    // 创建乘客信息页面
    PassengerInfoPage *passengerInfoPage = new PassengerInfoPage(airnumber);

    // 显示乘客信息页面
    homepagemain->addWidget(passengerInfoPage);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);

    // 隐藏当前页面
    this->hide();
}

FlightInfoPage::~FlightInfoPage()
{
    delete ui;
}

QString FlightInfoPage::getFlightNumber() const
{
    return flightNumber; // 返回航班号
}

