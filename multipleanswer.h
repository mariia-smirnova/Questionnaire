#ifndef MULTIPLEANSWER_H
#define MULTIPLEANSWER_H

#include <QJsonObject>
#include <QWidget>
#include "itojson.h"

namespace Ui {
class MultipleAnswer;
}

class MultipleAnswer : public QWidget, public IToJson
{
    Q_OBJECT

public:
    explicit MultipleAnswer(QJsonObject jsonobj, QWidget *parent = nullptr);
    ~MultipleAnswer();
    QJsonObject toJson() const override;

private:
    Ui::MultipleAnswer *ui;
};

#endif // MULTIPLEANSWER_H
