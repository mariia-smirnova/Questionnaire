#ifndef ROOMFORLIST_H
#define ROOMFORLIST_H

#include <QWidget>

namespace Ui {
class RoomForList;
}

class RoomForList : public QWidget
{
    Q_OBJECT

public:
    explicit RoomForList(QWidget *parent = nullptr);
    ~RoomForList();

private:
    Ui::RoomForList *ui;
};

#endif // ROOMFORLIST_H
