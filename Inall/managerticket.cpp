// #include "managerticket.h"
// #include "ui_managerticket.h"
// #include <QSqlError>
// #include <QMessageBox>
// #include <QDebug>
// #include <QHeaderView>
// #include <QLineEdit>
// #include <QWidget>
#include"global.h"

// QString g_userName = "Mary";
// QString g_userPhone = "130130130";

// managerticket::managerticket(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::managerticket)
// {
//     ui->setupUi(this);

//     // 创建表格
//     tableWidget = new QTableWidget(this);
//     tableWidget->setColumnCount(11);
//     tableWidget->setHorizontalHeaderLabels({"航班号", "起始地", "到达地", "日期", "时间", "机票类型", "价格", "登机状态", "登机口", "改签", "退票"});

//     // 设置选择行为为选择整行
//     tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//     tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); // 只允许选择一行

//     // 自适应宽度
//     tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//     // //////////////////////////////////////////////////////////
//     // 创建手机号输入框
//     phoneInput = new QLineEdit(this);
//     phoneInput->setPlaceholderText("请输入手机号");

//     // 创建查询按钮
//     searchButton = new QPushButton("查询", this);

//     // 创建结果显示标签
//     resultLabel = new QLabel(this);
//     resultLabel->setText("查询结果将显示在这里");
//     resultLabel->setWordWrap(true);  // 自动换行

//     // 布局
//     QVBoxLayout *layout = new QVBoxLayout(this);
//     layout->addWidget(phoneInput);
//     layout->addWidget(searchButton);
//     layout->addWidget(resultLabel);
//     setLayout(layout);

//     // 连接查询按钮的点击信号到槽函数
//     connect(searchButton, &QPushButton::clicked, this, &managerticket::searchUser);
// }






//     // 创建头像标签
//     QLabel *avatarLabel = new QLabel(this);
//     QPixmap avatarPixmap("D:\\Grade-2\\Training Project\\managerTicket1210\\travelDog");  // 使用文件路径
//     if (avatarPixmap.isNull()) {
//         qDebug() << "图片加载失败";
//     } else {
//         avatarLabel->setPixmap(avatarPixmap.scaled(150, 150, Qt::KeepAspectRatio));  // 设置头像大小为150x150像素
//     }

//     // 创建垂直布局用于存放用户名和手机号
//     QVBoxLayout *infoLayout = new QVBoxLayout();
//     infoLayout->setAlignment(Qt::AlignVCenter);

//     // 创建用户名标签
//     QLabel *userNameLabel = new QLabel("姓名：" + g_userName, this);
//     userNameLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");

//     // 创建手机号标签
//     QLabel *phoneLabel = new QLabel("手机号：" + g_userPhone, this);
//     phoneLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");

//     // 将用户名和手机号标签加入垂直布局
//     infoLayout->addWidget(userNameLabel);
//     infoLayout->addWidget(phoneLabel);

//     // 创建水平布局用于排列头像和信息
//     QHBoxLayout *userLayout = new QHBoxLayout();
//     userLayout->addWidget(avatarLabel);
//     userLayout->addLayout(infoLayout);

//     // 创建主布局
//     QVBoxLayout *layout = new QVBoxLayout(this);
//     layout->addLayout(userLayout);   // 添加用户信息布局
//     layout->addWidget(tableWidget); // 添加表格

//     // 连接数据库
//     if (!connectDatabase()) {
//         qCritical() << "数据库连接失败!";
//         return;
//     }

//     // 加载数据
//     loadData();
// }

// managerticket::~managerticket()
// {
//     delete ui;
// }

// bool managerticket::connectDatabase() {
//     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//     db.setDatabaseName("flightdb");  // 替换为你配置的 DSN 名称

//     if (!db.open()) {
//         qCritical() << "数据库连接失败：" << db.lastError().text();
//         return false;
//     }
//     qDebug() << "数据库连接成功!";
//     return true;
// }

