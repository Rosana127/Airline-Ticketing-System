#include "userinfopage.h"
#include "ui_userinfopage.h"

#include "global.h"





UserInfoPage::UserInfoPage(Database *db, const QString &username, QWidget *parent)
    : QWidget(parent), ui(new Ui::UserInfoPage), dbcon(db), currentUsername(g_userName) {
    ui->setupUi(this);

    // 显示用户信息
    displayUserInfo();

    // 绑定按钮点击事件
    connect(ui->buttonChangePassword, &QPushButton::clicked, this, &UserInfoPage::changePassword);
    connect(ui->buttonChangePhoneNumber, &QPushButton::clicked, this, &UserInfoPage::changePhoneNumber);
}

UserInfoPage::~UserInfoPage() {
    delete ui;
}

void UserInfoPage::displayUserInfo() {
    if (!dbcon || !dbcon->getDatabase().isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery query(dbcon->getDatabase());
    query.exec("USE flightdb");
    query.prepare("SELECT UserName, Gender FROM userinfo WHERE UserName = ?");
    query.addBindValue(g_userName);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to fetch user info:" << query.lastError().text();
        return;
    }

    ui->displayUserName->setText(query.value("UserName").toString());
    ui->displayGender->setText(query.value("Gender").toString());
}

void UserInfoPage::changePassword() {
    QString currentPassword = ui->editCurrentPassword->text();
    QString newPassword = ui->editPassword->text();

    if (currentPassword.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Error", "请输入当前密码和新密码！");
        return;
    }

    if (!dbcon || !dbcon->getDatabase().isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery query(dbcon->getDatabase());
    query.prepare("SELECT Password FROM userinfo WHERE UserName = ?");
    query.addBindValue(currentUsername);

    if (!query.exec() || !query.next() || query.value("Password").toString() != currentPassword) {
        QMessageBox::warning(this, "Error", "当前密码输入错误!");
        return;
    }
    QRegExp regex("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");

    if (!regex.exactMatch(newPassword)) {
        QMessageBox::warning(this, "密码错误", "密码必须是字母和数字的组合，且不少于8位！");
        return;
    }

    query.prepare("UPDATE userinfo SET Password = ? WHERE UserName = ?");
    query.addBindValue(newPassword);
    query.addBindValue(currentUsername);

    if (!query.exec()) {
        qDebug() << "对不起，密码修改失败！" << query.lastError().text();
        return;
    }

    QMessageBox::information(this, "Success", "密码修改成功！");
}

void UserInfoPage::changePhoneNumber() {
    QString currentPhoneNumber = ui->editCurrentPhoneNumber->text();
    QString newPhoneNumber = ui->editPhoneNumber->text();

    if (currentPhoneNumber.isEmpty() || newPhoneNumber.isEmpty()) {
        QMessageBox::warning(this, "Error", "请输入当前号码与新的号码!");
        return;
    }

    if (!dbcon || !dbcon->getDatabase().isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery query(dbcon->getDatabase());
    query.prepare("SELECT PhoneNumber FROM userinfo WHERE UserName = ?");
    query.addBindValue(currentUsername);

    if (!query.exec() || !query.next() || query.value("PhoneNumber").toString() != currentPhoneNumber) {
        QMessageBox::warning(this, "Error", "当前输入号码不正确！");
        return;
    }

    query.prepare("UPDATE userinfo SET PhoneNumber = ? WHERE UserName = ?");
    query.addBindValue(newPhoneNumber);
    query.addBindValue(currentUsername);

    if (!query.exec()) {
        qDebug() << "对不起，手机号修改失败！" << query.lastError().text();
        return;
    }

    QMessageBox::information(this, "Success", "手机号修改成功！");
}
