#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QDebug>
#include <QMenu>
#include "database.h"

class generalWindow;

namespace Ui {
class Playlist;
}

class Playlist : public QWidget
{
    Q_OBJECT

public:
    explicit Playlist(QWidget *parent = nullptr);
    ~Playlist();
    void clickMouse(const QPoint &point);
    void clicked();
    void exportPlaylist(QTreeWidgetItem *my);
    void importPlaylist();
    QString m_user;
private:
    Ui::Playlist *ui;
    DataBase m_db;
    generalWindow *m_main;
    
};

#endif // PLAYLIST_H
