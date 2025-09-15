#include "inquire.h"
#include "ui_inquire.h"
#include"qcustomcalendarwidget.h"
#include<QDateTimeEdit>
#include"flight_delete.h"
#include"chooseair.h"
#include"flight_change.h"
#include"global.h"
inquire::inquire(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inquire)
{
    ui->setupUi(this);

    //连接数据库
    QSqlQuery query;
    query.exec("USE flightdb");


    //创建toolbutton下拉菜单
    QToolButton *toolButton = ui->departbutton;
    QMenu *menuDeparure = new QMenu(toolButton);
    menuDeparure->setFixedWidth(160);
    menuDeparure->setStyleSheet(
        "QMenu {"
        "    font-family: 'Microsoft YaHei';"
        "    font-size: 14px;"
        "    border: 1px solid gray;"    // 边框颜色
        "    background-color: white;"  // 背景颜色
        "}"
        "QMenu::item {"
        "    padding: 8px 20px;"         // 菜单项内边距
        "    color: black;"              // 菜单项字体颜色
        "}"
        "QMenu::item:selected {"
        "    background-color: #E2E4E5;" // 菜单项选中效果
        "    color: blue;"               // 选中文字颜色
        "}"
        );


    // 执行 SQL 查询，去重并读取 "ArrivalCity" 列的内容
    query.exec("SELECT DISTINCT DepartureCity FROM flightinfo");
    if (query.next()) {
        QString firstCity = query.value(0).toString();  // 获取第一个城市
        toolButton->setText(firstCity);  // 设置 QToolButton 的文本为第一个城市
        QAction *action = new QAction(firstCity, this);
        menuDeparure->addAction(action);

        // 为每个菜单项连接一个槽函数，点击时设置 QToolButton 的文本
        connect(action, &QAction::triggered, this, [firstCity, toolButton]() {
            toolButton->setText(firstCity);  // 将选择的城市设置为 toolbutton 的文本
        });
    }


    // 遍历查询结果，将去重后的城市名加入菜单项
    while (query.next()) {
        QString city = query.value(0).toString();  //

        QAction *action = new QAction(city, this);
        menuDeparure->addAction(action);

        // 为每个菜单项连接一个槽函数，点击时设置 QToolButton 的文本
        connect(action, &QAction::triggered, this, [city, toolButton]() {
            toolButton->setText(city);  // 将选择的城市设置为 toolbutton 的文本
        });
    }
    toolButton->setMenu(menuDeparure);
    toolButton->setPopupMode(QToolButton::InstantPopup);




    //创建toolbutton下拉菜单
    QToolButton *toolButton2 = ui->arrivalbutton;
    QMenu *menuArrival = new QMenu(toolButton2);

    // 设置固定宽度（例如 150 像素）
    menuArrival->setFixedWidth(160);
    menuArrival->setStyleSheet(
        "QMenu {"
        "    font-family: 'Microsoft YaHei';"
        "    font-size: 14px;"
        "    border: 1px solid gray;"    // 边框颜色
        "    background-color: white;"  // 背景颜色
        "}"
        "QMenu::item {"
        "    padding: 8px 20px;"         // 菜单项内边距
        "    color: black;"              // 菜单项字体颜色
        "}"
        "QMenu::item:selected {"
        "    background-color: #E2E4E5;" // 菜单项选中效果
        "    color: blue;"               // 选中文字颜色
        "}"
        );

    query.exec("SELECT DISTINCT ArrivalCity FROM flightinfo");
    // 判断查询是否有结果
    if (query.next()) {
        QString firstCity = query.value(0).toString();  // 获取第一个城市
        toolButton2->setText(firstCity);  // 设置 QToolButton 的文本为第一个城市
        QAction *action = new QAction(firstCity, this);
        menuArrival->addAction(action);

        // 为每个菜单项连接一个槽函数，点击时设置 QToolButton 的文本
        connect(action, &QAction::triggered, this, [firstCity, toolButton2]() {
            toolButton2->setText(firstCity);  // 将选择的城市设置为 toolbutton 的文本
        });
    }


    // 遍历查询结果，将去重后的城市名加入菜单项
    while (query.next()) {
        QString city = query.value(0).toString();  // 获取 "ArriveCity" 列的值

        QAction *action = new QAction(city, this);
        menuArrival->addAction(action);

        // 为每个菜单项连接一个槽函数，点击时设置 QToolButton 的文本
        connect(action, &QAction::triggered, this, [city, toolButton2]() {
            toolButton2->setText(city);  // 将选择的城市设置为 toolbutton 的文本
        });
    }
    toolButton2->setMenu(menuArrival);
    toolButton2->setPopupMode(QToolButton::InstantPopup);


//    connect(swapButton, &QPushButton::clicked, this, &inquire::swapLocations);



    //日历图标绘制
    QDateTimeEdit *dateEdit = ui->dateEdit;
        QCustomCalendarWidget* calendarWidget = new QCustomCalendarWidget(this);
        dateEdit->setCalendarPopup(true);  // 日历弹出


        dateEdit->setCalendarWidget(calendarWidget);
        dateEdit->setMinimumDate(QDate::currentDate().addDays(-45));  // 0天
        dateEdit->setMaximumDate(QDate::currentDate().addDays(365));  // +365天
        dateEdit->setContextMenuPolicy(Qt::NoContextMenu);
//        dateEdit->setFixedSize(191,61);
        dateEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        calendarWidget->disconnect(SIGNAL(selectionChanged()));
        calendarWidget->disconnect(SIGNAL(clicked(QDate)));

        connect(calendarWidget, &QCustomCalendarWidget::signalSetCalendarTime, [dateEdit](const QDate& data){
            dateEdit->setDate(data);
        });

    //搜索逻辑设置
    connect(ui->sousuo, &QPushButton::clicked, this, &inquire::on_swapbutton_clicked);



}
void inquire::on_swapbutton_clicked() {
    // 隐藏当前界面
//    flisingle* tmp=new flisingle("海南航空","大机型","HU7818","武汉天河机场T1","浦东国际机场T2","2019-06-07 10:07:35","2019-06-07 12:07:37","570",this);
//    tmp->show();
//    flight_add2* tmp=new flight_add2();
//    flight_delete* tmp=new flight_delete();
//      flight_change* tmp=new flight_change();
//    tmp->show();

    // 创建并显示目标界面 chooseAir
    departPlace=ui->departbutton->text();
    arrivalPlace=ui->arrivalbutton->text();
    selectedDate = ui->dateEdit->date();
    QList<flisingle*> ret=searchFlightsFromDatabase(departPlace,arrivalPlace,selectedDate);
    if(!ret.empty()){
        this->hide();
        chooseAir *chooseAirWindow = new chooseAir();  // 创建 chooseAir 窗口实例
        chooseAirWindow->resize(static_cast<int>(widthq), static_cast<int>(heightq));
        homepagemain->addWidget(chooseAirWindow);
        homepagemain->setCurrentIndex(homepagemain->count() - 1);
    }
}


inquire::~inquire()
{
    delete ui;
}

