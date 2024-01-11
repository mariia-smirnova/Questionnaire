#ifndef SINGLEANSWER_H
#define SINGLEANSWER_H

#include <QWidget>
#include <QJsonObject>
#include "itojson.h"

namespace Ui {
class SingleAnswer;
}

class SingleAnswer : public QWidget, public IToJson
{
    Q_OBJECT

public:
    explicit SingleAnswer(QJsonObject jsonobj, QWidget *parent= nullptr);
    ~SingleAnswer();

private:
    Ui::SingleAnswer *ui;

    // IToJson interface
public:
    QJsonObject toJson() const override;
};

#endif // SINGLEANSWER_H
