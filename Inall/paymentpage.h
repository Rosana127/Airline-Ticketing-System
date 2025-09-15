#ifndef PAYMENTPAGE_H
#define PAYMENTPAGE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include "database.h"

namespace Ui {
class PaymentPage;
}

class PaymentPage : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentPage(const QString &flightNumber, QWidget *parent = nullptr);
    ~PaymentPage();

    void setPassengerInfo(const QString &name, const QString &id, const QString &phone);
private slots:
    void onWeChatButtonClicked();
    void onAlipayButtonClicked();
    void onBandCardButtonClicked();


private:
    void processPayment(); // 模拟支付处理
    void saveOrderToDatabase(); // 保存订单到数据库

    Ui::PaymentPage *ui;
    QString passengerName;
    QString idNumber;
    QString phoneNumber;
    QString flightNumber;


};

#endif // PAYMENTPAGE_H
