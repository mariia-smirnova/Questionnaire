#ifndef FREEANSWER_H
#define FREEANSWER_H

#include <QWidget>

namespace Ui {
class FreeAnswer;
}

class FreeAnswer : public QWidget
{
    Q_OBJECT

public:
    explicit FreeAnswer(QWidget *parent = nullptr);
    ~FreeAnswer();

private:
    Ui::FreeAnswer *ui;
};

#endif // FREEANSWER_H
