#include "musiclist.h"
#include "ui_musiclist.h"
#include "musicwidget.h"
#include "generalwindow.h"
#include <QMenu>
#include <QFileDialog>
#include <taglib/tag.h>
#include <taglib/fileref.h>

MusicList::MusicList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicList)
{
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow*>(parent);
    ui->tab->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tab, &QWidget::customContextMenuRequested, this, &MusicList::customContextMenuRequested);
//    {
//        QMenu rightMenu;
//        rightMenu.addAction("Add new music", this, [this] {
////            qDebug() << ui->layaoutPlayMusicList->
//            QString path = QFileDialog::getOpenFileName(this, tr("Open Track"), QDir::currentPath(),
//                            tr("Audio-Files(*.mp3 *.wav *.mp4 *.flac)"));
//            if (path.size()) {
//                m_main->addNewMusicToQueue(path);
//            }
//        });
//        rightMenu.show();
//        rightMenu.exec(QCursor::pos());
//    });
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

void MusicList::cleanList (void) {
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1;) {
        delete ui->layaoutPlayMusicList->takeAt(i)->widget();
    }
}

void MusicList::addNewMusic(const QString& path) {
    musicWidget *newMusic = new musicWidget(m_main);
    if (!newMusic->setMusic(path)) {
        delete newMusic;
    }
    else {
        ui->layaoutPlayMusicList->insertWidget(ui->layaoutPlayMusicList->count() - 1, newMusic);
    }
}

void MusicList::insertWindgetPos(musicWidget *newMusic, WindowSetting::Sort type) {
    if (type == WindowSetting::Sort::user) {
        ui->layaoutPlayMusicList->insertWidget(ui->layaoutPlayMusicList->count() - 1, newMusic);
        return;
    }
    TagLib::FileRef newFile(newMusic->getPathMusic().toUtf8().constData());
    for (int i = 0; i < ui->layaoutPlayMusicList->count() - 1; i++) {
        TagLib::FileRef f(qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(ui->layaoutPlayMusicList->count() - 2)->widget())->getPathMusic().toUtf8().constData());
        switch (type) {
            case WindowSetting::Sort::album:
                if (newFile.tag()->album().toCString() < f.tag()->artist().toCString()) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::artist:
                if (newFile.tag()->artist().toCString() < f.tag()->artist().toCString()) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::title:
                if (newFile.tag()->title().toCString() < f.tag()->artist().toCString()) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::genre:
                if (newFile.tag()->genre().toCString() < f.tag()->artist().toCString()) {
                    ui->layaoutPlayMusicList->insertWidget(i, newMusic);
                    return;
                }
                break;
            case WindowSetting::Sort::user:
                return;
        }
//        if (ui->layaoutPlayMusicList->itemAt(i)->widget()->objectName() == "Play") {
//            if (i == 0) {
//                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(ui->layaoutPlayMusicList->count() - 2)->widget())->clickDubleWidget();
//            }
//            else {
//                qobject_cast<musicWidget *>(ui->layaoutPlayMusicList->itemAt(--i)->widget())->clickDubleWidget();
//            }
//            return;
     }
}


MusicList::~MusicList()
{
    delete ui;
}

