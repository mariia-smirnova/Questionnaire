#include "multipleanswer.h"
#include "ui_multipleanswer.h"
#include <QCheckBox>
#include <QJsonArray>

MultipleAnswer::MultipleAnswer(QJsonObject jsonobj, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultipleAnswer)
{
    ui->setupUi(this);
    ui->question->setText(jsonobj["question"].toString());
    QJsonArray answers = jsonobj["answers"].toArray();
    for(const QJsonValue& answer:answers)
    {
        QJsonObject ans = answer.toObject();
        auto box = new QCheckBox(ans["text"].toString());
        box ->setChecked(ans["mark"].toBool());
        //box->setEnabled(false);
        box->setEnabled(ans["mark"].isNull());
        ui->answers->addWidget(box);
    }
}

MultipleAnswer::~MultipleAnswer()
{
    delete ui;
}

QJsonObject MultipleAnswer::toJson() const
{
    QJsonObject result;
    result.insert("type", "multiple");
    result.insert("question", ui->question->toPlainText());
    QJsonArray answers;
    for(int i=0; i<ui->variants->count(); i++)
    {
        auto box = dynamic_cast<QCheckBox*>(ui->answers->itemAt(i)->widget());
        QJsonObject answer;
        answer.insert("mark",box->isChecked());
        answer.insert("text", box->text());
        answers.push_back(answer);
    }
    result.insert("answers",answers);
    return result;
}
