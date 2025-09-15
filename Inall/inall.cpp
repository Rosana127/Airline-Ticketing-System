#include "inall.h"
#include "ui_inall.h"

Inall::Inall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inall)
{
    ui->setupUi(this);
}

Inall::~Inall()
{
    delete ui;
}
