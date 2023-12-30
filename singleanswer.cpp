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
