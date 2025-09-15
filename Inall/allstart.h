#ifndef ALLSTART_H
#define ALLSTART_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Allstart; }
QT_END_NAMESPACE

class Allstart : public QMainWindow
{
    Q_OBJECT

public:
    Allstart(QWidget *parent = nullptr);
    ~Allstart();

private:
    Ui::Allstart *ui;
};
#endif // ALLSTART_H
