
#include <QApplication>
#include "constructor.h"
#include "readyanswers.h"
#include <QtSql>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Constructor obj;
    obj.show();
    ReadyAnswers forStudent;
    forStudent.show();
    ReadyAnswers forTeacher;
    forTeacher.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Подключение к базе данных
    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных";
        return -1;
    }

    // Подготовка таблицы, если её нет
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER)");

    // Вставка данных в таблицу
    query.prepare("INSERT INTO employees (name, age) VALUES (:name, :age)");
    query.bindValue(":name", "Иванов");
    query.bindValue(":age", 25);

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке данных:" << query.lastError().text();
            return -1;
    }

    // Чтение данных из таблицы
    query.exec("SELECT * FROM employees");
    while (query.next()) {
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "Имя:" << name << "Возраст:" << age;
    }

    // Закрытие базы данных
    db.close();


    return a.exec();
}
