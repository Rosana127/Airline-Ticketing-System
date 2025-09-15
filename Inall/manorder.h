#ifndef MANORDER_H
#define MANORDER_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QInputDialog>

namespace Ui {
class ManOrder;
}

class ManOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManOrder(QWidget *parent = nullptr);
    ~ManOrder();

private slots:
    void on_flightTableView_clicked(const QModelIndex &index);  // 处理选择航班
    void on_changeGateButton_clicked();  // 处理更改登机口按钮点击

private:
    Ui::ManOrder *ui;
    void connectToDatabase();  // 连接数据库
    void loadFlightData();  // 加载航班信息
    void updateGateInfo(const QString &flightNumber, const QString &newGate);  // 更新登机口
    QStandardItemModel* createModel();  // 创建表格模型
};

#endif // MANORDER_H
