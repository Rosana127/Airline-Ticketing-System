#include "seatsselectpage.h"
#include "ui_seatsselectpage.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

SeatsSelectPage::SeatsSelectPage(Database *db, QWidget *parent)
    : QWidget(parent), ui(new Ui::SeatsSelectPage), dbcon(db) {
    ui->setupUi(this);

    // 检查数据库连接
    if (!dbcon || !dbcon->getDatabase().isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }
    qDebug() << "Database connected successfully!";


    // 连接加载座位按钮的点击信号

    connect(ui->loadSeatsButton, &QPushButton::clicked, this, &SeatsSelectPage::on_loadSeatsButton_clicked);
}

SeatsSelectPage::~SeatsSelectPage() {
    delete ui;
}

void SeatsSelectPage::on_loadSeatsButton_clicked() {
    QString orderID = ui->orderIDEdit->text().trimmed();
    if (orderID.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入订单号！");
        return;
    }

    QString flightNumber = ui->flightNumberEdit->text().trimmed();
    if (flightNumber.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入航班号！");
        return;
    }

    qDebug() << "Loading seats for OrderID:" << orderID << "and FlightNumber:" << flightNumber;
    loadSeats(flightNumber, orderID);
}

void SeatsSelectPage::loadSeats(const QString &flightNumber, const QString &orderID) {
    // 检查是否已经选择了座位
    QSqlQuery checkSeatQuery(dbcon->getDatabase());
    checkSeatQuery.exec("USE flightdb");
    checkSeatQuery.prepare("SELECT Seat FROM ordertable WHERE OrderID = ?");
    checkSeatQuery.addBindValue(orderID);


    if (!checkSeatQuery.exec()) {
        qDebug() << "Query failed: " << checkSeatQuery.lastError().text();
        return;
    }
    qDebug()<<checkSeatQuery.lastQuery();
    qDebug() << "OrderID:" << orderID;  // 打印绑定的参数值
    if (checkSeatQuery.next()) {
        QString selectedSeat = checkSeatQuery.value(0).toString();
        if (!selectedSeat.isEmpty() ) {
            if (!seatSelectionMessageShown) {
                QMessageBox::warning(this, "座位已预定", "你已经选过座位了");
                seatSelectionMessageShown = true;
            }
            return;
        }
    }

    QGridLayout *seatLayout = qobject_cast<QGridLayout*>(ui->seatLayoutWidget->layout());
    if (!seatLayout) {
        seatLayout = new QGridLayout();
        ui->seatLayoutWidget->setLayout(seatLayout);
    }

    // 清空现有布局
    while (seatLayout->count()) {
        QLayoutItem *item = seatLayout->takeAt(0);
        delete item->widget();
        delete item;
    }

    // 查询订单的TicketType
    QString ticketType;
    QSqlQuery query(dbcon->getDatabase());
    query.exec("USE flightdb");
    query.prepare("SELECT TicketType FROM ordertable WHERE OrderID = ?");
    query.addBindValue(orderID);

    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
        return;
    }

    if (query.next()) {
        ticketType = query.value(0).toString();
    } else {
        qDebug() << "No order found with the given OrderID.";
        return;
    }

    // 根据TicketType过滤座位
    QStringList seatTypes = filterSeatsByTicketType(ticketType);

    // 查询座位数据
    query.prepare("SELECT SeatRow, SeatColumn, SeatNumber, IsBooked, SeatType FROM seats WHERE FlightNumber = ?");
    query.addBindValue(flightNumber);

    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
        return;
    }

    // 动态生成座位按钮
    while (query.next()) {
        QString seatType = query.value(4).toString();
        if (seatTypes.contains(seatType)) {
            int row = query.value(0).toInt();
            QString columnStr = query.value(1).toString();
            QString seatNumber = query.value(2).toString();
            bool isBooked = query.value(3).toBool();

            QPushButton *button = new QPushButton(seatNumber);
            if (isBooked) {
                button->setStyleSheet("background-color: red;");
                button->setEnabled(false);
            } else {
                button->setStyleSheet(seatType == "A" ? "background-color: gold;" :
                                          seatType == "B" ? "background-color: lightblue;" :
                                          seatType == "C" ? "background-color: lightgreen;" :
                                          "background-color: lightgray;");
            }

            connect(button, &QPushButton::clicked, this, [this, flightNumber, seatNumber, button]() {
                handleSeatSelection(flightNumber, seatNumber, button);
            });

            seatLayout->addWidget(button, row, columnStr[0].toLatin1() - 'A');
        }
    }
}

