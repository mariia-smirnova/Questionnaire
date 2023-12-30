
#include <QApplication>
#include "constructor.h"
#include "readyanswers.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReadyAnswers obj;
    obj.show();
    return a.exec();
}
