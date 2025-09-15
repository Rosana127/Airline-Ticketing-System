#ifndef FLIGHT_CHANGE_H
#define FLIGHT_CHANGE_H

#include <QWidget>

namespace Ui {
class flight_change;
}

class flight_change : public QWidget
{
    Q_OBJECT

public:
    explicit flight_change(QWidget *parent = nullptr);
    ~flight_change();

private slots:
    void on_pushButton_clicked();

    void on_btnadd_clicked();

    void on_btndelete_clicked();

    void on_btnchange_2_clicked();

private:
    Ui::flight_change *ui;
};

#endif // FLIGHT_CHANGE_H
