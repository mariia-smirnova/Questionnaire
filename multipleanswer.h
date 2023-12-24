#ifndef MULTIPLEANSWER_H
#define MULTIPLEANSWER_H

#include <QJsonObject>
#include <QWidget>

namespace Ui {
class MultipleAnswer;
}

class MultipleAnswer : public QWidget
{
    Q_OBJECT

public:
    explicit MultipleAnswer(QJsonObject jsonobj, QWidget *parent = nullptr);
    ~MultipleAnswer();

private:
    Ui::MultipleAnswer *ui;
};

#endif // MULTIPLEANSWER_H
