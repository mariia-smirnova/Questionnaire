#include "constructor.h"
#include "ui_constructor.h"
#include <QPushButton>
#include <QLabel>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include "multipleanswer.h"
#include  "question.h"
#include <QJsonArray>
#include <QJsonDocument>

Constructor::Constructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constructor)
{
    ui->setupUi(this);
    ui->left->addWidget(new Question);

    setAcceptDrops(true);
}

Constructor::~Constructor()
{
    delete ui;
}

QString Constructor::toJson() const
{
    QJsonObject result;
    result.insert("count questions", ui->left->count()-1/*из-за учета спейсера*/);
    QJsonArray questions;
    for (int i=0; i<ui->left->count(); i++)
    {
        auto q = dynamic_cast<Question*>(ui->left->takeAt(i)->widget());
        if (!q) continue;
        questions.push_back(q->toJson());
    }
    result.insert("list", questions);
    QJsonDocument doc(result);
    return doc.toJson(QJsonDocument::Indented);
}


void Constructor::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton &&
        ui->multiple->geometry().contains(event->pos()))
    {
        QByteArray itemData;
        /*QDataStream dataStream(&itemData, QIODevice::WriteOnly);

        dataStream << ui->multiple->text();*/

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("multiple", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        QPixmap pixmap("C:/QtProjects/Questionnaire/Red.png");
        pixmap=pixmap.scaled(pixmap.size()/20);
        drag->setPixmap(pixmap);


        drag->exec(Qt::MoveAction);
    }
}

void Constructor::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("multiple"))
        event->accept();
    else
        event->ignore();
}

void Constructor::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("multiple"))
    {
        /*QByteArray itemData = event->mimeData()->data("label");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QString str;
        dataStream >> str;
        auto b = new QLabel(str);
        ui->right->addWidget(b);*/
        ui->left->addWidget(new MultipleAnswer("?", {"","","",""}));

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}


void Constructor::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("multiple")) {

        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}

void Constructor::on_pushButton_clicked()
{
    qDebug()<<toJson();
}

