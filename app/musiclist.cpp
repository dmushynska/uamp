#include "musiclist.h"
#include "ui_musiclist.h"
#include "musicwidget.h"
#include "generalwindow.h"
#include <QMenu>
#include <QFileDialog>

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

MusicList::~MusicList()
{
    delete ui;
}

