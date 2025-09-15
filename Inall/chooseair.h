#ifndef CHOOSEAIR_H
#define CHOOSEAIR_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QMenu>
#include"flisingle.h"
namespace Ui {
class chooseAir;
}

class chooseAir : public QWidget
{
    Q_OBJECT

public:
    explicit chooseAir(QWidget *parent = nullptr);
    ~chooseAir();
    void myshow();
//    QList<flisingle*> searchFlightsFromDatabase(const QString &departPlace, const QString &arrivalPlace, const QDate &selectedDate) ;

private slots:
    void on_sousuo_clicked();
    void hideSelf(); // 用于隐藏页面的槽函数

private:
    Ui::chooseAir *ui;
};
QList<flisingle*> searchFlightsFromDatabase(const QString &departPlace, const QString &arrivalPlace, const QDate &selectedDate) ;
#endif // CHOOSEAIR_H
