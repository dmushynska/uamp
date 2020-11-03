#include "musiclist.h"
#include "ui_musiclist.h"
#include "musicwidget.h"
#include "generalwindow.h"

MusicList::MusicList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicList)
{
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow*>(parent);
    ui->layaoutPlayMusicList->insertWidget(0, new musicWidget(m_main));
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->setMusic("/Users/solianovsk/Desktop/2L-110_04_stereo.mqa.flac");
    ui->layaoutPlayMusicList->insertWidget(0, new musicWidget(m_main));
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->setMusic("/Users/solianovsk/Desktop/3285.wav");
    ui->layaoutPlayMusicList->insertWidget(0, new musicWidget(m_main));
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->setMusic("/Users/solianovsk/Desktop/videoplayback.mp4");
}

void MusicList::resetObjectName(void) {

    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
            ui->layaoutPlayMusicList->itemAt(i)->widget()->setObjectName(nullptr);
            ui->layaoutPlayMusicList->itemAt(i)->widget()->style()->unpolish(ui->layaoutPlayMusicList->itemAt(i)->widget());
            ui->layaoutPlayMusicList->itemAt(i)->widget()->style()->polish(ui->layaoutPlayMusicList->itemAt(i)->widget());
            return;
        }
    }
}


void MusicList::nextMusic (void) {
    if (ui->layaoutPlayMusicList->count() < 3)
        return;
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
            if (i == ui->layaoutPlayMusicList->count() - 2) {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->clickDubleWidget();
            }
            else {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(++i)->widget())->clickDubleWidget();
            }
            return;
        }
    }
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->clickDubleWidget();
}

void MusicList::previousMusic (void) {
    if (ui->layaoutPlayMusicList->count() < 3)
        return;
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
            if (i == 0) {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(ui->layaoutPlayMusicList->count() - 2)->widget())->clickDubleWidget();
            }
            else {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(--i)->widget())->clickDubleWidget();
            }
            return;
        }
    }
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->clickDubleWidget();
}

MusicList::~MusicList()
{
    delete ui;
}

