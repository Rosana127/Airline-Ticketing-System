#ifndef SEATSSELECTPAGE_H
#define SEATSSELECTPAGE_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include "database.h"  // 数据库连接类

namespace Ui {
class SeatsSelectPage;
}

class SeatsSelectPage : public QWidget {
    Q_OBJECT

public:
    explicit SeatsSelectPage(Database *db, QWidget *parent = nullptr);
    ~SeatsSelectPage();
    bool seatSelectionMessageShown = false; // 新增标志变量

private:
    Ui::SeatsSelectPage *ui;
    Database *dbcon;  // 数据库连接

    void loadSeats(const QString &flightNumber, const QString &orderID);  // 加载座位信息
    void updateOrderSeat(const QString &orderID, const QString &seatNumber);
    void handleSeatSelection(const QString &flightNumber, const QString &seatNumber, QPushButton *button);
    void disableAllSeatsButtons();
    QStringList filterSeatsByTicketType(const QString &ticketType);

private slots:
    //void on_flightComboBox_currentIndexChanged(int index);  // 航班选择事件
    void on_loadSeatsButton_clicked();
};

#endif // SEATSSELECTPAGE_H
