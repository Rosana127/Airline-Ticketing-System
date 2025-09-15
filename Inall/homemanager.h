#ifndef HOMEMANAGER_H
#define HOMEMANAGER_H
#include<QMenu>
#include <QWidget>

namespace Ui {
class homemanager;
}

class homemanager : public QWidget
{
    Q_OBJECT

public:
    explicit homemanager(QWidget *parent = nullptr);
    ~homemanager();
//    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_searchFlightButton_clicked();
    void onLoginClicked();  // 登录按钮点击事件
    void onLogoutClicked(); // 退出按钮点击事件

    void on_myOrdersButton_clicked();

    void on_seatsSelectButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::homemanager *ui;
        QMenu *menu; // 悬浮菜单
};

#endif // HOMEMANAGER_H
