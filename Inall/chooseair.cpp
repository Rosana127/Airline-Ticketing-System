#include "chooseair.h"
#include "ui_chooseair.h"
#include"qcustomcalendarwidget.h"
#include"flisingle.h"
#include"global.h"
#include"database.h"
chooseAir::chooseAir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseAir)
{
    ui->setupUi(this);

        // 连接数据库
        QSqlQuery query;
        query.exec("USE flightdb");


        // 创建departbutton下拉菜单
        QToolButton *toolButton = ui->departbutton;
        QMenu *menuDeparure = new QMenu(toolButton);
        toolButton->setText(departPlace);

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

        // 执行 SQL 查询，去重并读取 "DepartureCity" 列的内容
        query.exec("SELECT DISTINCT DepartureCity FROM flightinfo");

        // 遍历查询结果，将去重后的城市名加入菜单项
        while (query.next()) {
            QString city = query.value(0).toString();  // 获取 "DepartureCity" 列的值
            QAction *action = new QAction(city, this);
            menuDeparure->addAction(action);

            // 为每个菜单项连接一个槽函数，点击时设置 QToolButton 的文本
            connect(action, &QAction::triggered, this, [city, toolButton]() {
                toolButton->setText(city);  // 将选择的城市设置为 toolbutton 的文本
                departPlace = city;  // 更新全局变量
            });
        }
        toolButton->setMenu(menuDeparure);
        toolButton->setPopupMode(QToolButton::InstantPopup);

        // 创建arrivalbutton下拉菜单
        QToolButton *toolButton2 = ui->arrivalbutton;
        toolButton2->setText(arrivalPlace);
        QMenu *menuArrival = new QMenu(toolButton2);

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

        // 遍历查询结果，将去重后的城市名加入菜单项
        while (query.next()) {
            QString city = query.value(0).toString();  // 获取 "ArrivalCity" 列的值

            QAction *action = new QAction(city, this);
            menuArrival->addAction(action);

            // 为每个菜单项连接一个槽函数，点击时设置 QToolButton 的文本
            connect(action, &QAction::triggered, this, [city, toolButton2]() {
                toolButton2->setText(city);  // 将选择的城市设置为 toolbutton 的文本
                arrivalPlace = city;  // 更新全局变量
            });
        }
        toolButton2->setMenu(menuArrival);
        toolButton2->setPopupMode(QToolButton::InstantPopup);

        //日历图标绘制
        QDateTimeEdit *dateEdit = ui->dateEdit;
        dateEdit->setDate(selectedDate);
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
                selectedDate=data;
            });
    myshow();
}


chooseAir::~chooseAir()
{
    delete ui;
}

//void chooseAir::myshow(){
//    QWidget *w =ui->scrollArea->widget();
//    QVBoxLayout *v = new QVBoxLayout(w);
//    flisingle* tmp=new flisingle("海南航空","大机型","HU7818","武汉天河机场T1","浦东国际机场T2","2019-06-07 10:07:35","2019-06-07 12:07:37","570",w);
//    v->addWidget(tmp);
//    tmp=new flisingle("北京航空","大机型","HU7818","武汉天河机场T1","浦东国际机场T2","2019-06-07 10:07:35","2019-06-07 12:07:37","570",w);
//    v->addWidget(tmp);
////    ui->scrollArea->setWidgetResizable(true);
////    ui->scrollArea->setWidget(w);

//// 3. 将所有的按钮添加到 垂直布局当中
////    QList<flisingle*> ret=searchFlightsFromDatabase(departPlace,arrivalPlace,selectedDate);

////    for(auto tmp:ret){
////        v->addWidget(tmp);
////        tmp->setParent(w);
////}

//}
void chooseAir::myshow() {
    QWidget *w = ui->scrollArea->widget();
    // 添加新的 flisingle
    QList<flisingle*> ret=searchFlightsFromDatabase(departPlace,arrivalPlace,selectedDate);
    w->setFixedHeight(ret.size()*flisingleHeight);
if(ret.size()>0 )  this->hide();
    for(int i=0;i<ret.size();i++){
        ret[i]->setParent(w);
        ret[i]->move(0,flisingleHeight*i);
         connect(ret[i], &flisingle::hidePage, this, &chooseAir::hideSelf);
    }
}

