#include "forgetPassword.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>
#include <QRandomGenerator>
#include "ui_forgetPassword.h"


forgetPassword::forgetPassword(QWidget *parent, bool isAdmin)
    : QDialog(parent), isAdmin(isAdmin), ui(new Ui::forgetPassword)  // 初始化 isAdmin 成员变量
{
    ui->setupUi(this);
    generatedCode = "";
}

// 析构函数
forgetPassword::~forgetPassword()
{
    delete ui;
}


void forgetPassword::on_getCheckButton_clicked()
{
    // 获取用户输入的用户名和手机号
    QString username = ui->userNameLineEdit->text();
    QString phone = ui->phoneNumberLineEdit->text();

    // 检查用户名和手机号是否为空
    if (username.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名和手机号不能为空！");
        return;
    }

    // 获取数据库连接
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库：" + db.lastError().text());
        return;
    }
    QSqlQuery query;
    if(!isAdmin){
        // 用户

        query.prepare("SELECT COUNT(*) FROM userinfo WHERE UserName = :username AND PhoneNumber = :phone");
        query.bindValue(":username", username);
        query.bindValue(":phone", phone);
    }
    else{
        query.prepare("SELECT COUNT(*) FROM managerinfo WHERE ManagerName = :username AND PhoneNumber = :phone");
        query.bindValue(":username", username);
        query.bindValue(":phone", phone);
    }



    if (!query.exec()) {
        QMessageBox::critical(this, "查询错误", "无法查询数据库：" + query.lastError().text());
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count == 0) {
        // 用户名和手机号不匹配
        QMessageBox::warning(this, "验证失败", "用户名和手机号不匹配！");
    } else {
        // 验证成功，生成随机验证码
        generatedCode = QString::number(QRandomGenerator::global()->bounded(1000, 9999));
        QMessageBox::information(this, "验证码", "您的验证码是：" + generatedCode);
    }
}

void forgetPassword::on_forgetButton_clicked()
{
    // 获取用户输入的验证码
    QString inputCheck = ui->checkLineEdit->text();

    // 检查验证码是否为空
    if (inputCheck.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入验证码！");
        return;
    }

    // 检查验证码是否正确
    if (inputCheck != generatedCode) {
        QMessageBox::warning(this, "验证码错误", "您输入的验证码不正确，请重新输入！");
    } else {
        // 验证码正确，查询并显示用户密码
        QString username = ui->userNameLineEdit->text();
        QString phone = ui->phoneNumberLineEdit->text();

        // 获取数据库连接
        QSqlDatabase db = QSqlDatabase::database();
        if (!db.isOpen()) {
            QMessageBox::critical(this, "数据库错误", "无法连接到数据库：" + db.lastError().text());
            return;
        }

        // 查询密码
        QSqlQuery query;
        query.prepare("SELECT Password FROM userinfo WHERE UserName = :username AND PhoneNumber = :phone");
        query.bindValue(":username", username);
        query.bindValue(":phone", phone);

        if (!query.exec()) {
            QMessageBox::critical(this, "查询错误", "无法查询数据库：" + query.lastError().text());
            return;
        }

        query.next();
        QString password = query.value(0).toString();

        if (password.isEmpty()) {
            QMessageBox::warning(this, "错误", "找不到该用户的密码！");
        } else {
            QMessageBox::information(this, "密码找回", "该用户的密码是：" + password);
        }
        return;
        // 清空验证码，准备下一次操作
        //generatedCode.clear();
    }
}
