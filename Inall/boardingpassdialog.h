#ifndef BOARDINGPASSDIALOG_H
#define BOARDINGPASSDIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QLabel>

#include "ui_boardingpassdialog.h"

namespace Ui {
class BoardingPassDialog;
}

class BoardingPassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BoardingPassDialog(const QString &userName, const QString &flightNumber, QWidget *parent = nullptr);
    ~BoardingPassDialog();

private:
    Ui::BoardingPassDialog *ui;
    void loadBoardingPassData(const QString &userName, const QString &flightNumber);

    // UI components to display the boarding pass information
    QLabel *labelUserName;
    QLabel *labelFlightNumber;
    QLabel *labelSeatNumber;
    QLabel *labelDepartureGate;
    QLabel *labelDepartureCity;
    QLabel *labelDepartureAirport;
    QLabel *labelArrivalCity;
    QLabel *labelArrivalAirport;
};

#endif // BOARDINGPASSDIALOG_H
