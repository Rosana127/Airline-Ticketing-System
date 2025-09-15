#ifndef INQUIRE_H
#define INQUIRE_H

#include <QMainWindow>
#include<QFont>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QCalendarWidget>
#include"flisingle.h"
#include"flight_add2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class inquire; }
QT_END_NAMESPACE

class inquire : public QMainWindow
{
    Q_OBJECT

public:
    inquire(QWidget *parent = nullptr);
    ~inquire();
    void on_swapbutton_clicked();

private:
    Ui::inquire *ui;
private slots:
//    void swapLocations();
};
#endif // INQUIRE_H
