#ifndef TICKETWINDOW_H
#define TICKETWINDOW_H

#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QLabel>
#include <QDateTime>

class TicketWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TicketWindow(const QString& orderID, QWidget *parent = nullptr);
    ~TicketWindow();

private:
    QLabel *userNameLabel;
    QLabel *flightNumberLabel;
    QLabel *seatNumberLabel;
    QLabel *departureGateLabel;
    QLabel *departureCityLabel;
    QLabel *departureAirportLabel;
    QLabel *arrivalCityLabel;
    QLabel *arrivalAirportLabel;
    QLabel *boardingStatusLabel;  // 用于显示登机状态

    void loadTicketDetails(const QString& orderID);  // 加载电子登机牌信息
    void updateBoardingStatus(const QDateTime& departureTime);  // 更新登机状态
};

#endif // TICKETWINDOW_H
