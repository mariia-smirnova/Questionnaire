#include "constructor.h"
#include "ui_constructor.h"
#include <QPushButton>
#include <QLabel>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>

Constructor::Constructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constructor)
{
    ui->setupUi(this);
    label = new QLabel("Hello World");
    ui->left->addWidget(label);
    setAcceptDrops(true);
}

Constructor::~Constructor()
{
    delete ui;
}


void Constructor::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton &&
        label->geometry().contains(event->pos()))
    {
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);

        dataStream << label->text();

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("label", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        QPixmap pixmap("C:/QtProjects/Questionnaire/Red.png");
        drag->setPixmap(pixmap);


        drag->exec(Qt::MoveAction);
    }
}

void Constructor::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("label"))
        event->accept();
    else
        event->ignore();
}

void Constructor::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("label"))
    {
        QByteArray itemData = event->mimeData()->data("label");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QString str;
        dataStream >> str;
        auto b = new QLabel(str);
        ui->right->addWidget(b);

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
    if (event->mimeData()->hasFormat("label")) {

        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}
