#ifndef MYORDERS_H
#define MYORDERS_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QStandardItemModel>
#include <QListView>

class CancelOrderWindow;  // 前向声明 CancelOrderWindow
class InboxWindow;  // 引入 InboxWindow 类

namespace Ui {
class MyOrders;
}

class MyOrders : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyOrders(QWidget *parent = nullptr);
    ~MyOrders();

public slots:
    void onOrderCanceled(const QString &orderID);
    void removeOrderFromDepartureList(const QString &orderID);

private slots:
    void loadOrders(int tabIndex);  // 加载不同状态的订单
    void showTicketDetails();       // 查看电子登机牌
    void loadCompletedOrders();  // 加载已完成的订单
    void showRatingWindow();     // 显示评价窗口
    void openCancelOrderWindow();  // 声明 openCancelOrderWindow 函数
    void openInbox();  // 打开收件箱窗口

private:
    Ui::MyOrders *ui;
    void connectToDatabase();  // 数据库连接
    void loadPendingDepartureOrders();  // 加载待出发的订单
    InboxWindow *inboxWindow;  // 收件箱窗口对象
};

#endif // MYORDERS_H
