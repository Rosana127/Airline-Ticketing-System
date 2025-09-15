#include "myorders.h"  // 修改为 MyOrders 类
#include "ui_myorders.h"  // 修改为 MyOrders 的 UI 文件
#include "ticketwindow.h"
#include "ratingwindow.h"
#include "cancelorderwindow.h"
#include "inboxwindow2.h"

#include <QSqlQuery>
#include <QStandardItemModel>
#include <QDebug>
#include <QSqlError>

MyOrders::MyOrders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyOrders)  // 修改为 MyOrders
{
    ui->setupUi(this);

//    connectToDatabase();

    // 加载已完成的订单
    loadCompletedOrders();
    // 加载待出发的订单
    loadPendingDepartureOrders();

    // 为每个标签页设置数据加载
    // 加载订单
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MyOrders::loadOrders);
    // 点击按钮，弹出登机牌
    connect(ui->btn_viewTicket, &QPushButton::clicked, this, &MyOrders::showTicketDetails);
    // 点击按钮，弹出评价窗口
    connect(ui->btn_rate, &QPushButton::clicked, this, &MyOrders::showRatingWindow);
    // 点击取消订单按钮，弹出取消订单窗口
    connect(ui->cancelOrderButton, &QPushButton::clicked, this, &MyOrders::openCancelOrderWindow);
    // 点击按钮，弹出收件箱
    connect(ui->inboxButton, &QPushButton::clicked, this, &MyOrders::openInbox);

    // 选择栏目的限定
    ui->listView_completed->setSelectionMode(QAbstractItemView::SingleSelection);  // 设置为单选模式
    ui->listView_completed->setSelectionBehavior(QAbstractItemView::SelectRows);    // 设置按行选择
}

MyOrders::~MyOrders()
{
    delete ui;
}

// 连接数据库
void MyOrders::connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("flightdb");  // 请替换为实际数据库名称

    if (!db.open()) {
        qDebug() << "Error: unable to connect to database";
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "Connected to database!";
    }
}

// 在listview加载已完成的订单
void MyOrders::loadCompletedOrders() {
    QSqlQuery query;
    query.exec("USE flightdb");
    query.prepare("SELECT OrderID FROM orders WHERE Status = '已完成' AND UserName = 'USER1'");
    query.exec();

    QStandardItemModel* model = new QStandardItemModel();
    while (query.next()) {
        QString orderID = query.value("OrderID").toString();
        QStandardItem* item = new QStandardItem(orderID);
        model->appendRow(item);
    }

    ui->listView_completed->setModel(model);  // 在列表中显示已完成订单
}

// 在listview加载待出发的订单
void MyOrders::loadPendingDepartureOrders() {
    QSqlQuery query;
    query.prepare("SELECT OrderID FROM orders WHERE Status = '待出发' AND UserName = 'USER1'");
    query.exec();

    QStandardItemModel* model = new QStandardItemModel();
    while (query.next()) {
        QString orderID = query.value("OrderID").toString();
        QStandardItem* item = new QStandardItem(orderID);
        model->appendRow(item);
    }

    ui->listView_departure->setModel(model);  // 在列表中显示订单编号
}

