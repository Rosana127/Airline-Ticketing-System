#ifndef FLISINGLE_H
#define FLISINGLE_H

#include <QDialog>
#include<QLineEdit>
#include<QWidget>
#include"buymenu.h"
#include<QVBoxLayout>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>
#include<iostream>
#include<QScrollArea>
namespace Ui {
class flisingle;
}

class flisingle : public QWidget
{
    Q_OBJECT

public:
    explicit flisingle(const QString &aircompany,const QString &model,const QString number, const QString &departure, const QString &destination, const QString &departureTime, const QString &arriveTime,const QString price_,QWidget *parent = nullptr);
    ~flisingle();
    buymenu* buyMenueco ;
    buymenu* buyMenufir ;
    buymenu* buyMenuhead;
    bool buyMenuVisible;

    void toggleBuyMenu(const QString &number);
signals:
    void hidePage(); // 新信号：用于通知外部页面隐藏

private slots:
    void on_buy_clicked();


private:
    Ui::flisingle *ui;
};

#endif // FLISINGLE_H
