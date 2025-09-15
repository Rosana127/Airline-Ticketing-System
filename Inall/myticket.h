#ifndef MYTICKET_H
#define MYTICKET_H

#include <QWidget>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidgetItem>
#include"ui_myticket.h"
#include "homepage.h"
//extern QString g_userName;
//extern QString g_userPhone;


namespace Ui {
class myTicket;
}

class myTicket : public QWidget
{
    Q_OBJECT

public:
    explicit myTicket(QWidget *parent = nullptr);
    ~myTicket();

private:
    Ui::myTicket *ui;
    QTableWidget *tableWidget;  // 修改为tableWidget

    bool connectDatabase();
    void loadData();
    void handleChange(int row);
    void handleCancel(int row);
    void checkBoardingGate(int row);
    void confirmChange(int row);
    double getPriceForOrder(const QString& orderID);
    QString getMaxOrderID(const QString& userName);

    HomePage* homePage;  // 添加一个指向 HomePage 的指针


};

#endif // MYTICKET_H
