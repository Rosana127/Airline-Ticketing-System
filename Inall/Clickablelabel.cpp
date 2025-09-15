#include "clickableLabel.h"
#include <QMouseEvent>

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    QLabel::mousePressEvent(event);
    emit clicked();
}
