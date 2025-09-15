#ifndef FLIGHT_ADD2_H
#define FLIGHT_ADD2_H

#include<QMainWindow>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QDateTime>
#include<QWidget>


namespace Ui {
class flight_add2;
}

class flight_add2 : public QWidget
{
    Q_OBJECT

public:
    explicit flight_add2(QWidget *parent = nullptr);
    ~flight_add2();
    bool eventFilter(QObject *watched, QEvent *event);
//    QString formatDateTime(const QString& date, const QString& Time);
    void insertFlightDataToDatabase();

private slots:
    void on_add_clicked();

    void on_btndelete_clicked();

    void on_btnchange_clicked();

    void on_btnchange_2_clicked();

private:
    Ui::flight_add2 *ui;
};

#endif // FLIGHT_ADD2_H
