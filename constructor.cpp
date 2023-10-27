#include "constructor.h"
#include "ui_constructor.h"

Constructor::Constructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constructor)
{
    ui->setupUi(this);
}

Constructor::~Constructor()
{
    delete ui;
}
