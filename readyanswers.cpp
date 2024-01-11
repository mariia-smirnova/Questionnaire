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
}


ReadyAnswers::~ReadyAnswers()
{
    delete ui;
}

void ReadyAnswers::readJson(QString json)
{
    auto list = fromJson(json);
    for (auto widget:list)
    {
        ui->questions->layout()->addWidget(widget);
    }
}

QString ReadyAnswers::toJson() const
{
    QJsonObject result;
    QJsonArray questions;
    for (int i=0; i<ui->questions->layout()->count(); i++)
    {
        auto w = dynamic_cast<IToJson*>(ui->questions->layout()->itemAt(i)->widget());
        if (!w) continue;
        questions.push_back(w->toJson());
    }
    result.insert("list", questions);
    QJsonDocument doc(result);
    return doc.toJson(QJsonDocument::Indented);
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
