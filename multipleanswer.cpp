#include "multipleanswer.h"
#include "ui_multipleanswer.h"

MultipleAnswer::MultipleAnswer(QString question, QVector<QString> answers, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultipleAnswer)
{
    ui->setupUi(this);
    ui->question->setText(question);
    for(int i=0; i<answers.size(); i++)
    {
        dynamic_cast<QCheckBox*>(ui->answers->itemAt(i)->widget())->setText(answers[i]);
    }
}

MultipleAnswer::~MultipleAnswer()
{
    delete ui;
}