QList<flisingle*> searchFlightsFromDatabase(const QString &departPlace, const QString &arrivalPlace, const QDate &selectedDate) {
    QList<flisingle*> resultList;
     qDebug()<<"myshow传参"<<departPlace<<arrivalPlace<<selectedDate;
     QSet<QString> seenFlightNumbers;  // 用于去重的 QSet

    // 连接数据库
    QSqlQuery query;
    if (!query.exec("USE flightdb")) {
        qDebug() << "Failed to select database: " << query.lastError().text();
        return resultList;
    }else {
        qDebug() << "Database selected: myflight";
    }

    // 编写 SQL 查询语句
    // 假设 DepartureTime 存储为 'yyyy-MM-dd HH:mm:ss' 格式
    QString queryStr = QString("SELECT FlightNumber, AirlineCompany, ArrivalCity, DepartureCity, AircraftModel, "
                               "DepartureAirport, ArrivalAirport, IsDelayed, Date, DepartureTime, ArrivalTime, "
                               "Price FROM flightinfo WHERE DepartureCity = '%1' AND ArrivalCity = '%2' "
                               "AND Date = '%3'")
                               .arg(departPlace).arg(arrivalPlace).arg(selectedDate.toString("yyyy-MM-dd"));
    qDebug() << "Executing query: " << queryStr;  // 打印生成的 SQL 查询语句
    qDebug()<<departPlace<<arrivalPlace<<selectedDate.toString(("yyyy-MM-dd"));
    // 执行查询
    if (!query.exec(queryStr)) {
        qDebug() << "Query execution failed: " << query.lastError().text();
        return resultList;
    }

int rowCount = 0;
    // 遍历查询结果并创建 flisingle 对象
    while (query.next()) {
        QString flightNumber = query.value("FlightNumber").toString();

        // 如果已经出现过该航班号，则跳过
        if (seenFlightNumbers.contains(flightNumber)) {
            continue;
        }

        QString airlineCompany = query.value("AirlineCompany").toString();
        QString arrivalCity = query.value("ArrivalCity").toString();
        QString departureCity = query.value("DepartureCity").toString();
        QString aircraftModel = query.value("AircraftModel").toString();
        QString departureAirport = query.value("DepartureAirport").toString();
        QString arrivalAirport = query.value("ArrivalAirport").toString();
        QString isDelayed = query.value("IsDelayed").toString();
        QString date = query.value("Date").toString();
        QString departureTime = query.value("DepartureTime").toString().mid(11, 8);  // 从索引11开始，取8个字符
        QString arrivalTime = query.value("ArrivalTime").toString().mid(11, 8);  // 从索引11开始，取8个字符
        price=query.value("Price").toString();

        // 创建 flisingle 对象并添加到结果列表
        flisingle *tmp = new flisingle(airlineCompany, aircraftModel, flightNumber,
                                       departureAirport, arrivalAirport, departureTime,
                                       arrivalTime, price);

        resultList.append(tmp);
        seenFlightNumbers.insert(flightNumber);  // 添加航班号到 QSet 中，避免重复
        rowCount++;
    }
    if (rowCount == 0) {
        qDebug() << "No results found for the query.";
        QMessageBox::information(nullptr, "No Flights Found", "对不起，不存在该批次的航班！");
    } else {
        qDebug() << "Found " << rowCount << " results.";
    }

    return resultList;
}

void chooseAir::on_sousuo_clicked()
{
//    this->hide();
    chooseAir *chooseAirWindow = new chooseAir();
    chooseAirWindow->resize(static_cast<int>(widthq), static_cast<int>(heightq));
    homepagemain->addWidget(chooseAirWindow);
    homepagemain->setCurrentIndex(homepagemain->count() - 1);
}
void chooseAir::hideSelf() {
    this->hide(); // 隐藏整个页面
}
