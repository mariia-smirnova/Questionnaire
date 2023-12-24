#ifndef SINGLEANSWER_H
#define SINGLEANSWER_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class SingleAnswer;
}

class SingleAnswer : public QWidget
{
    Q_OBJECT

public:
    explicit SingleAnswer(QJsonObject jsonobj, QWidget *parent= nullptr);
    ~SingleAnswer();

private:
    Ui::SingleAnswer *ui;
};

#endif // SINGLEANSWER_H