// void managerticket::loadData() {
//     QSqlQuery query;
//     query.prepare("SELECT FlightNumber, DepartureCity, ArrivalCity, FlightDate, FlightTime, TicketType, Price, BoardingStatus, BoardingGate "
//                   "FROM FlightOrders WHERE PassengerName = :userName ORDER BY FlightDate ASC");
//     query.bindValue(":userName", g_userName);
//     if (!query.exec()) {
//         qCritical() << "查询执行失败：" << query.lastError().text();
//         return;
//     }

//     // 填充表格数据
//     int row = 0;
//     while (query.next()) {
//         tableWidget->insertRow(row);

//         // 设置每个单元格的值
//         for (int col = 0; col < 9; ++col) {
//             tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
//         }

//         // 添加按钮
//         QPushButton *changeButton = new QPushButton("改签");
//         connect(changeButton, &QPushButton::clicked, [this, row]() { handleChange(row); });

//         QPushButton *cancelButton = new QPushButton("退票");
//         connect(cancelButton, &QPushButton::clicked, [this, row]() { handleCancel(row); });

//         tableWidget->setCellWidget(row, 9, changeButton);
//         tableWidget->setCellWidget(row, 10, cancelButton);

//         ++row;
//     }
// }

// void managerticket::handleChange(int row) {
//     QString flightNumber = tableWidget->item(row, 0)->text();
//     QString message = QString("您确定要改签航班 %1 吗？").arg(flightNumber);
//     QMessageBox::question(this, "确认改签", message, QMessageBox::Yes | QMessageBox::No);
// }

// void managerticket::handleCancel(int row) {
//     QString flightNumber = tableWidget->item(row, 0)->text();
//     QString message = QString("您确定要取消航班 %1 吗？").arg(flightNumber);
//     QMessageBox::question(this, "确认退票", message, QMessageBox::Yes | QMessageBox::No);
// }

// void managerticket::checkBoardingGate(int row) {
//     QString gate = tableWidget->item(row, 8)->text();
//     QMessageBox::information(this, "登机口", "您的登机口是 " + gate);
// }

// // ////////////////////////

// void managerTicket::searchUser()
// {
//     QString phone = phoneInput->text();  // 获取用户输入的手机号

//     if (phone.isEmpty()) {
//         QMessageBox::warning(this, "输入错误", "请输入有效的手机号！");
//         return;
//     }

//     // 假设数据库已经连接
//     QSqlQuery query;
//     query.prepare("SELECT name FROM users WHERE phone = :phone");
//     query.bindValue(":phone", phone);

//     if (!query.exec()) {
//         QMessageBox::critical(this, "数据库错误", "查询失败：" + query.lastError().text());
//         return;
//     }

//     if (query.next()) {
//         QString name = query.value("name").toString();  // 获取查询结果中的姓名
//         resultLabel->setText("用户名：" + name);
//     } else {
//         resultLabel->setText("未找到对应的用户！");
//     }
// }



#include "managerticket.h"
#include "ui_managerticket.h"
#include <QSqlError>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QHeaderView>
#include <QString>
#include <QInputDialog>
#include <QPushButton>



#include"global.h"
#include<QLabel>
#include"myticket.h"
#include "inquire.h"
#include "database.h"
#include "homepage.h"


