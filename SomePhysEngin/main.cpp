#include "someenginmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SomeEnginMainWindow w;
    w.show();

    return a.exec();
}
