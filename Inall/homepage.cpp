#include "homepage.h" // 注意这里也要更改
#include "ui_homepage.h" // 注意这里也要更改
#include "userinfopage.h"
#include "seatsselectpage.h"
#include "global.h"
#include "myticket.h"  // 引入myticket界面类
#include <QMessageBox>
#include <QMenu>
#include <QWidgetAction>
#include <QPushButton>
#include <QAction>
#include <QCursor>
#include <QDebug>
#include <QEvent>
#include <QLabel>
#include"inquire.h"
#include"login.h"
#include"inboxwindow2.h"
HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage) // 注意这里也要更改
{
    ui->setupUi(this);
    this->showMaximized();

    // 创建数据库连接
    Database* db = &Database::instance();
    db->connectToDatabase();

//    // 默认显示值机选座页面
//    SeatsSelectPage *seatsSelectPage = new SeatsSelectPage(db, this);  // 传递数据库对象
//    ui->stackedWidget->addWidget(seatsSelectPage);
//    ui->stackedWidget->setCurrentIndex(0);  // 设置默认显示页面

    // 连接按钮事件
//    connect(ui->searchFlightButton, &QPushButton::clicked, this, &HomePage::onSearchFlightClicked); // 注意这里也要更改
    connect(ui->seatsSelectButton, &QPushButton::clicked, this, &HomePage::onSeatsSelectClicked); // 注意这里也要更改
    connect(ui->myOrdersButton, &QPushButton::clicked, this, &HomePage::on_myOrdersButton_clicked); // 注意这里也要更改
    connect(ui->pushButton, &QPushButton::clicked, this, &HomePage::on_pushButton_clicked); // 注意这里也要更改
    // 点击按钮，弹出收件箱
//    connect(ui->inboxButton, &QPushButton::clicked, this, &MyOrders::openInbox);

    homepagemain=   ui->stackedWidget;
    inquire* tmp=new inquire();
    homepagemain->addWidget(tmp);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
    // 创建悬浮菜单
    QMenu *menu = new QMenu(this);

    // 创建“登录”和“退出”菜单项
    QAction *loginAction = new QAction("登录                                ", this);
    QAction *logoutAction = new QAction("退出                                ", this);

    // 设置菜单项字体
    QFont font("Microsoft YaHei");
    font.setPointSize(18);  // 设置字体大小

    loginAction->setFont(font);
    logoutAction->setFont(font);

    // 将菜单项添加到菜单中
    menu->addAction(loginAction);
    menu->addAction(logoutAction);




    // 设置 QLabel 的光标为手形光标
    //ui->userLabel->setStyleSheet("font-size: 16px; color: blue;");
    ui->userLabel->setStyleSheet(
        "QLabel {"
        "background: rgba(85, 170, 255, 0);"
        "color: white;"
        "font-family: 'MingLiU-ExtB';"
        "font-size: 32px;"  /* 提高字体大小 */
        "text-align: center;"  /* 居中对齐文字 */
        "}"
        );
    ui->userLabel->setCursor(Qt::PointingHandCursor);

    // 将 eventFilter 安装到 QLabel 上
    ui->userLabel->installEventFilter(this);

    // 连接菜单项点击事件
    connect(loginAction, &QAction::triggered, this, &HomePage::onLoginClicked); // 注意这里也要更改
    connect(logoutAction, &QAction::triggered, this, &HomePage::onLogoutClicked); // 注意这里也要更改

    // 用于保存 menu 对象的指针
    this->menu = menu;

}

bool HomePage::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->userLabel) {
        if (event->type() == QEvent::Enter) {
            ui->userLabel->setStyleSheet(
                "QLabel {"
                "color: black;"
                "font-family: 'Microsoft YaHei';"
                "font-size: 32px;"  /* 提高字体大小 */
                "text-align: center;"  /* 居中对齐文字 */
                "}"
                );
            // 鼠标进入时，显示菜单
            QPoint pos = ui->userLabel->mapToGlobal(ui->userLabel->rect().bottomLeft());
            menu->move(pos);
            menu->resize(ui->userLabel->size());
            menu->show();
        } else if (event->type() == QEvent::Leave) {
            // 鼠标离开时，隐藏菜单
            ui->userLabel->setStyleSheet(
                "QLabel {"
                "color: white;"
                "font-family: 'Microsoft YaHei';"
                "font-size: 32px;"  /* 提高字体大小 */
                "text-align: center;"  /* 居中对齐文字 */
                "}"
                );
            menu->hide();
        }
    }

    // 传递事件
    return QMainWindow::eventFilter(watched, event);
}

HomePage::~HomePage()
{
    delete ui;
}

//void HomePage::onSearchFlightClicked()
//{
//    // TODO: 实现航班查询界面逻辑
//    inquire* tmp=new inquire();
//    tmp->show();
//    //    QMessageBox::information(this, "航班查询", "航班查询功能");
//}

void HomePage::on_myOrdersButton_clicked()
{
    // 显示 myTicket 页面
    Database* db = &Database::instance();  // 获取数据库实例
    myTicket *ticketWindow = new myTicket(this);
   // myticket12 *ticketWindow = new myticket12(this);
    ui->stackedWidget->addWidget(ticketWindow );
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);

}

void HomePage::on_pushButton_clicked()
{
    // 显示 收信 页面
    Database* db = &Database::instance();  // 获取数据库实例
    inboxWindow2 *inboxWindow = new inboxWindow2(this);
    ui->stackedWidget->addWidget(inboxWindow );
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);

}

// // 收件箱
// void MyOrders::openInbox() {
//     InboxWindow *inboxWindow = new InboxWindow(this);
//     inboxWindow->setWindowFlags(Qt::Window);  // 设置为新窗口
//     inboxWindow->show();
// }


void HomePage::onSeatsSelectClicked()
{
    // 切换到值机选座页面
    Database* db = &Database::instance();  // 获取数据库实例
    SeatsSelectPage *seatsSelectPage = new SeatsSelectPage(db, this);
    ui->stackedWidget->addWidget(seatsSelectPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
}

void HomePage::onLoginClicked() {

    // 创建managerLogin窗口
    Login *mainwindow = new Login();  // 设置父窗口为this，即MainWindow



    //loginWindow->showFullScreen();

    // 显示managerLogin窗口
    mainwindow->show();
    // 隐藏当前主窗口（如果需要）
    this->hide();
}

void HomePage::onLogoutClicked() {
    QMessageBox::information(this, "提示", "退出功能");
    QApplication::quit(); // 关闭程序
}

void HomePage::on_pushButton_2_clicked()
{
    Database* db = &Database::instance();  // 获取数据库实例
    UserInfoPage *userInfoPage = new UserInfoPage(db,g_userName, this);
    ui->stackedWidget->addWidget(userInfoPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);

}


void HomePage::on_searchFlightButton_clicked()
{
    inquire *userInfoPage = new inquire( this);
    ui->stackedWidget->addWidget(userInfoPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
}


