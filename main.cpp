#include "homeautomainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeAutoMainWindow w;
    w.show();
    return a.exec();
}
