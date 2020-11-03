#include "generalwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("/Users/solianovsk/Desktop/player/uamp/stylesheet.qss");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    generalWindow w;
    w.show();

    return a.exec();
}
