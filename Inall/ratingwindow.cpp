//ratingwindow.cpp
#include "ratingwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

RatingWindow::RatingWindow(const QString& orderID, QWidget *parent) :
    QWidget(parent), orderID(orderID)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 创建三个评分滑块，步长设置为0.5
    slider1 = new QSlider(Qt::Horizontal, this);
    slider2 = new QSlider(Qt::Horizontal, this);
    slider3 = new QSlider(Qt::Horizontal, this);

    slider1->setRange(0, 10);  // 范围是0到10，表示评分1到5
    slider2->setRange(0, 10);  // 范围是0到10，表示评分1到5
    slider3->setRange(0, 10);  // 范围是0到10，表示评分1到5

    // 设置步长为0.5，表示评分为1、1.5、2、2.5等
    slider1->setSingleStep(1);
    slider2->setSingleStep(1);
    slider3->setSingleStep(1);

    // 创建标签显示评分
    QLabel *label1 = new QLabel("第一项评分（1-5分）", this);
    QLabel *label2 = new QLabel("第二项评分（1-5分）", this);
    QLabel *label3 = new QLabel("第三项评分（1-5分）", this);

    avgRatingLabel = new QLabel("平均评分: 尚未评分", this);

    // 创建显示评分值的标签
    ratingLabel1 = new QLabel("当前评分：1.0", this);
    ratingLabel2 = new QLabel("当前评分：1.0", this);
    ratingLabel3 = new QLabel("当前评分：1.0", this);

    // 提交按钮
    QPushButton *submitButton = new QPushButton("提交评价", this);
    connect(submitButton, &QPushButton::clicked, this, &RatingWindow::calculateAverageRating);

    // 创建用于显示感谢信息的标签
    thankYouLabel = new QLabel("感谢您的评价！", this);
    thankYouLabel->setVisible(false);  // 初始时隐藏感谢标签

    // 连接滑块的信号，更新评分显示值
    connect(slider1, &QSlider::valueChanged, this, &RatingWindow::updateSlider1Value);
    connect(slider2, &QSlider::valueChanged, this, &RatingWindow::updateSlider2Value);
    connect(slider3, &QSlider::valueChanged, this, &RatingWindow::updateSlider3Value);

    // 布局
    layout->addWidget(label1);
    layout->addWidget(slider1);
    layout->addWidget(ratingLabel1);  // 显示评分1的值
    layout->addWidget(label2);
    layout->addWidget(slider2);
    layout->addWidget(ratingLabel2);  // 显示评分2的值
    layout->addWidget(label3);
    layout->addWidget(slider3);
    layout->addWidget(ratingLabel3);  // 显示评分3的值
    layout->addWidget(avgRatingLabel);
    layout->addWidget(submitButton);
    layout->addWidget(thankYouLabel);  // 加入感谢信息的标签

    setLayout(layout);

    // 设置窗口大小和位置
    setFixedSize(400, 300);
    setWindowTitle("评分窗口");  // 设置窗口标题
}

RatingWindow::~RatingWindow()
{
}

void RatingWindow::calculateAverageRating() {
    int rating1 = slider1->value() / 2.0;  // 将滑块的值转换为实际的评分（0-10转为0.0-5.0）
    int rating2 = slider2->value() / 2.0;
    int rating3 = slider3->value() / 2.0;

    double averageRating = (rating1 + rating2 + rating3) / 3.0;
    avgRatingLabel->setText("平均评分: " + QString::number(averageRating, 'f', 2));

    // 显示感谢信息
    thankYouLabel->setVisible(true);  // 显示感谢信息标签
    QMessageBox::information(this, "感谢", "感谢您的评价，平均评分是: " + QString::number(averageRating, 'f', 2));
}

// 更新评分1的显示值
void RatingWindow::updateSlider1Value(int value) {
    float displayValue = value / 2.0;
    ratingLabel1->setText("当前评分：" + QString::number(displayValue, 'f', 1));
}

// 更新评分2的显示值
void RatingWindow::updateSlider2Value(int value) {
    float displayValue = value / 2.0;
    ratingLabel2->setText("当前评分：" + QString::number(displayValue, 'f', 1));
}

// 更新评分3的显示值
void RatingWindow::updateSlider3Value(int value) {
    float displayValue = value / 2.0;
    ratingLabel3->setText("当前评分：" + QString::number(displayValue, 'f', 1));
}
