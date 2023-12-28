#include "question.h"
#include "ui_question.h"
#include <QLineEdit>
#include <QJsonArray>

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

QJsonObject Question::toJson() const
{
    QJsonObject result;
    result.insert("type",ui->typeQuestion->currentText().toLower());
    result.insert("question", ui->question->toPlainText());
    if(ui->typeQuestion->currentText()=="Free")
    {
        result.insert("answer","");
        return result;
    }
    result.insert("count answers", ui->variants->count());
    QJsonArray answers;
    for(int i=0; i<ui->variants->count(); i++)
    {
        QJsonObject answer;
        answer.insert("mark",false);
        answer.insert("text",dynamic_cast<QLineEdit*>(ui->variants->itemAt(i)->widget())->text());
        answers.push_back(answer);
    }
    result.insert("answers",answers);
    return result;
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


void Question::on_deleteButton_clicked()
{
    delete this;
}

