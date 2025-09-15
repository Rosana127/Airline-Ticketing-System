#ifndef FLIGHT_CHANINFO_H
#define FLIGHT_CHANINFO_H

#include <QWidget>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QDateTime>
namespace Ui {
class flight_chaninfo;
}

class flight_chaninfo : public QWidget
{
    Q_OBJECT

public:
    explicit flight_chaninfo(QString flightNumber,QWidget *parent = nullptr);
    ~flight_chaninfo();
    void on_search_clicked(QString flightNumber);

private slots:
    void on_add_clicked();

    void on_btndelete_clicked();

    void on_btnadd_clicked();

    void on_pushButton_clicked();

    void on_isDelayed_textChanged(const QString &arg1);

    void on_btnchange_2_clicked();

private:
    Ui::flight_chaninfo *ui;
};
void Update1();
#endif // FLIGHT_CHANINFO_H
