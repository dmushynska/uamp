#include "playlist.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMediaPlaylist>
#include <QtGui>

#include "generalwindow.h"
#include "mytreewidgetitem.h"
#include "ui_playlist.h"

void Playlist::exportPlaylist(QTreeWidgetItem *my) {
    QMediaPlaylist *playlist = new QMediaPlaylist;
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", "*.m3u");
    if (filename != nullptr) {
        for (int i = 0; i < my->childCount(); i++) {
            MyTreeWidgetItem *item = dynamic_cast<MyTreeWidgetItem *>(my->child(i));
            playlist->addMedia(QUrl(item->GetPath()));
        }
        playlist->save(QUrl::fromLocalFile(filename), "m3u");
    }
}

void Playlist::importPlaylist() {
    QString path = QFileDialog::getOpenFileName(this, tr("Open m3u"), "", tr("(*.m3u)"));
    if (path != nullptr) {
        QFile file(path);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString line = in.readLine();
        int added = m_main->m_db->addToPlaylists(path, m_user);
        if (added > 0) {
            MyTreeWidgetItem *my = m_main->m_db->addPlaylist(ui->treeWidget, path, added, m_main);
            while (!line.isNull()) {
                int added_track = m_main->m_db->addToTracks(line);
                if (added_track > 0) {
                    m_main->m_db->addToTrackPlaylists(added_track, added);
                    m_main->m_db->addTrack(line, my, m_main);
                }
                line = in.readLine();
            }
        }
    }
}

void Playlist::clicked() {
    if (ui->treeWidget->currentItem()->parent() != nullptr) {
        MyTreeWidgetItem *my = dynamic_cast<MyTreeWidgetItem *>(ui->treeWidget->currentItem()->parent());
        if (my->GetPath() != nullptr) {
            ui->treeWidget->setStyleSheet("background-image:url(" + my->GetPath() + ".png)");
        } else {
            ui->treeWidget->setStyleSheet("background-image:none;");
        }
    } else {
        MyTreeWidgetItem *my = dynamic_cast<MyTreeWidgetItem *>(ui->treeWidget->currentItem());
        if (my->GetPath() != nullptr) {
            ui->treeWidget->setStyleSheet("background-image:url(" + my->GetPath() + ".png)");
        } else {
            ui->treeWidget->setStyleSheet("background-image:none;");
        }
    }
}

void addToQueue(QTreeWidget *treeWidget, generalWindow *m_main) {
    for (int j = 0; j < treeWidget->currentItem()->childCount(); j++) {
        MyTreeWidgetItem *my = dynamic_cast<MyTreeWidgetItem *>(treeWidget->currentItem()->child(j));
        m_main->addNewMusicToQueue(my->GetPath());
    }
}

