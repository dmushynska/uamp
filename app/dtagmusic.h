#ifndef DTAGMUSIC_H
#define DTAGMUSIC_H

#include <QDialog>

namespace Ui {
class DTagMusic;
}

class DTagMusic : public QDialog
{
    Q_OBJECT

public:
    explicit DTagMusic(QWidget *parent = nullptr);
    void setTagWindow(const QString& path);
    ~DTagMusic();

private:
    Ui::DTagMusic *ui;
};

#endif // DTAGMUSIC_H
