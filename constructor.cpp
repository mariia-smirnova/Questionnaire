#include "constructor.h"
#include "ui_constructor.h"
#include <QPushButton>

Constructor::Constructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constructor)
{
    ui->setupUi(this);
    auto b = new QPushButton();
    ui->left->addWidget(b);
}

Constructor::~Constructor()
{
    delete ui;
}
