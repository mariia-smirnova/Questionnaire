#ifndef MULTIPLEANSWER_H
#define MULTIPLEANSWER_H

#include <QWidget>

namespace Ui {
class MultipleAnswer;
}

class MultipleAnswer : public QWidget
{
    Q_OBJECT

public:
    explicit MultipleAnswer(QString question, QList<QPair<bool,QString>> answers, QWidget *parent = nullptr);
    ~MultipleAnswer();

private:
    Ui::MultipleAnswer *ui;
};

#endif // MULTIPLEANSWER_H
