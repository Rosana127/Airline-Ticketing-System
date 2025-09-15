#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include <QStackedWidget>

namespace Ui {
class HomePage; // 注意这里也要更改
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
//    void onSearchFlightClicked();
    //void onMyOrdersClicked();
    void onSeatsSelectClicked();
    void onLoginClicked();  // 登录按钮点击事件
    void onLogoutClicked(); // 退出按钮点击事件

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_myOrdersButton_clicked();

   // void on_seatsSelectButton_clicked();

    void on_searchFlightButton_clicked();

private:
    Ui::HomePage *ui; // 注意这里也要更改
    QMenu *menu; // 悬浮菜单
    QLabel *userLabel;
};

#endif // HOMEPAGE_H
