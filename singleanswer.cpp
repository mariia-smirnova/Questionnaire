#include "singleanswer.h"
#include "ui_singleanswer.h"

SingleAnswer::SingleAnswer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleAnswer)
{
    ui->setupUi(this);
}

SingleAnswer::~SingleAnswer()
{
    delete ui;
}