managerticket::managerticket(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::managerticket)
{
    ui->setupUi(this);

    // 创建表格
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(11);
    tableWidget->setHorizontalHeaderLabels({"航班号", "起始地", "到达地", "日期", "时间", "机票类型", "价格", "登机状态" ,"登机口","订单号", "退票",});
    tableWidget->setStyleSheet("font-size: 20px;");
    tableWidget->setFixedWidth(1660);
    // 设置每列宽度，根据需求分配总宽度（示例分配列宽）
    int columnWidths[] = {120, 120, 150, 150, 150, 150, 150, 200, 150, 150, 150};
    for (int i = 0; i < tableWidget->columnCount(); ++i) {
        tableWidget->setColumnWidth(i, columnWidths[i]);
    }
    tableWidget->horizontalHeader()->setStretchLastSection(false); // 禁止最后一列自动拉伸
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); // 禁用所有列的自动调整

    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 创建手机号输入框和查询按钮
    phoneInput = new QLineEdit(this);
    phoneInput->setPlaceholderText("请输入手机号");
    phoneInput->setStyleSheet("font-size: 24px;");
    phoneInput->setFixedWidth(1660);
    searchButton = new QPushButton("查询", this);
    searchButton->setStyleSheet("font-size: 24px; font-weight: bold;");
    searchButton->setFixedWidth(1660);

    resultLabel = new QLabel(this);
    resultLabel->setText("查询结果将显示在这里");
    resultLabel->setWordWrap(true);
    resultLabel->setStyleSheet("font-size: 20px;"); // 设置标签字体为 24px
    resultLabel->setFixedWidth(1660);
    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    // mainLayout->addLayout(userLayout);       // 用户信息
    mainLayout->addWidget(phoneInput);       // 手机号输入
    mainLayout->addWidget(searchButton);     // 查询按钮
    mainLayout->addWidget(resultLabel);      // 查询结果
    mainLayout->addWidget(tableWidget);      // 表格
    setLayout(mainLayout);


    // 信号槽连接
    connect(searchButton, &QPushButton::clicked, this, &managerticket::searchUser);
//    connectDatabase();
    // 数据库连接和数据加载
    // if (connectDatabase()) {
    //     loadData();
    // }
}

managerticket::~managerticket()
{
    delete ui;
}

bool managerticket::connectDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("abc");  // 替换为实际 DSN 名称
    if (!db.open()) {
        qCritical() << "数据库连接失败：" << db.lastError().text();
        return false;
    }
    qDebug() << "数据库连接成功!";
    return true;
}


