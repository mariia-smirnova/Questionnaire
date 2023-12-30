#ifndef READYANSWERS_H
#define READYANSWERS_H

#include <QWidget>

namespace Ui {
class ReadyAnswers;
}

class ReadyAnswers : public QWidget
{
    Q_OBJECT

public:
    explicit ReadyAnswers(QWidget *parent = nullptr);
    ~ReadyAnswers();

private:
    Ui::ReadyAnswers *ui;
    static QList<QWidget*> fromJson(QString str);
};

#endif // READYANSWERS_H
