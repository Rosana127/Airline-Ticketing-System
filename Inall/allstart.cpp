#include "allstart.h"
#include "ui_allstart.h"

Allstart::Allstart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Allstart)
{
    ui->setupUi(this);
}

Allstart::~Allstart()
{
    delete ui;
}

