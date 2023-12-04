#include "multipleanswer.h"
#include "ui_multipleanswer.h"
#include <QCheckBox>

MultipleAnswer::MultipleAnswer(QString question, QList<QPair<bool,QString>> answers, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultipleAnswer)
{
    ui->setupUi(this);
    ui->question->setText(question);
    for(const auto& answer:answers)
    {
        auto box = new QCheckBox(answer.second);
        box ->setChecked(answer.first);
        box->setEnabled(false);
        ui->answers->addWidget(box);
    }
}

MultipleAnswer::~MultipleAnswer()
{
    delete ui;
}
