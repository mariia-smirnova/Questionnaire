#include "readyanswers.h"
#include "ui_readyanswers.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "multipleanswer.h"
#include <QFile>

ReadyAnswers::ReadyAnswers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadyAnswers)
{
    ui->setupUi(this);
    QFile file;
    file.setFileName("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    auto list = fromJson(file.readAll());
    file.close();
    for (auto widget:list)
    {
        ui->verticalLayout->addWidget(widget);
    }
}


ReadyAnswers::~ReadyAnswers()
{
    delete ui;
}

QList<QWidget *> ReadyAnswers::fromJson(QString str)
{
    QList<QWidget*> resultList;
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    if(!doc.isObject()) qFatal("error");
    QJsonObject json = doc.object();
    int countQuestions = json["count questions"].toInt();
    QJsonArray listQuestions = json["list"].toArray();
    for (const QJsonValue& question:listQuestions)
    {
        QJsonObject obj = question.toObject();
        if(obj["type"].toString()=="multiple")
        {
            QString text = obj["question"].toString();
            int count = obj["count answers"].toInt();
            QList<QPair<bool, QString>> answers;
            QJsonArray listAnswers = obj ["answers"].toArray();
            for(const QJsonValue& answer:listAnswers)
            {
                answers.push_back({answer.toObject()["mark"].toBool(),answer.toObject()["text"].toString()});
            }
            resultList.push_back(new MultipleAnswer(text, answers));
        }
    }
    return resultList;
}
