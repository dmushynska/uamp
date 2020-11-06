#ifndef DTAGMUSIC_H
#define DTAGMUSIC_H

#include <QDialog>
#include <taglib/tag.h>
#include <taglib/fileref.h>

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


private:
    Ui::DTagMusic *ui;
};

#endif // DTAGMUSIC_H