QStringList SeatsSelectPage::filterSeatsByTicketType(const QString &ticketType) {
    QStringList seatTypes;
    if (ticketType == "经济舱") {
        seatTypes << "C";
    } else if (ticketType == "商务舱") {
        seatTypes << "B";
    } else if (ticketType == "头等舱") {
        seatTypes << "A";
    } else {
        // 如果TicketType未知，则展示所有类型的座位
        seatTypes << "A" << "B" << "C";
    }
    return seatTypes;
}

// 新增函数，用于禁用所有座位按钮
void SeatsSelectPage::disableAllSeatsButtons() {
    QGridLayout *seatLayout = qobject_cast<QGridLayout*>(ui->seatLayoutWidget->layout());
    if (seatLayout) {
        for (int i = 0; i < seatLayout->count(); ++i) {
            QLayoutItem *item = seatLayout->itemAt(i);
            if (item && item->widget() && qobject_cast<QPushButton*>(item->widget())) {
                QPushButton *button = qobject_cast<QPushButton*>(item->widget());
                button->setEnabled(false);
            }
        }
    }
}


void SeatsSelectPage::handleSeatSelection(const QString &flightNumber, const QString &seatNumber, QPushButton *button) {
    QSqlQuery checkQuery(dbcon->getDatabase());
    checkQuery.exec("USE flightdb");
    checkQuery.prepare("SELECT IsBooked FROM seats WHERE FlightNumber = ? AND SeatNumber = ?");
    checkQuery.addBindValue(flightNumber);
    checkQuery.addBindValue(seatNumber);



    if (!checkQuery.exec()) {
        qDebug() << "Query failed: " << checkQuery.lastError().text();
        return;
    }



    if (checkQuery.next() && checkQuery.value(0).toBool()) {
        if (!seatSelectionMessageShown) {
            QMessageBox::warning(this, "座位已预定", "该座位已被预定，请选择其他座位！");
            seatSelectionMessageShown = true;
        }
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认选择", "是否确认选择此座位：" + seatNumber + "?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QSqlQuery updateQuery(dbcon->getDatabase());
        updateQuery.exec("USE flightdb");
        updateQuery.prepare("UPDATE seats SET IsBooked = 1 WHERE FlightNumber = ? AND SeatNumber = ?");
        updateQuery.addBindValue(flightNumber);
        updateQuery.addBindValue(seatNumber);

        if (!updateQuery.exec()) {
            qDebug() << "Update failed: " << updateQuery.lastError().text();
        } else {
            button->setStyleSheet("background-color: red;");
            button->setEnabled(false);

            // 禁用所有座位按钮
            disableAllSeatsButtons();

            // 获取用户输入的订单号
            QString orderID = ui->orderIDEdit->text();
            if (!orderID.isEmpty()) {
                updateOrderSeat(orderID, seatNumber);
            }
        }
    }
}


void SeatsSelectPage::updateOrderSeat(const QString &orderID, const QString &seatNumber) {
    QSqlQuery updateOrderQuery(dbcon->getDatabase());
    updateOrderQuery.exec("USE flightdb");
    updateOrderQuery.prepare("UPDATE ordertable SET Seat = ? WHERE OrderID = ?");
    updateOrderQuery.addBindValue(seatNumber);
    updateOrderQuery.addBindValue(orderID);

    if (!updateOrderQuery.exec()) {
        qDebug() << "Update order failed: " << updateOrderQuery.lastError().text();
    } else {
        qDebug() << "Order seat updated successfully.";
    }
}
