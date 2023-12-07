#ifndef QUESTION_H
#define QUESTION_H

#include <QWidget>

namespace Ui {
class Question;
}

class Question : public QWidget
{
    Q_OBJECT

public:
    explicit Question(QWidget *parent = nullptr);
    ~Question();

private slots:
    void on_typeQuestion_currentTextChanged(const QString &arg1);

    void on_removeVariant_clicked();

    void on_addVariant_clicked();

private:
    Ui::Question *ui;
};

#endif // QUESTION_H