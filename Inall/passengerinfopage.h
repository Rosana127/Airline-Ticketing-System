// passengerinfopage.h
#ifndef PASSENGERINFOPAGE_H
#define PASSENGERINFOPAGE_H

#include <QWidget>

namespace Ui {
class PassengerInfoPage;
}

class PassengerInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit PassengerInfoPage(const QString &flightNumber, QWidget *parent = nullptr); // 接收航班号
    ~PassengerInfoPage();


private slots:
    void onSubmitButtonClicked();  // 提交按钮点击的槽函数



private:
    Ui::PassengerInfoPage *ui;
    QString flightNumber; // 存储航班号
};

#endif // PASSENGERINFOPAGE_H
