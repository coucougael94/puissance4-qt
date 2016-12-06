#include "mainfile.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainFile w;
    w.show();

    return a.exec();
}
