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
