
#include <QApplication>
#include "constructor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Constructor obj;
    obj.show();
    return a.exec();
}