void Playlist::clickMouse(const QPoint &point) {
    if (ui->treeWidget->currentItem() != nullptr) {
        QMenu myMenu;
        QPoint globalPos = ui->treeWidget->mapToGlobal(point);

        if (ui->treeWidget->currentItem()->parent() != nullptr) {
            myMenu.addAction("delete track from playlist " + ui->treeWidget->currentItem()->parent()->text(0), this, [this, point]() {
                m_main->m_db->deleteTrack(ui->treeWidget->currentItem()->text(0));
                ui->treeWidget->itemAt(point)->~QTreeWidgetItem();
            });

            MyTreeWidgetItem *item = dynamic_cast<MyTreeWidgetItem *>(ui->treeWidget->currentItem());
            myMenu.addAction("change tags", this, [this, item]() {
                m_main->showEditTagMusic(item->GetPath());
            });

            myMenu.addAction("add track to play", this, [this, item]() {
                m_main->addNewMusicToQueue(item->GetPath());
            });
        } else {
            myMenu.addAction("export playlist" + ui->treeWidget->currentItem()->text(0), this, [this]() {
                exportPlaylist(ui->treeWidget->currentItem());
            });

            myMenu.addAction("import playlist", this, [this]() {
                importPlaylist();
            });

            myMenu.addAction("add new playlist", this, [this]() {
                QString defaultText("new name");
                bool ok;
                QString caseInput = QInputDialog::getText(this, tr("new playlist"), ui->treeWidget->currentItem()->text(0), QLineEdit::Normal, defaultText, &ok);
                if (caseInput != nullptr) {
                    int check = m_main->m_db->addToPlaylists(caseInput, m_user);
                    if (check != -1)
                        m_main->m_db->addPlaylist(ui->treeWidget, caseInput, check, m_main);
                }
            });

            myMenu.addAction("add photo to " + ui->treeWidget->currentItem()->text(0), this, [this]() {
                QString photo = QFileDialog::getOpenFileName(
                    this,
                    tr("Open Track"),
                    "/home",
                    tr("Photo-Files(*.png)"));
                if (photo != nullptr) {
                    MyTreeWidgetItem *my = dynamic_cast<MyTreeWidgetItem *>(ui->treeWidget->currentItem());
                    my->SetPath(ui->treeWidget->currentItem()->text(0));
                    m_main->m_db->insertImage(ui->treeWidget->currentItem()->text(0), photo);
                    m_main->m_db->saveImage(ui->treeWidget->currentItem()->text(0));
                    clicked();
                }
            });
            myMenu.addAction("delete photo from " + ui->treeWidget->currentItem()->text(0), this, [this]() {
                m_main->m_db->deleteImage(ui->treeWidget->currentItem()->text(0));
                MyTreeWidgetItem *my = dynamic_cast<MyTreeWidgetItem *>(ui->treeWidget->currentItem());
                QFile(my->GetPath()).remove();
                my->SetPath(nullptr);
                ui->treeWidget->setStyleSheet("background-image:none;");
            });

            myMenu.addAction("add track to " + ui->treeWidget->currentItem()->text(0), this, [this]() {
                QString track = QFileDialog::getOpenFileName(
                    this,
                    tr("Open Track"),
                    "/home",
                    tr("Audio-Files(*.mp3)"));

                if (track != nullptr) {
                    if (m_main->m_db->addToTrackPlaylists(m_main->m_db->addToTracks(track), m_main->m_db->NumbPlaylist(ui->treeWidget->currentItem()->text(0)))) {
                        m_main->m_db->addTrack(track, ui->treeWidget->currentItem(), m_main);
                    }
                }
            });

            myMenu.addAction("delete playlist " + ui->treeWidget->currentItem()->text(0), this, [this, point]() {
                m_main->m_db->deletePlaylists(ui->treeWidget->currentItem()->text(0));
                ui->treeWidget->itemAt(point)->~QTreeWidgetItem();
                if (ui->treeWidget->topLevelItemCount() == 0) {
                    if (m_main->m_db->addToPlaylists("New Playlist", m_user) != -1)
                        m_main->m_db->addPlaylist(ui->treeWidget, "New Playlist", m_main->m_db->NumbPlaylist("New Playlist"), m_main);
                }
            });

            myMenu.addAction("play", this, [this]() {
                m_main->cleanListMusic();
                addToQueue(ui->treeWidget, m_main);
            });

            myMenu.addAction("add playlist to play", this, [this]() {
                addToQueue(ui->treeWidget, m_main);
            });

            myMenu.addAction("rename playlist " + ui->treeWidget->currentItem()->text(0), this, [this]() {
                QString defaultText("new name");
                bool ok;

                QString caseInput = QInputDialog::getText(this, tr("Rename"), ui->treeWidget->currentItem()->text(0), QLineEdit::Normal, defaultText, &ok);
                if (caseInput != nullptr && m_main->m_db->renamePlaylist(ui->treeWidget->currentItem()->text(0), caseInput)) {
                    ui->treeWidget->currentItem()->setText(0, caseInput);
                }
            });
        }
        myMenu.exec(globalPos);
    }
}

Playlist::Playlist(QWidget *parent) : QWidget(parent),
                                      ui(new Ui::Playlist) {
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow *>(parent);
    m_main->m_db->createDataBase();
    m_main->m_db->SignUp("users", "1234");
    m_user = "users";
    if (ui->treeWidget->topLevelItemCount() == 0)
        m_main->m_db->addToPlaylists("New Playlist", m_user);
    m_main->m_db->selectPlaylistFromDataBase(ui->treeWidget, m_user, m_main);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, &Playlist::clickMouse);
    connect(ui->treeWidget, &QTreeWidget::clicked, this, &Playlist::clicked);
}

Playlist::~Playlist() {
    delete ui;
}
