#include "freeanswer.h"
#include "ui_freeanswer.h"

FreeAnswer::FreeAnswer(QJsonObject jsonobj, QWidget *parent):
    QWidget(parent),
    ui(new Ui::FreeAnswer)
{
    ui->setupUi(this);
    ui->question->setText(jsonobj["question"].toString());
    ui->answer->setText(jsonobj["answer"].toString());
    ui->answer->setEnabled(jsonobj["answer"].isNull());
}

FreeAnswer::~FreeAnswer()
{
    delete ui;
}
