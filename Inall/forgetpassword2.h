#ifndef FORGETPASSWORD2_H
#define FORGETPASSWORD2_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
namespace Ui {
class forgetPassword2;
}

class forgetPassword2 : public QWidget
{
    Q_OBJECT

public:
    explicit forgetPassword2(QWidget *parent = nullptr,bool isAdmin = false);
    ~forgetPassword2();
private slots:
    // 忘记密码按钮点击事件
    void on_forgetButton_clicked();
    void on_getCheckButton_clicked();

private:
    Ui::forgetPassword2 *ui;
    QString generatedCode;  // 用于存储生成的验证码
    bool isAdmin;

};

#endif // FORGETPASSWORD2_H
