#include "playmusic.h"
#include "windowsetting.h"
#include "generalwindow.h"
#include "ui_generalwindow.h"
#include "musiclist.h"
#include "dtagmusic.h"



generalWindow::generalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::generalWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window);
    m_playMusic = new PlayMusic(this);
    this->ui->generalLayout->addWidget(m_playMusic);
    m_MusicList = new MusicList(this);
    this->ui->horizontalLayout->addWidget(m_MusicList);
    m_WindowTag = new DTagMusic(this);
    m_WindowSetting = new WindowSetting(this);
}

generalWindow::~generalWindow()
{
    delete ui;
    delete m_playMusic;
    delete m_MusicList;
    delete m_WindowTag;
    delete m_WindowSetting;
}


void generalWindow::addNewMusicToQueue(const QString& path) {
    this->m_MusicList->addNewMusic(path);
}

void generalWindow::showEditTagMusic(const QString& path) {
    m_WindowTag->setTagWindow(path);
    m_WindowTag->show();
}
void generalWindow::resetObjectName(void) {
    this->m_MusicList->resetObjectName();
}

void generalWindow::playMusic (const QString& name, const QString& path) {
    this->m_playMusic->setNewMusicAndPlay(name, path);
}

void generalWindow::nextMusic (void) {
    m_MusicList->nextMusic();
}

void generalWindow::cleanListMusic(void) {
    m_MusicList->cleanList();
}

void generalWindow::previousMusic (void) {
//    m_MusicList->cleanList();
    m_MusicList->previousMusic();
}

#include <QDir>
#include <QFileDialog>


void generalWindow::on_action_Add_music_to_Queue_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Track"), QDir::currentPath(),
                               tr("Audio-Files(*.mp3 *.wav *.mp4 *.flac)"));
    if (path.size()) {
        this->addNewMusicToQueue(path);
    }
}

void generalWindow::on_action_Setting_triggered()
{
    m_WindowSetting->show();
}
