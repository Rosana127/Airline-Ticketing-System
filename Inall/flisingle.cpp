#include "flisingle.h"
#include "ui_flisingle.h"
#include"global.h"
flisingle::flisingle(const QString &aircompany ,const QString &model,const QString number,const QString &departure, const QString &destination, const QString &departureTime, const QString &arriveTime,const QString price_,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flisingle)
{
    ui->setupUi(this);
    ui->companyEdit->setText(aircompany);
    ui->numberEdit->setText(number);
    ui->modelEdit->setText(model);
    ui->departTime->setText(departureTime);
    ui->departAir->setText(departure);
    ui->arrivalAir->setText(destination);
    ui->arrivalTime->setText(arriveTime);
    ui->price->setText( QString("￥%1起").arg(price_));

}

flisingle::~flisingle()
{
    delete ui;
}

void flisingle::on_buy_clicked()
{

    buymenu* tmp=new buymenu(ui->companyEdit->text(),ui->modelEdit->text(),ui->numberEdit->text(),ui->departAir->text(),ui->arrivalAir->text(),ui->departTime->text(),ui->arrivalTime->text(),ui->price->text());
    tmp->resize(static_cast<int>(widthq), static_cast<int>(heightq));
    homepagemain->addWidget(tmp);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
    timeh=ui->departTime->text();
 emit hidePage();
}
