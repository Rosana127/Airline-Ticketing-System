#ifndef FLIGHT_DELETE_H
#define FLIGHT_DELETE_H

#include <QWidget>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
namespace Ui {
class flight_delete;
}

class flight_delete : public QWidget
{
    Q_OBJECT

public:
    explicit flight_delete(QWidget *parent = nullptr);
    ~flight_delete();

private slots:
    void on_pushButton_clicked();

    void on_btnadd_clicked();

    void on_btnchange_clicked();

    void on_btnchange_2_clicked();

private:
    Ui::flight_delete *ui;
};

#endif // FLIGHT_DELETE_H
