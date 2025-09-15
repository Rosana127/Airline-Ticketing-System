#include "manorder.h"  // 修改为 ManOrder 的头文件
#include "ui_manorder.h"  // 修改为 Ui::ManOrder

#include <QSqlQuery>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>

ManOrder::ManOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManOrder)  // 修改为 Ui::ManOrder
{
    ui->setupUi(this);

//    connectToDatabase();
    loadFlightData();

    // 设置 tableView 为单行选择模式，并选择整行
    ui->flightTableView->setSelectionMode(QAbstractItemView::SingleSelection);  // 单行选择模式
    ui->flightTableView->setSelectionBehavior(QAbstractItemView::SelectRows);    // 选择整行

    // 连接 clicked 信号来捕获用户选择的航班
    connect(ui->flightTableView, &QTableView::clicked, this, &ManOrder::on_flightTableView_clicked);  // 修改为 ManOrder::on_flightTableView_clicked
}

ManOrder::~ManOrder()
{
    delete ui;
}

// 连接到数据库
void ManOrder::connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("flight");  // 请替换为实际数据库名称

    if (!db.open()) {
        qDebug() << "Error: unable to connect to database";
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "Connected to database!";
    }
}

// 创建表格模型
QStandardItemModel* ManOrder::createModel() {  // 修改为 ManOrder::createModel
    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({ "航班号", "舱位", "登机口" });
    return model;
}

// 加载航班数据
void ManOrder::loadFlightData() {  // 修改为 ManOrder::loadFlightData
    QSqlQuery query("SELECT FlightNumber, SeatType, DepartureGate FROM flightinfo");
    QStandardItemModel* model = createModel();

    while (query.next()) {
        QString flightNumber = query.value(0).toString();
        QString seatType = query.value(1).toString();
        QString departureGate = query.value(2).toString();

        QList<QStandardItem*> row;
        row.append(new QStandardItem(flightNumber));
        row.append(new QStandardItem(seatType));
        row.append(new QStandardItem(departureGate));

        model->appendRow(row);
    }

    ui->flightTableView->setModel(model);
}

// 处理表格中的行点击事件
void ManOrder::on_flightTableView_clicked(const QModelIndex &index) {  // 修改为 ManOrder::on_flightTableView_clicked
    // 获取选中行的航班号、舱位和登机口
    QString flightNumber = index.sibling(index.row(), 0).data().toString();  // 第0列是航班号
    QString seatType = index.sibling(index.row(), 1).data().toString();      // 第1列是舱位
    QString departureGate = index.sibling(index.row(), 2).data().toString();  // 第2列是登机口

    // 显示选中的航班信息在标签上
    ui->selectedFlightLabel->setText("航班号: " + flightNumber + "    舱位: " + seatType + "    登机口: " + departureGate);
}

// 处理“更改登机口”按钮点击事件
void ManOrder::on_changeGateButton_clicked() {  // 修改为 ManOrder::on_changeGateButton_clicked
    // 获取当前选中的航班号
    QModelIndexList selectedIndexes = ui->flightTableView->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "选择航班", "请先选择一个航班！");
        return;
    }

    QString flightNumber = selectedIndexes.first().sibling(selectedIndexes.first().row(), 0).data().toString();
    QString oldGate = selectedIndexes.first().sibling(selectedIndexes.first().row(), 2).data().toString();

    // 弹出输入框，提示管理员输入新的登机口
    bool ok;
    QString newGate = QInputDialog::getText(this, "更改登机口", "请输入新的登机口：", QLineEdit::Normal, oldGate, &ok);

    if (ok && !newGate.isEmpty()) {
        // 更新数据库中的登机口信息
        updateGateInfo(flightNumber, newGate);
    }
}

// 更新数据库中的登机口信息
void ManOrder::updateGateInfo(const QString &flightNumber, const QString &newGate) {  // 修改为 ManOrder::updateGateInfo
    QSqlQuery query;
    query.prepare("UPDATE flightinfo SET DepartureGate = :newGate WHERE FlightNumber = :flightNumber");
    query.bindValue(":newGate", newGate);
    query.bindValue(":flightNumber", flightNumber);

    if (query.exec()) {
        // 成功更新后重新加载数据并显示提示
        loadFlightData();
        QMessageBox::information(this, "成功", "登机口信息已更新！");
    } else {
        QMessageBox::critical(this, "错误", "更新登机口失败！\n" + query.lastError().text());
    }
}
