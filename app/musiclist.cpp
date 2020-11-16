#include "musiclist.h"

#include <taglib/fileref.h>
#include <taglib/tag.h>

#include <QFileDialog>
#include <QMenu>

#include "generalwindow.h"
#include "musicwidget.h"
#include "playlist.h"
#include "radio.h"
#include "ui_musiclist.h"

MusicList::MusicList(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::MusicList) {
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow *>(parent);
    ui->tab->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tab, &QWidget::customContextMenuRequested, this, &MusicList::customContextMenuRequested);
    ui->Playlists->addWidget(new Playlist(m_main));
    m_radio = new radio(m_main);
    ui->radio->addWidget(m_radio);
}

void MusicList::stopRadio(void) {
    m_radio->pause();
}

void MusicList::loadingSettings(DataBase *db) {
    QList<QString> list = db->GetSavePlaylist();
    int i = 0;
    for (auto it = list.begin(); list.end() != it; it++, i++) {
        if (addNewMusic(*it) && i == db->GetId())
            qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(this->ui->layaoutPlayMusicList->count() - 2)->widget())->setStylePlay();
    }
}

void MusicList::playRandom(void) {
    if (this->ui->layaoutPlayMusicList->count() != 1) {
        int pos = (rand() % (this->ui->layaoutPlayMusicList->count() - 1));
        qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(pos)->widget())->clickDubleWidget();
    }
}

void MusicList::customContextMenuRequested(const QPoint &pos) {
    QMenu rightMenu;
    rightMenu.addAction("Add new music", this, [this] {
        QString path = QFileDialog::getOpenFileName(this, tr("Open Track"), QDir::currentPath(),
                                                    tr("Audio-Files(*.mp3 *.wav *.mp4 *.flac)"));
        if (path.size()) {
            m_main->addNewMusicToQueue(path);
        }
    });
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        if (ui->layaoutPlayMusicList->itemAt(i)->geometry().contains(pos)) {
            rightMenu.addAction("Delete music to Queue", this, [this, i] {
                delete ui->layaoutPlayMusicList->takeAt(i)->widget();
            });
            rightMenu.addAction("Show tag info music", this, [this, i] {
                this->m_main->showEditTagMusic(qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(i)->widget())->getPathMusic());
            });
            break;
        }
    }
    rightMenu.show();
    rightMenu.exec(QCursor::pos());
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

void MusicList::nextMusic(void) {
    if (ui->layaoutPlayMusicList->count() < 3)
        return;
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
            if (i == ui->layaoutPlayMusicList->count() - 2) {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->clickDubleWidget();
            } else {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(++i)->widget())->clickDubleWidget();
            }
            return;
        }
    }
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->clickDubleWidget();
}

void MusicList::previousMusic(void) {
    if (ui->layaoutPlayMusicList->count() < 3)
        return;
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
            if (i == 0) {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(ui->layaoutPlayMusicList->count() - 2)->widget())->clickDubleWidget();
            } else {
                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(--i)->widget())->clickDubleWidget();
            }
            return;
        }
    }
    qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(0)->widget())->clickDubleWidget();
}

void MusicList::cleanList(void) {
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1;) {
        delete ui->layaoutPlayMusicList->takeAt(i)->widget();
    }
}

bool MusicList::addNewMusic(const QString &path) {
    musicWidget *newMusic = new musicWidget(m_main);
    if (!newMusic->setMusic(path)) {
        delete newMusic;
        return false;
    } else {
        this->insertWindgetPos(newMusic, this->m_main->getSortType());
    }
    return true;
}

void MusicList::insertWindgetPos(musicWidget *newMusic, WindowSetting::Sort type) {
    if (type == WindowSetting::Sort::user) {
        ui->layaoutPlayMusicList->insertWidget(ui->layaoutPlayMusicList->count() - 1, newMusic);
        return;
    }
    TagLib::FileRef newFile(newMusic->getPathMusic().toUtf8().constData());
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        TagLib::FileRef f(qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(i)->widget())->getPathMusic().toUtf8().constData());
        switch (type) {
            case WindowSetting::Sort::album:
                if (QString(newFile.tag()->album().toCString()) < QString(f.tag()->album().toCString())) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::artist:
                if (QString(newFile.tag()->artist().toCString()) < QString(f.tag()->artist().toCString())) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::title:
                if (QString(newFile.tag()->title().toCString()) < QString(f.tag()->title().toCString())) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::genre:
                if (QString(newFile.tag()->genre().toCString()) < QString(f.tag()->genre().toCString())) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::random: {
                int pos = (rand() % (this->ui->layaoutPlayMusicList->count()));
                ui->layaoutPlayMusicList->insertWidget(pos, newMusic);
                return;
            } break;
            case WindowSetting::Sort::user:
                return;
        }
    }
    ui->layaoutPlayMusicList->insertWidget(ui->layaoutPlayMusicList->count() - 1, newMusic);
}

void MusicList::chengeTypeSort(WindowSetting::Sort type) {
    if (ui->layaoutPlayMusicList->count() != 1 && type != WindowSetting::Sort::user) {
        QWidget *temp = ui->layaoutPlayMusicList->takeAt(0)->widget();
        this->chengeTypeSort(type);
        insertWindgetPos(qobject_cast<musicWidget *>(temp), type);
    }
}

MusicList::~MusicList() {
    m_main->m_db->deleteSavePlaylist();
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        m_main->m_db->addIntoSavePlaylist(qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(i)->widget())->getPathMusic());
        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
            m_main->m_db->addId(i);
        }
    }
    delete ui;
    delete m_radio;
}