bool managerticket::searchUser()
{
    QString phone = phoneInput->text();
    if (phone.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入有效的手机号！");
        return false;
    }

    // 第一次查询: 查找用户
    QSqlQuery query;
    query.exec("USE flightdb");
    query.prepare("SELECT UserName FROM ordertable WHERE PhoneNumber = :phone");
    query.bindValue(":phone", phone);
    if (!query.exec()) {
        QMessageBox::critical(this, "数据库错误", "查询失败：" + query.lastError().text());
        return false;
    }

    if (query.next()) {
        QString name = query.value("UserName").toString();
        resultLabel->setText("用户名：" + name);
        QMessageBox::information(this, "成功", "找到用户 " + name);
        g_userName = name;
        g_userPhone = phone;

        // 第二次查询: 查找该用户的航班信息

        query.prepare("SELECT FlightNumber_lmh, DepartureCity, ArrivalCity, FlightDate, FlightTime, TicketType, Price, BoardingStatus, BoardingGate, OrderID "
                      "FROM ordertable WHERE UserName = :userName ORDER BY FlightDate ASC");
        query.bindValue(":userName", g_userName);


        // 执行查询
        if (!query.exec()) {
            QMessageBox::critical(this, "数据库错误", "查询失败：" + query.lastError().text());
            return false;
        }

        // 清空表格之前的内容
        //tableWidget->setRowCount(0);

        QString ticketType = query.value(5).toString();
        QString boardingGate;

        // 根据TicketType设置登机口
        if (ticketType == "头等舱") {
            boardingGate = "212";
        } else if (ticketType == "商务舱") {
            boardingGate = "214";
        } else if (ticketType == "经济舱") {
            boardingGate = "227";
        } else if (ticketType == "超级经济舱") {
            boardingGate = "268";
        } else {
            boardingGate = "229"; // 如果票种不匹配，使用“未知”作为默认值
        }

        // 更新数据库中的BoardingGate字段
        QString orderID = query.value(9).toString();  // 获取OrderID
        QSqlQuery updateQuery;
        updateQuery.exec("USE flightdb");
        updateQuery.prepare("UPDATE ordertable SET BoardingGate = :boardingGate WHERE OrderID = :orderID");
        updateQuery.bindValue(":boardingGate", boardingGate);
        updateQuery.bindValue(":orderID", orderID);
        if (!updateQuery.exec()) {
            qCritical() << "更新登机口失败：" << updateQuery.lastError().text();
        }

        // 填充表格数据
        int row = 0;
        while (query.next()) {
            tableWidget->insertRow(row);

            // 获取航班的起飞时间
            QString flightDate = query.value(3).toString();  // FlightDate
            QString flightTime = query.value(4).toString();  // FlightTime
            QDateTime flightDateTime = QDateTime::fromString(flightDate + " " + flightTime, "yyyy-MM-dd hh:mm:ss");

            // 获取当前时间
            QDateTime currentTime = QDateTime::currentDateTime();

            // 计算时间差
            qint64 timeDiff = currentTime.msecsTo(flightDateTime);

            // 判断航班的登机状态
            QString boardingStatus;
            if (timeDiff > 0) {
                // 航班起飞前
                if (timeDiff > 60 * 60 * 1000) {  // 起飞前超过一小时
                    boardingStatus = "待登机";
                } else if (timeDiff > 30 * 60 * 1000) {  // 起飞前半小时到一小时
                    boardingStatus = "登机中";
                } else {  // 起飞前不到半小时
                    boardingStatus = "已登机";
                }
            } else {
                boardingStatus = "航班已起飞";
            }

            // 设置每个单元格的值
            tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
            tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
            tableWidget->setItem(row, 7, new QTableWidgetItem(boardingStatus));
            tableWidget->setItem(row, 8, new QTableWidgetItem(boardingGate));

            // 获取OrderID并插入到第九列
            QString orderIDFromQuery = query.value(9).toString();  // OrderID
            tableWidget->setItem(row, 9, new QTableWidgetItem(orderIDFromQuery));  // 插入OrderID到第九列


            // 创建并添加改签按钮
            // QPushButton *changeButton = new QPushButton("改签");
            // connect(changeButton, &QPushButton::clicked, [this, row](){
            //     handleChange(row);  // 调用处理改签的槽函数
            // });

            // 创建并添加退票按钮
            QPushButton *cancelButton = new QPushButton("退票");
            connect(cancelButton, &QPushButton::clicked, [this, row](){
                handleCancel(row);  // 调用处理退票的槽函数
            });

            // 将按钮添加到表格的最后两列
            tableWidget->setCellWidget(row, 10, cancelButton);
            //tableWidget->setCellWidget(row, 11, changeButton);

            ++row;
        }

        return true;
    } else {
        resultLabel->setText("未找到对应的用户！");
        QMessageBox::critical(this, "失败", "未找到用户");
        //return false;
    }
}

// 处理退票操作
void managerticket::handleCancel(int row) {
    // 获取当前行的OrderID 和航班号及舱位
    QString orderID = tableWidget->item(row, 9)->text();  // 获取订单编号（第九列）
    QString flightNumber = tableWidget->item(row, 0)->text();  // 获取航班号（第一列）
    QString ticketType = tableWidget->item(row, 5)->text();  // 获取票种（第六列）

    // 弹出一个输入框，让用户输入订单编号
    bool ok;
    QString inputOrderID = QInputDialog::getText(this, "输入订单编号", "请输入订单编号:", QLineEdit::Normal, "", &ok);

    if (ok && !inputOrderID.isEmpty()) {
        // 判断输入的订单编号是否与当前订单编号一致
        if (inputOrderID == orderID) {
            // 如果编号匹配，弹窗提示退票成功
            int ret = QMessageBox::question(this, "确认退票", "退票成功！",
                                            QMessageBox::Yes | QMessageBox::No);
            if (ret == QMessageBox::Yes) {
                // 删除订单信息
                QSqlQuery deleteQuery;
                deleteQuery.exec("USE flightdb");
                deleteQuery.prepare("DELETE FROM ordertable WHERE OrderID = :orderID");
                deleteQuery.bindValue(":orderID", orderID);

                if (deleteQuery.exec()) {
                    qDebug() << "订单已删除：" << orderID;

                    // 更新flightinfo表中的booktickets
                    QSqlQuery updateQuery;
                    updateQuery.exec("USE flightdb");
                    updateQuery.prepare("UPDATE flightinfo SET booktickets = booktickets + 1 "
                                        "WHERE FlightNumber = :flightNumber AND SeatType = :seatType");
                    updateQuery.bindValue(":flightNumber", flightNumber);  // 使用航班号
                    updateQuery.bindValue(":seatType", ticketType);         // 使用舱位类型
                    if (updateQuery.exec()) {
                        qDebug() << "flightinfo表中的booktickets更新成功";
                    } else {
                        qCritical() << "更新booktickets失败：" << updateQuery.lastError().text();
                    }

                    QMessageBox::information(this, "退票", "订单已删除，退票成功！");
                    // 清空表格中的现有数据
                    tableWidget->clearContents();
                    tableWidget->setRowCount(0);  // 重置行数为0

                    // 重新加载数据，刷新订单列表
                    searchUser();
                } else {
                    qCritical() << "删除订单失败：" << deleteQuery.lastError().text();
                    QMessageBox::critical(this, "退票", "删除订单失败，请稍后再试！");
                }
            }
        } else {
            // 如果订单编号不匹配，弹窗提示错误
            QMessageBox::warning(this, "编号错误", "编号错误，退出退票过程");
        }
    }
}

