
#include <QApplication>
#include "constructor.h"
#include "readyanswers.h"
#include <QtSql>
#include <QDebug>
#include "ui_constructor.h"
#include "ui_readyanswers.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Constructor obj;
    obj.show();
    ReadyAnswers forStudent;
    ReadyAnswers forTeacher;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Подключение к базе данных
    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных";
        return -1;
    }

    // Подготовка таблицы, если её нет
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS survey ("
                    "survey_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "json_data TEXT)"))
    {
        qDebug()<<"не удалось создать таблицу 'survey':"<<query.lastError().text();
    }
    if(!query.exec("CREATE TABLE IF NOT EXISTS response ("
                    "response_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "survey_id INTEGER, "
                    "json_data TEXT)"))
    {
        qDebug()<<"не удалось создать таблицу 'response':"<<query.lastError().text();
    }

    QObject::connect(obj.ui->pushButton, &QPushButton::clicked, [&](){
        QSqlQuery q;
        q.prepare("INSERT INTO survey (json_data) VALUES (:json)");
        q.bindValue(":json",obj.toJson());
        if(!q.exec()){
            qDebug()<<"не удалось добавить данные в таблицу survey:"<<q.lastError().text();
        }
        forStudent.show();
        if(!q.exec("SELECT json_data FROM survey WHERE survey_id = 1")){
            qDebug()<<q.lastError().text();
        }
        if(!q.next()) qDebug()<<"нет данных";
        forStudent.readJson(q.value(0).toString());
    });
    QObject::connect(forStudent.ui->pushButton, &QPushButton::clicked, [&](){
        QSqlQuery q;
        q.prepare("INSERT INTO response (survey_id, json_data) VALUES (?, ?)");
        q.bindValue( 1, forStudent.toJson());
        q.bindValue(0,1);
        if(!q.exec()){
            qDebug()<<"не удалось добавить данные в таблицу survey:"<<q.lastError().text();
        }
    });

    return a.exec();
}
