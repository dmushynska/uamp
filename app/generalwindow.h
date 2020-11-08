#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <QVector>
#include "windowsetting.h"

class MusicList;
class DTagMusic;
//class WindowSetting {
//public:
//    enum class Sort;
//};
class PlayMusic;

namespace Ui {
class generalWindow;
}

class generalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit generalWindow(QWidget *parent = nullptr);
    ~generalWindow();
    void nextMusic (bool isButton);
    void previousMusic (void);
    void playMusic (const QString& name, const QString& path);
    void resetObjectName(void);
    void showEditTagMusic(const QString& path);
    void cleanListMusic(void);
    void addNewMusicToQueue(const QString& path);
    WindowSetting::Sort getSortType(void);
    void setSort(WindowSetting::Sort type);

private slots:

    void on_action_Setting_triggered();
    void on_action_Add_music_to_Queue_triggered();

private:
    Ui::generalWindow *ui;
    PlayMusic *m_playMusic;
    MusicList *m_MusicList;
    DTagMusic *m_WindowTag;
    WindowSetting *m_WindowSetting;
};

#endif // GENERALWINDOW_H