// // 处理改签操作
 void managerticket::handleChange(int row) {
     //QMessageBox::information(this, "改签", "确认改签");
     QString flightNumber = tableWidget->item(row, 0)->text();
     QString message = QString("您确定要改签航班 %1 吗？").arg(flightNumber);

     QMessageBox::question(this, "确认改签", message,QMessageBox::Yes | QMessageBox::No);

 }


// void managerticket::handleChange(int row) {
//     // 获取当前行的航班号、订单编号和票种
//     QString orderID = tableWidget->item(row, 9)->text();  // 订单编号
//     QString flightNumber = tableWidget->item(row, 0)->text();  // 航班号
//     QString ticketType = tableWidget->item(row, 5)->text();  // 票种

//     // 弹出提示框确认改签操作
//     QString message = QString("您确定要改签航班 %1 吗？").arg(flightNumber);
//     int ret = QMessageBox::question(this, "确认改签", message, QMessageBox::Yes | QMessageBox::No);

//     if (ret == QMessageBox::Yes) {
//         // 删除旧订单
//         QSqlQuery deleteQuery;
//         deleteQuery.exec("USE flightdb");
//         deleteQuery.prepare("DELETE FROM ordertable WHERE OrderID = :orderID");
//         deleteQuery.bindValue(":orderID", orderID);

//         if (deleteQuery.exec()) {
//             qDebug() << "订单已删除：" << orderID;

//             // 更新flightinfo表中的booktickets
//             QSqlQuery updateQuery;
//             updateQuery.exec("USE flightdb");
//             updateQuery.prepare("UPDATE flightinfo SET booktickets = booktickets + 1 "
// //                                 "WHERE FlightNumber = :flightNumber AND SeatType = :seatType");
//             updateQuery.bindValue(":flightNumber", flightNumber);
//             updateQuery.bindValue(":seatType", ticketType);

//             if (updateQuery.exec()) {
//                 qDebug() << "flightinfo表中的booktickets更新成功";
//             } else {
//                 qCritical() << "更新booktickets失败：" << updateQuery.lastError().text();
//             }

//             QMessageBox::information(this, "改签", "退款已返回原账户，旧订单已删除，请用户登录系统选择新的航班进行改签！");

//             // 清空表格并重新加载数据
//             tableWidget->clearContents();
//             tableWidget->setRowCount(0);
//             searchUser();

//             homepage* tmp=new HomePage()
//         } else {
//             qCritical() << "删除订单失败：" << deleteQuery.lastError().text();
//             QMessageBox::critical(this, "改签", "删除旧订单失败，请稍后再试！");
//         }
//     } else {
//         QMessageBox::information(this, "改签", "您已取消改签操作！");
//     }
// }

