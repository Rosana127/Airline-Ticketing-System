#ifndef BUYMENU_H
#define BUYMENU_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>
namespace Ui {
class buymenu;
}

class buymenu : public QWidget
{
    Q_OBJECT

public:
    explicit buymenu(const QString &aircompany,const QString &model,const QString number, const QString &departure, const QString &destination, const QString &departureTime, const QString &arriveTime,const QString price_,QWidget *parent = nullptr);
    ~buymenu();

private slots:
    void on_pushButton_2_clicked();

    void on_buy_clicked();

    void on_buy_bus_clicked();

    void on_buy_head_clicked();

private:
    Ui::buymenu *ui;
};

#endif // BUYMENU_H
