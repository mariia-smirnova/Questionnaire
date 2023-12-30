#ifndef FREEANSWER_H
#define FREEANSWER_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class FreeAnswer;
}

class FreeAnswer : public QWidget
{
    Q_OBJECT

public:
    explicit FreeAnswer(QJsonObject jsonobj, QWidget *parent = nullptr);
    ~FreeAnswer();

private:
    Ui::FreeAnswer *ui;
};

#endif // FREEANSWER_H
