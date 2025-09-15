#ifndef CANCELORDERWINDOW_H
#define CANCELORDERWINDOW_H

#include <QWidget>
#include <QDialog>  // 确保包含 QDialog 头文件

class MyOrders;  // 前向声明 MyOrders 类


namespace Ui {
class CancelOrderWindow;
}

class CancelOrderWindow : public QDialog  // 确保继承自 QDialog
{
    Q_OBJECT

public:
    explicit CancelOrderWindow(QWidget *parent = nullptr);
    ~CancelOrderWindow();

private slots:
    void onConfirmCancel();
    void onCancelOrder();

private:
    Ui::CancelOrderWindow *ui;
    QString orderID;  // 保存订单ID
    MyOrders *myOrders;  // 保存 MyOrders 指针

signals:
    void orderCanceled(const QString &orderID);  // 自定义信号
};

#endif // CANCELORDERWINDOW_H
