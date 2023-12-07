#include "question.h"
#include "ui_question.h"
#include <QLineEdit>

Question::Question(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Question)
{
    ui->setupUi(this);
}

Question::~Question()
{
    delete ui;
}

void Question::on_typeQuestion_currentTextChanged(const QString &arg1)
{
    if (ui->typeQuestion->currentText()=="Multiple" && arg1=="Single")
        return;
    if (ui->typeQuestion->currentText()=="Single" && arg1=="Multiple")
        return;
    if(arg1 =="Free")
    {
        while(!ui->variants->isEmpty())
            on_removeVariant_clicked();
        on_addVariant_clicked();
    }
}

void Question::on_removeVariant_clicked()
{
    ui->variants->removeItem(ui->variants->itemAt(ui->variants->count()-1));
}


void Question::on_addVariant_clicked()
{
    ui->variants->addWidget(new QLineEdit);
}

