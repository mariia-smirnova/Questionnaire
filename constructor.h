#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QWidget>

namespace Ui {
class Constructor;
}

class Constructor : public QWidget
{
    Q_OBJECT

public:
    explicit Constructor(QWidget *parent = nullptr);
    ~Constructor();

private:
    Ui::Constructor *ui;
};

#endif // CONSTRUCTOR_H
