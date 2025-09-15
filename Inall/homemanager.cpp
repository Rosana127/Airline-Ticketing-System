#include "homemanager.h"
#include "ui_homemanager.h"
#include"flight_add2.h"
#include"flight_change.h"
#include"flight_delete.h"
#include"managerticket.h"
#include"database.h"
#include<QMenu>
#include"login.h"
#include"global.h"
#include<QMainWindow>
homemanager::homemanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homemanager)
{
    ui->setupUi(this);
    this->showMaximized();

//    // 创建数据库连接
    Database* db = &Database::instance();
    db->connectToDatabase();
    homemanagermain=   ui->stackedWidget;
    flight_add2* tmp=new flight_add2();
    homemanagermain->addWidget(tmp);
    homemanagermain->setCurrentIndex(homemanagermain->count() - 1);
//    QMenu *menu = new QMenu(this);

//    // 创建“登录”和“退出”菜单项
//    QAction *loginAction = new QAction("登录                                ", this);
//    QAction *logoutAction = new QAction("退出                                ", this);

//    // 设置菜单项字体
//    QFont font("Microsoft YaHei");
//    font.setPointSize(18);  // 设置字体大小

//    loginAction->setFont(font);
//    logoutAction->setFont(font);

//    // 将菜单项添加到菜单中
//    menu->addAction(loginAction);
//    menu->addAction(logoutAction);

//    homemanagermain=  ui->stackedWidget;



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

//    // 将 eventFilter 安装到 QLabel 上
//    ui->userLabel->installEventFilter(this);

//    // 连接菜单项点击事件
//    connect(loginAction, &QAction::triggered, this, &homemanager::onLoginClicked); // 注意这里也要更改
//    connect(logoutAction, &QAction::triggered, this, &homemanager::onLogoutClicked); // 注意这里也要更改
}
//bool homemanager::eventFilter(QObject *watched, QEvent *event)
//{
//    if (watched == ui->userLabel) {
//        if (event->type() == QEvent::Enter) {
//            ui->userLabel->setStyleSheet(
//                "QLabel {"
//                "color: black;"
//                "font-family: 'Microsoft YaHei';"
//                "font-size: 32px;"  /* 提高字体大小 */
//                "text-align: center;"  /* 居中对齐文字 */
//                "}"
//                );
//            // 鼠标进入时，显示菜单
//            QPoint pos = ui->userLabel->mapToGlobal(ui->userLabel->rect().bottomLeft());
//            menu->move(pos);
//            menu->resize(ui->userLabel->size());
//            menu->show();
//        } else if (event->type() == QEvent::Leave) {
//            // 鼠标离开时，隐藏菜单
//            ui->userLabel->setStyleSheet(
//                "QLabel {"
//                "color: white;"
//                "font-family: 'Microsoft YaHei';"
//                "font-size: 32px;"  /* 提高字体大小 */
//                "text-align: center;"  /* 居中对齐文字 */
//                "}"
//                );
//            menu->hide();
//        }
//    }

//    // 传递事件
//    return QWidget::eventFilter(watched, event);
//}

homemanager::~homemanager()
{
    delete ui;
}

void homemanager::on_searchFlightButton_clicked()
{
    flight_add2 *userInfoPage = new flight_add2( this);
    ui->stackedWidget->addWidget(userInfoPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
}
void homemanager::onLoginClicked() {

    // 创建managerLogin窗口
    Login *mainwindow = new Login(this);  // 设置父窗口为this，即MainWindow



    //loginWindow->showFullScreen();

    // 显示managerLogin窗口
    mainwindow->show();
    // 隐藏当前主窗口（如果需要）
    this->hide();
}

void homemanager::onLogoutClicked() {
    QMessageBox::information(this, "提示", "退出功能");
    QApplication::quit(); // 关闭程序
}
void homemanager::on_myOrdersButton_clicked()
{
    flight_delete *userInfoPage = new flight_delete( this);
    ui->stackedWidget->addWidget(userInfoPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
}

void homemanager::on_seatsSelectButton_clicked()
{
    flight_change *userInfoPage = new flight_change( this);
    ui->stackedWidget->addWidget(userInfoPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
}

void homemanager::on_pushButton_2_clicked()
{
    managerticket *userInfoPage = new managerticket();
    ui->stackedWidget->addWidget(userInfoPage);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
}

void homemanager::on_pushButton_clicked()
{
    // 创建managerLogin窗口
    Login *mainwindow = new Login();  // 设置父窗口为this，即MainWindow
    //loginWindow->showFullScreen();

    // 显示managerLogin窗口
    mainwindow->show();
    // 隐藏当前主窗口（如果需要）
    this->hide();
}
