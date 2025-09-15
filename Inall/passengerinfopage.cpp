#include "passengerinfopage.h"
#include "ui_passengerinfopage.h"
#include <QMessageBox>
#include "paymentpage.h"  // 引入支付页面的头文件

#include"global.h"

PassengerInfoPage::PassengerInfoPage(const QString &flightNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PassengerInfoPage),
    flightNumber(flightNumber) // 初始化航班号
{
    ui->setupUi(this);

    // 连接提交按钮点击事件
    connect(ui->btnSubmit, &QPushButton::clicked, this, &PassengerInfoPage::onSubmitButtonClicked);


}



PassengerInfoPage::~PassengerInfoPage()
{
    delete ui;
}

void PassengerInfoPage::onSubmitButtonClicked()
{
    QString name = ui->lineEditName->text();
    QString idNumber = ui->lineEditIdNumber->text();
    QString phoneNumber = ui->lineEditPhoneNumber->text();

    if (name.isEmpty() || idNumber.isEmpty() || phoneNumber.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请完整填写乘客信息！");
        return;
    }


    PaymentPage *paymentPage = new PaymentPage(flightNumber, this); // 传递航班号
    paymentPage->setPassengerInfo(name, idNumber, phoneNumber); // 传递乘客信息
    homepagemain->addWidget(paymentPage);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
    //this->hide();
    ui->lineEditName->hide();
    ui->lineEditIdNumber->hide();
    ui->lineEditPhoneNumber->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->btnSubmit->hide();


}