// 从数据库获取数据并加载订单
void MyOrders::loadOrders(int tabIndex) {
    char Status;
    switch (tabIndex) {
    case 0:
        Status = '0';  // 全部
        break;
    case 1:
        Status = '1';  // 待支付
        break;
    case 2:
        Status = '2';  // 待出发
        break;
    case 3:
        Status = '3';  // 已完成
        break;
    default:
        return;  // 非法的索引，直接返回
    }

    QString currentUserName = "USER1";  // 假设用户名是 USER1

    // 创建查询对象
    QSqlQuery query;
    QString queryStr = "SELECT OrderID, FlightNumber, SeatNumber, Status, DepartureGate "
                       "FROM orders "
                       "WHERE UserName = :userName";

    // 根据状态添加过滤条件
    if (Status == '0') {  // 全部
        queryStr += " AND Status IN ('待支付', '待出发', '已完成')";
    } else if (Status == '1') {  // 待支付
        queryStr += " AND Status = '待支付'";
    } else if (Status == '2') {  // 待出发
        queryStr += " AND Status = '待出发'";
    } else if (Status == '3') {  // 已完成
        queryStr += " AND Status = '已完成'";
    }

    // 准备查询
    query.prepare(queryStr);
    query.bindValue(":userName", currentUserName);  // 绑定当前用户名
    query.exec();

    // 创建模型并填充数据
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"订单编号", "航班号", "座位号", "状态", "登机口"});

    // 遍历查询结果并将其填充到模型中
    while (query.next()) {
        QString orderID = query.value("OrderID").toString();
        QString flightNumber = query.value("FlightNumber").toString();
        QString seatNumber = query.value("SeatNumber").toString();
        QString statusStr = query.value("Status").toString();
        QString departureGate = query.value("DepartureGate").toString();

        QList<QStandardItem*> row;
        row.append(new QStandardItem(orderID));
        row.append(new QStandardItem(flightNumber));
        row.append(new QStandardItem(seatNumber));
        row.append(new QStandardItem(statusStr));
        row.append(new QStandardItem(departureGate));

        model->appendRow(row);
    }

    // 根据传入的状态，选择合适的标签页展示数据
    if (Status == '0') {
        ui->table_view_1->setModel(model);  // 显示全部订单
    } else if (Status == '1') {
        ui->table_view_2->setModel(model);  // 显示待支付订单
    } else if (Status == '2') {
        ui->table_view_3->setModel(model);  // 显示待出发订单
    } else if (Status == '3') {
        ui->table_view_4->setModel(model);  // 显示已完成订单
    }
}

// 查看登机牌
void MyOrders::showTicketDetails() {
    QModelIndex index = ui->listView_departure->currentIndex();  // 获取当前选中的订单编号
    if (index.isValid()) {
        QString orderID = index.data().toString();  // 获取订单编号
        TicketWindow* ticketWindow = new TicketWindow(orderID, nullptr);  // 使用 nullptr 确保它是独立窗口
        ticketWindow->resize(400, 300);  // 设置窗口大小
        ticketWindow->move(600, 400);    // 设置窗口位置
        ticketWindow->show();  // 显示电子登机牌
    }
}

// 评价
void MyOrders::showRatingWindow() {
    QModelIndex index = ui->listView_completed->currentIndex();
    if (index.isValid()) {
        QString orderID = index.data().toString();  // 获取选中的订单编号
        RatingWindow* ratingWindow = new RatingWindow(orderID, this);  // 创建评价窗口

        ratingWindow->setWindowFlags(Qt::Window);  // 设置边框窗口
        ratingWindow->setAttribute(Qt::WA_DeleteOnClose);  // 窗口关闭后自动删除
        ratingWindow->show();  // 显示评价窗口
    } else {
        qDebug() << "No order selected";
    }
}

// 取消订单
void MyOrders::openCancelOrderWindow()
{
    // 创建取消订单窗口并显示
    CancelOrderWindow *cancelWindow = new CancelOrderWindow(this);  // this是QMainWindow的指针
    cancelWindow->exec();  // 使用exec()来显示弹出窗口
}

// 收件箱
void MyOrders::openInbox() {
    inboxWindow2 *inboxWindow = new inboxWindow2(this);
    inboxWindow->setWindowFlags(Qt::Window);  // 设置为新窗口
    inboxWindow->show();
}

void MyOrders::removeOrderFromDepartureList(const QString &orderID) {
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->listView_departure->model());
    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            QModelIndex index = model->index(row, 0);
            if (index.data().toString() == orderID) {
                model->removeRow(row);
                break;
            }
        }
    }
}

// 订单取消后，移除订单
void MyOrders::onOrderCanceled(const QString &orderID)
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->listView_departure->model());
    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            QModelIndex index = model->index(row, 0);  // 假设订单编号在第一列
            if (index.data().toString() == orderID) {
                model->removeRow(row);  // 从模型中移除对应的行
                break;
            }
        }
    }
}
