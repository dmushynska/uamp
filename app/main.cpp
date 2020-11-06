#include "generalwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("./app/stylesheet.qss");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    generalWindow w;
//    w.addNewMusicToQueue("/Users/solianovsk/Desktop/2L-110_04_stereo.mqa.flac");
//    w.addNewMusicToQueue("/Users/solianovsk/Desktop/3285.wav");
//    w.cleanListMusic();
//    w.addNewMusicToQueue("/Users/solianovsk/Desktop/videoplayback.mp4");
    w.show();

    return a.exec();
}
