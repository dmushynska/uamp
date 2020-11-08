#include "playlist.h"
#include "ui_playlist.h"
#include "mytreewidgetitem.h"
#include "generalwindow.h"

#include <QFileDialog>
#include <QInputDialog>

void Playlist::clickMouse(const QPoint &point) {
    QMenu myMenu;
    QPoint globalPos = ui->treeWidget->mapToGlobal(point);

    if(ui->treeWidget->currentItem()->parent() != nullptr) {
        myMenu.addAction("delete track from playlist " + ui->treeWidget->currentItem()->parent()->text(0), this, [this, point]() {
            m_db.deleteTrack(ui->treeWidget->currentItem()->text(0));
            ui->treeWidget->itemAt(point)->~QTreeWidgetItem();
        });
// Функции Серёги
        MyTreeWidgetItem *item = dynamic_cast<MyTreeWidgetItem *> (ui->treeWidget->currentItem());
       myMenu.addAction("change tags", this, [this, item]() {
           m_main->showEditTagMusic(item->GetPath());
        //    qDebug() << "change tags";
       });

       myMenu.addAction("add track to play", this, [this, item]() {
           qDebug() << "add track to play";
           m_main->addNewMusicToQueue(item->GetPath());
       });
    }
    else {
        myMenu.addAction("add new playlist", this, [this]() {
            QString defaultText("new name");
            bool ok;QString caseInput = QInputDialog::getText(this, tr("new playlist"), ui->treeWidget->currentItem()->text(0), QLineEdit::Normal, defaultText, &ok);
            if (caseInput != nullptr) {
                int check =  m_db.addToPlaylists(caseInput);
                if (check != -1)
                    m_db.addPlaylist(ui->treeWidget, caseInput, check);
            }
        });

        myMenu.addAction("add track to " + ui->treeWidget->currentItem()->text(0), this, [this]() {
            QString track = QFileDialog::getOpenFileName(
                            this,
                            tr("Open Track"),
                            "/home",
                            tr("Audio-Files(*.mp3)"));

            if (track != nullptr) {
                if (m_db.addToTrackPlaylists(m_db.addToTracks("name"), m_db.NumbPlaylist(ui->treeWidget->currentItem()->text(0)))) {
                    m_db.addTrack(track, ui->treeWidget->currentItem());
                }
            }
        });

        myMenu.addAction("delete playlist " + ui->treeWidget->currentItem()->text(0), this, [this, point]() {
            m_db.deletePlaylists(ui->treeWidget->currentItem()->text(0));
            ui->treeWidget->itemAt(point)->~QTreeWidgetItem();
            if (ui->treeWidget->topLevelItemCount() == 0) {
                if (m_db.addToPlaylists("New Playlist") != -1)
                    m_db.addPlaylist(ui->treeWidget, "New Playlist", m_db.NumbPlaylist("New Playlist"));
            }
        });
// Функции Серёги
//        myMenu.addAction("play", this, []() {
//            qDebug() << "play";
//        });

//        myMenu.addAction("add playlist to play", this, []() {
//            qDebug() << "add playlist to play";
//        });

        myMenu.addAction("rename playlist " + ui->treeWidget->currentItem()->text(0), this, [this]() {
            QString defaultText("new name");
            bool ok;

            QString caseInput = QInputDialog::getText(this, tr("Rename"), ui->treeWidget->currentItem()->text(0), QLineEdit::Normal, defaultText, &ok);
            if (caseInput != nullptr && m_db.renamePlaylist(ui->treeWidget->currentItem()->text(0), caseInput)) {
                ui->treeWidget->currentItem()->setText(0, caseInput);
            }
        });
    }
    myMenu.exec(globalPos);
}

Playlist::Playlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Playlist)
{
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow*>(parent);
   m_db.createDataBase();
   m_db.addToPlaylists("New Playlist");
    m_db.selectPlaylistFromDataBase(ui->treeWidget);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, &Playlist::clickMouse);
}

Playlist::~Playlist()
{
    delete ui;
}
