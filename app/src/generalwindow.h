#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <QVector>
#include <QFileInfo>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include "windowsetting.h"

class MusicList;
class DTagMusic;
class PlayMusic;
class DataBase;
class radio;

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
    QString GetFileName(const QString &path);
    WindowSetting::Sort getSortType(void);
    void setSort(WindowSetting::Sort type);
    void setSortType(WindowSetting::Sort type);
    void saveSettings(void);
    void loadingSettings(void);
    void setPlayMusic(const QString& name, const QString& path);
    void pause(void);

private slots:

    void on_action_Setting_triggered();
    void on_action_Add_music_to_Queue_triggered();

    void on_action_Next_triggered();

    void on_action_Previous_triggered();

    void on_action_Play_Pause_triggered();

    void on_action_Rewind_triggered();

    void on_action_Fast_forwsrd_triggered();
public:
    DataBase *m_db;
private:
    Ui::generalWindow *ui;
    PlayMusic *m_playMusic;
    MusicList *m_MusicList;
    DTagMusic *m_WindowTag;
    WindowSetting *m_WindowSetting;
};

#endif // GENERALWINDOW_H
