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
    void readJson(QString json);
    Ui::ReadyAnswers *ui;
    QString toJson() const;

private:
    static QList<QWidget*> fromJson(QString str);
};

#endif // READYANSWERS_H
