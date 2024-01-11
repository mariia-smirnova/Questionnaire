#ifndef FREEANSWER_H
#define FREEANSWER_H

#include <QWidget>
#include <QJsonObject>
#include "itojson.h"

namespace Ui {
class FreeAnswer;
}

class FreeAnswer : public QWidget, public IToJson
{
    Q_OBJECT

public:
    explicit FreeAnswer(QJsonObject jsonobj, QWidget *parent = nullptr);
    ~FreeAnswer();
    QJsonObject toJson() const override;

private:
    Ui::FreeAnswer *ui;
};

#endif // FREEANSWER_H
