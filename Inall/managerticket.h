// #ifndef MANAGERTICKET_H
// #define MANAGERTICKET_H

// #include <QWidget>
// #include <QTableWidget>
// #include <QSqlDatabase>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QTableWidgetItem>
// #include <QLabel>
// #include <QVBoxLayout>
// #include <QPushButton>

// extern QString g_userName;
// extern QString g_userPhone;

// namespace Ui {
// class managerticket;
// }

// class managerticket : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit managerticket(QWidget *parent = nullptr);
//     ~managerticket();

// private slots:
//     void searchUser(); // 槽函数，用于处理查询操作
// private:
//     Ui::managerticket *ui;
//     QTableWidget *tableWidget;  // 表格控件
//     QLineEdit *phoneInput;  // 手机号输入框
//     QPushButton *searchButton;  // 查询按钮
//     QLabel *resultLabel;  // 显示查询结果

//     bool connectDatabase();     // 数据库连接函数
//     void loadData();            // 加载数据
//     void handleChange(int row); // 处理改签
//     void handleCancel(int row); // 处理退票
//     void checkBoardingGate(int row); // 查看登机口
// };

// #endif // MANAGERTICKET_H




#ifndef MANAGERTICKET_H
#define MANAGERTICKET_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

extern QString g_userName;
extern QString g_userPhone;

namespace Ui {
class managerticket;
}

class managerticket : public QWidget
{
    Q_OBJECT

public:
    explicit managerticket(QWidget *parent = nullptr);
    ~managerticket();

private slots:
    void handleChange(int row);  // 改签按钮槽函数
    void handleCancel(int row);  // 退票按钮槽函数
    bool searchUser();           // 查询用户槽函数

private:
    Ui::managerticket *ui;
    QTableWidget *tableWidget;   // 航班信息表格
    QLineEdit *phoneInput;       // 手机号输入框
    QPushButton *searchButton;   // 查询按钮
    QLabel *resultLabel;         // 查询结果标签

    bool connectDatabase();      // 数据库连接函数
//    void loadData();             // 加载表格数据函数
    void fill_information();
};

#endif // MANAGERTICKET_H

