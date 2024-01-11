#include "singleanswer.h"
#include "ui_singleanswer.h"
#include <QRadioButton>
#include <QJsonArray>

SingleAnswer::SingleAnswer(QJsonObject jsonobj, QWidget *parent):
    QWidget(parent),
    ui(new Ui::SingleAnswer)
{
    ui->setupUi(this);
    ui->question->setText(jsonobj["question"].toString());
    QJsonArray answers = jsonobj["answers"].toArray();
    for(const QJsonValue& answer:answers)
    {
        QJsonObject ans = answer.toObject();
        auto button = new QRadioButton(ans["text"].toString());
        button ->setChecked(ans["mark"].toBool());
        button->setEnabled(ans["mark"].isNull());
        ui->answers->addWidget(button);
    }
}

SingleAnswer::~SingleAnswer()
{
    delete ui;
}

QJsonObject SingleAnswer::toJson() const
{
    QJsonObject result;
    result.insert("type", "single");
    result.insert("question", ui->question->toPlainText());
    QJsonArray answers;
    for(int i=0; i<ui->variants->count(); i++)
    {
        auto button = dynamic_cast<QRadioButton*>(ui->answers->itemAt(i)->widget());
        QJsonObject answer;
        answer.insert("mark",button->isChecked());
        answer.insert("text", button->text());
        answers.push_back(answer);
    }
    result.insert("answers",answers);
    return result;
}
