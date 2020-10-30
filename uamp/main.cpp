#include "generalwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    generalWindow w;
    w.show();

    return a.exec();
}
