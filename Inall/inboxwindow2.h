#ifndef INBOXWINDOW2_H
#define INBOXWINDOW2_H

#include <QWidget>
#include<QListWidget>
namespace Ui {
class inboxWindow2;
}

class inboxWindow2 : public QWidget
{
    Q_OBJECT

public:
    explicit inboxWindow2(QWidget *parent = nullptr);
    ~inboxWindow2();

private:
    Ui::inboxWindow2 *ui;
    QListWidget *messageList;  // 用于展示延误信息列表

    void loadMessages();  // 加载延误信息
};

#endif // INBOXWINDOW2_H
