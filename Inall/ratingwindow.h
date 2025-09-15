#ifndef RATINGWINDOW_H
#define RATINGWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

class RatingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RatingWindow(const QString& orderID, QWidget *parent = nullptr);
    ~RatingWindow();

private slots:
    void calculateAverageRating();
    void updateSlider1Value(int value);  // 更新评分1的值
    void updateSlider2Value(int value);  // 更新评分2的值
    void updateSlider3Value(int value);  // 更新评分3的值

private:
    QString orderID;
    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QLabel *avgRatingLabel;
    QLabel *thankYouLabel;
    QLabel *ratingLabel1;  // 显示评分1的值
    QLabel *ratingLabel2;  // 显示评分2的值
    QLabel *ratingLabel3;  // 显示评分3的值
};

#endif // RATINGWINDOW_H
