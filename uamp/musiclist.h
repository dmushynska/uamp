#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QWidget>

namespace Ui {
class MusicList;
}

class MusicList : public QWidget
{
    Q_OBJECT

public:
    explicit MusicList(QWidget *parent = nullptr);
    ~MusicList();

private:
    Ui::MusicList *ui;
};

#endif // MUSICLIST_H
