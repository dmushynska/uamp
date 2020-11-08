#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QWidget>
#include "windowsetting.h"

namespace Ui {
class MusicList;
}

class musicWidget;
class generalWindow;


class MusicList : public QWidget
{
    Q_OBJECT

public:
    explicit MusicList(QWidget *parent = nullptr);
    ~MusicList();
    void resetObjectName(void);
    void nextMusic (void);
    void previousMusic (void);
    void cleanList (void);
    void addNewMusic(const QString& path);
    void customContextMenuRequested(const QPoint &pos);
    void playRandom(void);
//    int getMax
private:
    void insertWindgetPos(musicWidget *newMusic, WindowSetting::Sort type);

private:
    Ui::MusicList *ui;
    generalWindow *m_main;
};

#endif // MUSICLIST_H
