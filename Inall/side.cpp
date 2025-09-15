#include "side.h"
#include "ui_side.h"
#include"flight_add2.h"
#include"flight_change.h"
#include"flight_delete.h"
#include"chooseair.h"

side::side(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::side)
{
//        QWidget* add = new flight_add2(this);
//        QWidget* change = new flight_change(this);
//        QWidget* delete1 = new flight_delete(this);       //
////        chooseAir* chooseair=new chooseAir(this);
//        // 将QDialog类型的页面添加到QStackedWidget中
//        ui->stackedWidget->addWidget(add);
//        ui->stackedWidget->addWidget(change);
//        ui->stackedWidget->addWidget(delete1);
////        ui->stackedWidget->addWidget(chooseair);
//        // 打印出当前显示的页面索引，确认 setCurrentIndex 是否生效
//        qDebug() << "Current Page Index: " << ui->stackedWidget->currentIndex();
//        // 创建一个QButtonGroup来处理按钮点击事件
//        QButtonGroup btnGroup;

//        btnGroup.addButton(ui->btnadd, 0);
//        btnGroup.addButton(ui->btndelete, 1);
//        btnGroup.addButton(ui->btnchange, 2);
////        btnGroup.addButton(ui->btnfind, 3);

//        // 连接QButtonGroup的buttonClicked信号到QStackedWidget的setCurrentIndex槽
//        connect(&btnGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
//                [this](int id) {
//                    qDebug() << "Button clicked, switching to page: " << id;
//                    ui->stackedWidget->setCurrentIndex(id);
//                });


//        // 设置默认选中的页面
//        btnGroup.button(0)->setChecked(true);
//        ui->stackedWidget->setCurrentIndex(0);
//        show();

//    flight_add2 *widgetDialog=new flight_add2();
//    qDebug() << "页面索引: " << ui->stackedWidget->addWidget(widgetDialog);
//     }
qDebug() << "页面索引总数: " << ui->stackedWidget->count();
}

side::~side()
{
    delete ui;
}
