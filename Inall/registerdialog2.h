#ifndef REGISTERDIALOG2_H
#define REGISTERDIALOG2_H
#include<QDebug>
#include <QWidget>
namespace Ui {
class RegisterDialog2;
}

class RegisterDialog2 : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterDialog2(QWidget *parent = nullptr, bool isAdmin = false);
    ~RegisterDialog2();
    QString sexValue;

private slots:
    void on_registerButton_clicked();
//    void onButtonClicked(QAbstractButton *button) {
//        // 获取被选中的复选框的文本
//         s = button->text();
//        qDebug() << "Selected: " << s;
//    }

    void on_male_clicked();

    void on_female_clicked();

    void on_otherSex_clicked();

private:
    Ui::RegisterDialog2 *ui;
    bool isAdmin;

//    QString s;

};

#endif // REGISTERDIALOG2_H
