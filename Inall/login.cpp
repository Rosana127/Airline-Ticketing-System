#include "login.h"
#include "ui_login.h"
#include "forgetpassword2.h"
#include "database.h"
#include "manager1226.h"
#include "registerdialog2.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "homepage.h" // 注意这里也要更改
#include <QMouseEvent>
#include"inquire.h"
#include"global.h"


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    Database dbManager;
    if (!dbManager.connectToDatabase()) {
        qDebug() << "Failed to initialize database connection.";
    }else{
        qDebug()<<"Database is opened successfully!";
    }
}

Login::~Login()
{
    delete ui;
}
void Login::on_minimizeButton_clicked()
{
    showMinimized();
}

void Login::on_closeButton_clicked()
{
    close();
}

//鼠标移动边框功能
void Login::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_drag = true;
        m_dragPosition = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event) {
    if (m_drag && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void Login::mouseReleaseEvent(QMouseEvent *event) {
    m_drag = false;
}

void Login::on_registerButton_clicked()
{
    // 用户界面注册时
    RegisterDialog2* registerDialog2=new RegisterDialog2(); // false 表示用户注册
    registerDialog2->show();
}

void Login::on_forgetButton_clicked()
{
    forgetPassword2* forgetPass2=new forgetPassword2(nullptr);
    forgetPass2->show(); // 显示模态对话框
}

void Login::on_managerUiButton_clicked()
{
    // 创建manager1226窗口
    manager1226 *loginWindow = new manager1226();  // 设置父窗口为this，即Login
    //loginWindow->showFullScreen();

    // 显示manager1226窗口
    loginWindow->show();


    // 隐藏当前主窗口（如果需要）
        this->hide();

}

// 检查用户是否存在
bool Login::checkUserExists(const QString &account, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM UserInfo WHERE UserName = :account AND Password = :password");
    query.bindValue(":account", account);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        return true; // 用户存在
    }
    return false; // 用户不存在
}

// 登录按钮的槽函数
void Login::on_loginButton_clicked() {
    QString account = ui->txt_user->text();
    QString password = ui->txt_password->text();

    if (account.isEmpty() && password.isEmpty()) {
        QMessageBox::warning(this, "警告", "账号和密码不能为空！");
        return;
    }
    else if (account.isEmpty()) {
        QMessageBox::warning(this, "警告", "账号不能为空！");
        return;
    }
     else if (password.isEmpty()) {
        QMessageBox::warning(this, "警告", "密码不能为空！");
        return;
    }

    // 检查账号是否存在
    QSqlQuery query;
    query.exec("USE flightdb");
    query.prepare("SELECT Password FROM userinfo WHERE UserName = :account");
    query.bindValue(":account", account);

    if (query.exec()) {
        if (query.next()) {
            // 账号存在，检查密码是否匹配
            QString correctPassword = query.value(0).toString();
            if (password == correctPassword) {
                QMessageBox::information(this, "成功", "登录成功！");
                g_userName=account;
                HomePage *homepage = new HomePage;

                // 显示乘客信息页面
                homepage->show();

                // 隐藏当前页面
                this->hide();
            } else {
                QMessageBox::warning(this, "警告", "密码错误！");
            }
        } else {
            // 账号不存在
            QMessageBox::warning(this, "警告", "用户不存在！");
        }
    } else {
        QMessageBox::critical(this, "错误", "查询失败：" + query.lastError().text());
    }

}
