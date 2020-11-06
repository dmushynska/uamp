#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QWidget>

namespace Ui {
class MusicList;
}

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
//    int getMax

private:
    Ui::MusicList *ui;
    generalWindow *m_main;
};

#endif // MUSICLIST_H
