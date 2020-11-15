#ifndef DTAGMUSIC_H
#define DTAGMUSIC_H

#include <QDialog>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/mpeg/id3v2/id3v2.h>
#include <taglib/mpeg/id3v2/id3v2frame.h>
#include <taglib/mpeg/id3v2/id3v2tag.h>
#include <taglib/mpeg/mpegfile.h>
#include <taglib/mpeg/id3v2/id3v2frame.h>
#include <taglib/mpeg/id3v2/id3v2header.h>
#include <taglib/mpeg/id3v2/frames/attachedpictureframe.h>

namespace Ui {
class DTagMusic;
}

class DTagMusic : public QDialog
{
    Q_OBJECT

public:
    explicit DTagMusic(QWidget *parent = nullptr);
    void setTagWindow(const QString& path);
    void checkBoxChenge();
    void saveChengeTag(void);
    ~DTagMusic();


private slots:
    void on_ButtonChengeImg_clicked();

private:
    Ui::DTagMusic *ui;
};

#endif // DTAGMUSIC_H
