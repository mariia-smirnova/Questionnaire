#include "readyanswers.h"
#include "ui_readyanswers.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "freeanswer.h"
#include "multipleanswer.h"
#include "singleanswer.h"
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
        ui->questions->layout()->addWidget(widget);
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
    //if(!doc.isObject()) qFatal("error");
    QJsonObject json = doc.object();
    /*int countQuestions = json["count questions"].toInt();*/
    QJsonArray listQuestions = json["list"].toArray();
    for (const QJsonValue& question:listQuestions)
    {
        QJsonObject obj = question.toObject();
        if(obj["type"].toString()=="multiple")
        {

            resultList.push_back(new MultipleAnswer(obj));
        }
        else if(obj["type"].toString()=="single")
        {

            resultList.push_back(new SingleAnswer(obj));
        }
        else if(obj["type"].toString()=="free")
        {

            resultList.push_back(new FreeAnswer(obj));
        }
    }
    return resultList;
}
