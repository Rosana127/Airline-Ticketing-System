#include "cancelorderwindow.h"
#include "ui_cancelorderwindow.h"
#include "myorders.h"  // 引入 MyOrders 类
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>

CancelOrderWindow::CancelOrderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CancelOrderWindow)
{
    ui->setupUi(this);

    // 连接信号与槽
    connect(ui->confirmButton, &QPushButton::clicked, this, &CancelOrderWindow::onConfirmCancel);
    connect(ui->cancelButton, &QPushButton::clicked, this, &CancelOrderWindow::onCancelOrder);

    // 假设 MyOrders 是父窗口，连接 orderCanceled 信号到 MyOrders 的槽
    MyOrders* myOrders = qobject_cast<MyOrders*>(parent);
    if (myOrders) {
        connect(this, &CancelOrderWindow::orderCanceled, myOrders, &MyOrders::onOrderCanceled);
    }
}

CancelOrderWindow::~CancelOrderWindow()
{
    delete ui;
}

void CancelOrderWindow::onConfirmCancel()
{
    // 获取要取消的订单的订单编号
    QString orderID = ui->orderIDLineEdit->text();  // 假设订单编号输入框的对象名为 orderIDLineEdit

    // 执行删除操作
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE OrderID = :orderID");
    query.bindValue(":orderID", orderID);

    if (query.exec()) {
        emit orderCanceled(orderID);  // 发出信号，通知 MyOrders 取消该订单

        QMessageBox::information(this, "取消订单", "取消订单成功！");
        this->accept();
    } else {
        QMessageBox::warning(this, "取消订单", "取消订单失败！错误: " + query.lastError().text());
    }
}

void CancelOrderWindow::onCancelOrder()
{
    // 退出取消订单的逻辑
    QMessageBox::information(this, "取消订单", "已退出取消订单");
    this->reject();  // 关闭窗口，返回 QDialog::Rejected
}
