#include "registerdialog2.h"
#include "ui_registerdialog2.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QGroupBox>


RegisterDialog2::RegisterDialog2(QWidget *parent,bool isAdmin) :
     QWidget(parent), isAdmin(isAdmin),ui(new Ui::RegisterDialog2)
{
    ui->setupUi(this);
}

RegisterDialog2::~RegisterDialog2()
{
    delete ui;
}


void RegisterDialog2::on_registerButton_clicked()
{
    // 通过 ui 指针访问控件
    QString username = ui->userNameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirm = ui->confirmPassword->text();
    QString phone = ui->phoneNumberLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名和密码不能为空！");
        return;
    }
    if(confirm.isEmpty()){
        QMessageBox::warning(this, "输入错误", "请确认密码！");
        return;
    }
    if(phone.isEmpty()){
        QMessageBox::warning(this, "输入错误", "请绑定手机号！");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen()) {
        qDebug() << "Database is open.";
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return;  // 连接失败，返回
    }
    QSqlQuery checkQuery(db);
        checkQuery.exec("USE flightdb");
    //是否是管理员
    if(!isAdmin){
        checkQuery.prepare("SELECT COUNT(*) FROM userinfo WHERE UserName = :username");
        checkQuery.bindValue(":username", username);
    }
    else{
        checkQuery.prepare("SELECT Password FROM managerinfo WHERE ManagerName = :username");
        checkQuery.bindValue(":username", username);
    }

    if (!checkQuery.exec()) {
        QMessageBox::critical(nullptr, "错误", "查询数据库失败：" + checkQuery.lastError().text());
        return;  // 如果查询失败，返回
    }


    checkQuery.next(); // 结果返回一行
    int count = checkQuery.value(0).toInt();  // 获取返回的行数

    if (count > 0) {
        QMessageBox::warning(this, "用户已存在", "该用户名已被注册，请选择其他用户名");
        return;  // 如果用户名已存在，不进行注册
    }
    QRegExp regex("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");

    if (!regex.exactMatch(password)) {
        QMessageBox::warning(this, "密码错误", "密码必须是字母和数字的组合，且不少于8位！");
        return;
    }
    if (confirm != password) {
        QMessageBox::warning(this, "输入错误", "密码输入不一致！请重新输入！");
        return;
    }


    // 创建按钮组，并将复选框添加到该组

    QGroupBox *groupBox = new QGroupBox("Select an option");
    groupBox->setLayout(ui->horizontalLayout);


//    for (QObject *child : ui->horizontalLayout->children()) {
//        QRadioButton *radioButton = qobject_cast<QRadioButton *>(child); // 转换为 QRadioButton
//        if (radioButton) {
//            connect(radioButton, &QRadioButton::toggled, this, [radioButton, &sexValue]() {
//                if (radioButton->isChecked()) {
//                    sexValue = radioButton->text(); // 将选中按钮的文本赋值给 sexValue
//                    qDebug() << "Selected value:" << sexValue; // 打印选中值
//                }
//            });
//        }
//    }

    // 如果用户名不存在，则插入新用户
    QSqlQuery query;
    query.exec("USE flightdb");
    if(!isAdmin){
    query.prepare("INSERT INTO UserInfo (UserName, Password, PhoneNumber,Gender) "
                  "VALUES (:username, :password, :phone,:gender)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":phone", phone);
    query.bindValue(":gender",sexValue);
}else{
        query.prepare("INSERT INTO managerinfo (ManagerName, Password, PhoneNumber,Gender) "
                      "VALUES (:username, :password, :phone,:gerder)");
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        query.bindValue(":phone", phone);
         query.bindValue(":gender",sexValue);
    }
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "注册失败", "无法注册用户：" + query.lastError().text());
    } else {
        QMessageBox::information(nullptr, "注册成功", "用户注册成功！");
        this->hide();
    }
}


void RegisterDialog2::on_male_clicked()
{
        sexValue = ui->male->text(); // 将选中按钮的文本赋值给 sexValue
        qDebug() << "Selected value:" << sexValue; // 打印选中值
}

void RegisterDialog2::on_female_clicked()
{
    sexValue = ui->female->text(); // 将选中按钮的文本赋值给 sexValue
    qDebug() << "Selected value:" << sexValue; // 打印选中值
}

void RegisterDialog2::on_otherSex_clicked()
{
    sexValue = ui->otherSex->text(); // 将选中按钮的文本赋值给 sexValue
    qDebug() << "Selected value:" << sexValue; // 打印选中值
}
