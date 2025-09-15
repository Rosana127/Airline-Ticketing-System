#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QLineEdit>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class forgetPassword;
}

class forgetPassword : public QDialog
{
    Q_OBJECT

public:

    explicit forgetPassword(QWidget *parent = nullptr, bool isAdmin = false);
    ~forgetPassword();

// protected:
//     void closeEvent(QCloseEvent *event) override;  // 重载 closeEvent

private slots:
    // 忘记密码按钮点击事件
    void on_forgetButton_clicked();
    void on_getCheckButton_clicked();

private:
    Ui::forgetPassword *ui;
    QString generatedCode;  // 用于存储生成的验证码
    bool isAdmin;
};

#endif // FORGETPASSWORD_H
