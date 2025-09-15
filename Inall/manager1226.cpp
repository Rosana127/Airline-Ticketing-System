#include "manager1226.h"
#include "ui_manager1226.h"
#include "manager1226.h"
#include "forgetpassword2.h"
#include "database.h"
#include <QApplication>
#include <QMainWindow>
#include"flight_add2.h"
#include"homemanager.h"
#include "login.h"
#include"registerdialog2.h"
manager1226::manager1226(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager1226)
{
    ui->setupUi(this);
}

manager1226::~manager1226()
{
    delete ui;
}



void manager1226::on_registerButton_clicked()
{
    // 管理员界面注册时
    RegisterDialog2* registerDialog=new RegisterDialog2(nullptr,true); // true 表示管理员注册
    registerDialog->show();
//    registerDialog.close();  // 关闭当前的 RegisterDialog 窗口
//    this->show();  // 继续显示 manager1226 窗口
}

void manager1226::on_forgetButton_clicked()
{
    forgetPassword2* forgetPassword=new forgetPassword2(nullptr, true);
    forgetPassword->show(); // 显示模态对话框
//    forgetPassword.close();  // 关闭当前的 RegisterDialog 窗口
//    this->show();  // 继续显示 manager1226 窗口
}

void manager1226::on_userLogin_clicked(){
    // 创建managerLogin窗口
    Login *mainwindow = new Login();  // 设置父窗口为this，即MainWindow
    // 显示managerLogin窗口
    mainwindow->show();

    // 隐藏当前主窗口（如果需要）
    this->hide();

}

void manager1226::on_loginButton_clicked()
{
    QString account = ui->txt_user->text();
    QString password = ui->txt_password->text();

    if (account.isEmpty() && password.isEmpty()) {
        QMessageBox::warning(this, "警告", "账号和密码不能为空！");  // 使用 this 作为父窗口
        return;
    }
    else if (account.isEmpty()) {
        QMessageBox::warning(this, "警告", "账号不能为空！");  // 使用 this 作为父窗口
        return;
    }
    else if (password.isEmpty()) {
        QMessageBox::warning(this, "警告", "密码不能为空！");  // 使用 this 作为父窗口
        return;
    }

    // // 检查账号是否存在
    // QSqlQuery query;
    // query.prepare("SELECT Password FROM UserInfo WHERE UserName = :account");
    // query.bindValue(":account", account);


    // 连接到数据库
    QSqlQuery query;
    query.exec("USE flightdb");
    query.prepare("SELECT Password FROM ManagerInfo WHERE ManagerName = :account");
    query.bindValue(":account", account);



    if (query.exec()) {
        if (query.next()) {
            // 账号存在，检查密码是否匹配
            QString correctPassword = query.value(0).toString();
            if (password == correctPassword) {
                QMessageBox::information(this, "成功", "登录成功！");
                this->hide();
                homemanager* tmp=new homemanager();
                tmp->show();
            } else {
                QMessageBox::warning(this, "警告", "密码错误！");
            }
        } else {
            // 账号不存在
            QMessageBox::warning(this, "警告", "该账号不存在！");
        }
    } else {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
        // 确保 manager1226 窗口继续显示
        this->show();  // 继续显示 manager1226 窗口
    }

    //    // 确保 manager1226 窗口继续显示
    //    this->show();  // 继续显示 manager1226 窗口
}


