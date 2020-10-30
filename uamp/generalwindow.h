#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QMainWindow>

#include "playmusic.h"
#include <iostream>
#include <QVector>

class MusicList;

namespace Ui {
class generalWindow;
}

class generalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit generalWindow(QWidget *parent = nullptr);
    ~generalWindow();
    void nextMusic (void) {
        pos++;
        if (pos == 5)
            pos = 0;
        std::cout << 1 << std::endl;
         qDebug() << list[pos];
        m_playMusic->setNewMusicAndPlay(list[pos]);
    }
    void previousMusic (void) {
        --pos;
        if (pos == -1)
            pos = 4;
        qDebug() << list[pos];
        m_playMusic->setNewMusicAndPlay(list[pos]);
    }

private slots:


private:
    Ui::generalWindow *ui;
    PlayMusic *m_playMusic;
    MusicList *m_MusicList;
    int pos = 0;
    QVector <QString>  list = {"/Users/solianovsk/Desktop/2L-110_04_stereo.mqa.flac", "/Users/solianovsk/Desktop/3285.wav", "/Users/solianovsk/Desktop/videoplayback.mp4", "/Users/solianovsk/Desktop/Ты Врёшь.mp3",
                              "Maxime Abbey - Operation Stealth - The Ballad of J. & J.ogg"};
};

#endif // GENERALWINDOW_H
