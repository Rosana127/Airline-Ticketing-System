#ifndef MANAGER1226_H
#define MANAGER1226_H

#include <QWidget>

namespace Ui {
class manager1226;
}

class manager1226 : public QWidget
{
    Q_OBJECT

public:
    explicit manager1226(QWidget *parent = nullptr);
    ~manager1226();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void on_forgetButton_clicked();
    void on_userLogin_clicked();

private:
    Ui::manager1226 *ui;
};

#endif // MANAGER1226_H
