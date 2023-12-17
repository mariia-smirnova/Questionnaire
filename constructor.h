#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QWidget>
#include <QLabel>

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
    QString toJson() const;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

    // QWidget interface
protected:
    void dragMoveEvent(QDragMoveEvent *event) override;
private slots:
    void on_pushButton_clicked();
};

#endif // CONSTRUCTOR_H
