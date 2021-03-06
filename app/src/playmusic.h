#ifndef PLAYMUSIC_H
#define PLAYMUSIC_H

#include <QWidget>
#include <QMediaPlayer>

class generalWindow;
class DataBase;

namespace Ui {
class PlayMusic;
}

class PlayMusic : public QWidget
{
    Q_OBJECT

public:
    explicit PlayMusic(QWidget *parent = nullptr);
    ~PlayMusic();

    void setNewMusic(const QString& name, const QString& path);
    void setNewMusicAndPlay(const QString& name, const QString& path);
    void play(void) {
        on_ButtonPlay_clicked();
    }
    void clickShortKeyPlay(void);
    void clickShortKeyRewind(void);
    void clickShortKeyFastForward(void);
    void loadingSettings(DataBase *db);
    void pause(void);

private:
    QString getTime(qint64 time);
    void setTimeMusic(qint64 valueTile, qint64 maxTime);
    void valueChangedSliderMusic(int value);

private slots:
    void positionChanged(qint64 position);

    void stateChanged(QMediaPlayer::State state);

    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void on_ButtonPrevious_clicked();

    void on_ButtonRewind_clicked();

    void on_ButtonPause_clicked();

    void on_ButtinStop_clicked();

    void on_ButtonPlay_clicked();

    void on_ButtonFastForward_clicked();

    void on_ButtonNext_clicked();

    void on_ButtonShuffle_clicked();

private:
    Ui::PlayMusic *ui;
    QMediaPlayer *m_media;
    bool m_playMusic = false;
    generalWindow *m_window;
};

#endif // PLAYMUSIC_H
