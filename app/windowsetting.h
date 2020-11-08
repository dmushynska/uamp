#ifndef WINDOWSETTING_H
#define WINDOWSETTING_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class WindowSetting;
}

class generalWindow;

class WindowSetting : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSetting(QWidget *parent = nullptr);
    ~WindowSetting();

    enum class Sort {
        user,
        artist,
        title,
        album,
        genre
    };
    enum class nextMusic {
        onePlay,
        loopQueue,
        repeatSong,
        randomMusic
    };
    WindowSetting::nextMusic getTypeNext();
    WindowSetting::Sort getTypeSort(void);

signals:
    void dialogClosed();

private slots:
    void closeEvent(QCloseEvent *event)
    {
    emit dialogClosed();
        event->accept();
    }
    void on_pushButton_Save_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::WindowSetting *ui;
    generalWindow *m_main;
    Sort m_TypeSort;
    nextMusic m_TypeNextMusic;
};

#endif // WINDOWSETTING_H
