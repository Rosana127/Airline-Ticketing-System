#ifndef SIDE_H
#define SIDE_H

#include <QWidget>
#include<QButtonGroup>

namespace Ui {
class side;
}

class side : public QWidget
{
    Q_OBJECT

public:
    explicit side(QWidget *parent = nullptr);
    ~side();

private:
    Ui::side *ui;
};

#endif // SIDE_H
