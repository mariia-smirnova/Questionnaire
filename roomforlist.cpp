#include "roomforlist.h"
#include "ui_roomforlist.h"

RoomForList::RoomForList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomForList)
{
    ui->setupUi(this);
}

RoomForList::~RoomForList()
{
    delete ui;
}
