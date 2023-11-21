#include "freeanswer.h"
#include "ui_freeanswer.h"

FreeAnswer::FreeAnswer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FreeAnswer)
{
    ui->setupUi(this);
}

FreeAnswer::~FreeAnswer()
{
    delete ui;
}
