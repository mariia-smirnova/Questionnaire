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
    if(arg1 =="Free")
    {
        while (QLayoutItem* item = ui->variants->takeAt(0)) {
            delete item->widget();
            delete item;
        }
        on_addVariant_clicked();
        ui->removeVariant->setEnabled(false);
        ui->addVariant->setEnabled(false);
    }
    else
    {
        ui->removeVariant->setEnabled(true);
        ui->addVariant->setEnabled(true);
    }
}

void Question::on_removeVariant_clicked()
{
    QLayoutItem* item = ui->variants->takeAt(ui->variants->count()-1);
    if (!item) return;
    delete item->widget();
    delete item;
}


void Question::on_addVariant_clicked()
{
    ui->variants->addWidget(new QLineEdit);
}

