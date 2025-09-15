#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_minimizeButton_clicked();
    void on_closeButton_clicked();
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void on_forgetButton_clicked();
    void on_managerUiButton_clicked();



protected:
    // 鼠标事件重载
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Login *ui;
    // 用于窗口拖动的成员变量
    bool m_drag = false;                    // 是否正在拖动
    QPoint m_dragPosition;                  // 拖动时鼠标相对于窗口左上角的位置
    bool checkUserExists(const QString &account, const QString &password);

};

#endif // LOGIN_H
