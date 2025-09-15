#ifndef INALL_H
#define INALL_H

#include <QWidget>

namespace Ui {
class Inall;
}

class Inall : public QWidget
{
    Q_OBJECT

public:
    explicit Inall(QWidget *parent = nullptr);
    ~Inall();

private:
    Ui::Inall *ui;
};

#endif // INALL_H
