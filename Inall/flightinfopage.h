#ifndef FLIGHTINFOPAGE_H
#define FLIGHTINFOPAGE_H

#include <QWidget> // 确保包含 QWidget
#include <QString>

namespace Ui {
class FlightInfoPage;
}

class FlightInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit FlightInfoPage( QWidget *parent = nullptr); // 接收航班号
    ~FlightInfoPage();
    QString getFlightNumber() const; // 提供航班号接口



private slots:
    void onAgreeButtonClicked();

private:
    Ui::FlightInfoPage *ui;
    QString flightNumber;
};

#endif // FLIGHTINFOPAGE_H
