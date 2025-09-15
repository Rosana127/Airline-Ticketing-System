#include "myticket.h"
#include "ui_myticket.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>

#include"global.h"
#include<QLabel>
#include"myticket.h"
#include "inquire.h"
#include "database.h"
#include "homepage.h"

myTicket::myTicket(QWidget *parent)
    : QWidget(parent),
    homePage(qobject_cast<HomePage*>(parent))  // 获取父窗口 HomePage 实例

    , ui(new Ui::myTicket)
{
    // 设置窗口的初始位置和大小
   //this->setGeometry(200, 500, 800, 911);

    // 初始化 UI
    ui->setupUi(this);

    // 创建表格
    tableWidget = new QTableWidget(this);
    //tableWidget->move(500, 150);
    tableWidget->setColumnCount(13);
    tableWidget->setHorizontalHeaderLabels({"航班号", "起始地", "到达地", "日期", "时间", "机票类型", "价格", "登机状态", "登机口", "订单编号", "座位号","", ""});
    tableWidget->setStyleSheet("font-size: 20px;");
    // 设置选择行为为选择整行
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  // 只允许选择一行

    // 自适应宽度
    //tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 创建头像标签
    // QLabel *avatarLabel = new QLabel(this);
    // QPixmap avatarPixmap(":/images/travelDog");  // 使用文件路径
    // if (avatarPixmap.isNull()) {
    //     qDebug() << "图片加载失败";
    // } else {
    //     avatarLabel->setPixmap(avatarPixmap.scaled(150, 150, Qt::KeepAspectRatio));  // 设置头像大小为150x150像素
    // }

    // // 创建垂直布局用于存放用户名和手机号
    // QVBoxLayout *infoLayout = new QVBoxLayout();
    // infoLayout->setAlignment(Qt::AlignVCenter);

    // // 创建用户名标签
    // QLabel *userNameLabel = new QLabel("姓名：" + g_userName, this);
    // userNameLabel->setAlignment(Qt::AlignLeft);
    // userNameLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");  // 设置样式，字体加粗，颜色更深

    // // 创建手机号标签
    // QLabel *phoneLabel = new QLabel("手机号：" + g_userPhone, this);
    // phoneLabel->setAlignment(Qt::AlignLeft);
    // phoneLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");  // 设置样式，手机号字体稍小，颜色浅一些

    // // 将用户名和手机号标签加入垂直布局
    // infoLayout->addWidget(userNameLabel);
    // infoLayout->addWidget(phoneLabel);

    // // 创建水平布局，用于排列头像和信息
     QHBoxLayout *userLayout = new QHBoxLayout();
    // userLayout->setSpacing(10);  // 设置间距，头像和信息之间的距离
    // userLayout->addWidget(avatarLabel);  // 头像
    // userLayout->addLayout(infoLayout);  // 用户名和手机号

    // 创建主布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 将用户信息布局添加到主布局中
    layout->addLayout(userLayout);

    // 添加表格控件
    layout->addWidget(tableWidget);



//    // 连接数据库
//    if (!connectDatabase()) {
//        qCritical() << "数据库连接失败!";
//        return;
//    }

    // 从数据库查询数据并填充表格
    loadData();
}



myTicket::~myTicket()
{
    delete ui;
}

//bool myTicket::connectDatabase() {
//    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
//    db.setDatabaseName("abc");  // 替换为你配置的 DSN 名称

//    if (!db.open()) {
//        qCritical() << "数据库连接失败：" << db.lastError().text();
//        return false;
//    }
//    qDebug() << "数据库连接成功!";
//    return true;
//}

void myTicket::loadData() {
    QSqlQuery query;
    query.exec("USE flightdb");

    query.prepare("SELECT FlightNumber_lmh, DepartureCity, ArrivalCity, FlightDate, FlightTime, TicketType, Price, BoardingStatus, BoardingGate, OrderID,Seat "
                  "FROM ordertable WHERE UserName = :userName ORDER BY FlightDate ASC");
    query.bindValue(":userName",g_userName);




    if (!query.exec()) {
        qCritical() << "查询执行失败：" << query.lastError().text();
        return;
    }

    // 遍历查询结果，根据TicketType设置登机口并更新数据库
    while (query.next()) {
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
            boardingGate = "未知"; // 如果票种不匹配，使用“未知”作为默认值
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
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
qDebug() << "数据库连接成功!111";

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

        QString insert12="未选座";
        if(!query.value(10).toString().isEmpty()) insert12=query.value(10).toString();
        tableWidget->setItem(row,10,new QTableWidgetItem(insert12));

        // 创建并添加改签按钮
        QPushButton *changeButton = new QPushButton("改签");
        connect(changeButton, &QPushButton::clicked, [this, row](){
            handleChange(row);  // 调用处理改签的槽函数
        });

        // 创建并添加退票按钮
        QPushButton *cancelButton = new QPushButton("退票");
        connect(cancelButton, &QPushButton::clicked, [this, row](){
            handleCancel(row);  // 调用处理退票的槽函数
        });

        // 将按钮添加到表格的最后两列
        tableWidget->setCellWidget(row, 11, changeButton);
        tableWidget->setCellWidget(row, 12, cancelButton);


    }
}


// 处理退票操作
void myTicket::handleCancel(int row) {
    // 获取当前行的OrderID 和航班号及舱位
    QString orderID = tableWidget->item(row, 9)->text();  // 获取订单编号（第九列）
    QString flightNumber = tableWidget->item(row, 0)->text();  // 获取航班号（第一列）
    QString ticketType = tableWidget->item(row, 5)->text();  // 获取票种（第六列）

    // 弹出一个输入框，让用户输入订单编号
    bool ok;
    QString inputOrderID = QInputDialog::getText(this, "输入订单编号", "请输入您的订单编号:", QLineEdit::Normal, "", &ok);

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
                    updateQuery.prepare("UPDATE flightinfo SET booktickets = booktickets -1  "
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
                    loadData();
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


void myTicket::handleChange(int row) {
    // 获取当前行的航班号、订单编号和票种
    QString orderID = tableWidget->item(row, 9)->text();  // 订单编号
    QString flightNumber = tableWidget->item(row, 0)->text();  // 航班号
    QString ticketType = tableWidget->item(row, 5)->text();  // 票种

    // 弹出提示框确认改签操作
    QString message = QString("您确定要改签航班 %1 吗？").arg(flightNumber);
    int ret = QMessageBox::question(this, "确认改签", message, QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        // 删除旧订单
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
            updateQuery.bindValue(":flightNumber", flightNumber);
            updateQuery.bindValue(":seatType", ticketType);

            if (updateQuery.exec()) {
                qDebug() << "flightinfo表中的booktickets更新成功";
            } else {
                qCritical() << "更新booktickets失败：" << updateQuery.lastError().text();
            }

            QMessageBox::information(this, "改签", "退款已返回原账户，旧订单已删除，可以选择新的航班进行改签！");

            // 触发 HomePage 的 on_searchFlightButton_clicked 方法，自动跳转到选座页面
            if (homePage) {
                // 直接调用 HomePage 的槽函数
                QMetaObject::invokeMethod(homePage, "on_searchFlightButton_clicked");
            }

            // 清空表格并重新加载数据
            tableWidget->clearContents();
            tableWidget->setRowCount(0);
            loadData();
        } else {
            qCritical() << "删除订单失败：" << deleteQuery.lastError().text();
            QMessageBox::critical(this, "改签", "删除旧订单失败，请稍后再试！");
        }
    } else {
        QMessageBox::information(this, "改签", "您已取消改签操作！");
    }
}
