#ifndef PLAYMUSIC_H
#define PLAYMUSIC_H

#include <QWidget>
#include <QMediaPlayer>

class generalWindow;

namespace Ui {
class PlayMusic;
}

class PlayMusic : public QWidget
{
    Q_OBJECT

public:
    explicit PlayMusic(QWidget *parent = nullptr);
    ~PlayMusic();

    void setNewMusic(const QString& name);
    void setNewMusicAndPlay(const QString& name);

private slots:
    void positionChanged(qint64 position);

    void stateChanged(QMediaPlayer::State state);

    void on_ButtonPrevious_clicked();

    void on_ButtonRewind_clicked();

    void on_ButtonPause_clicked();

    void on_ButtinStop_clicked();

    void on_ButtonPlay_clicked();

    void on_ButtonFastForward_clicked();

    void on_ButtonNext_clicked();

private:
    Ui::PlayMusic *ui;
    QMediaPlayer *m_media;
    bool m_playMusic = false;
    generalWindow *window;
};

#endif // PLAYMUSIC_H
