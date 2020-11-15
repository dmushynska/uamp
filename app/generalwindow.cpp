#include "generalwindow.h"

#include <ctime>

#include "dtagmusic.h"
#include "musiclist.h"
#include "playmusic.h"
#include "ui_generalwindow.h"
#include "windowsetting.h"

QString generalWindow::GetFileName(const QString& path) {
    TagLib::FileRef f(path.toUtf8().constData());
    if (!f.isNull() && QString(f.tag()->title().toCString()).size() != 0) {
        return f.tag()->title().toCString();
    }
    QFile file(path);
    QFileInfo fileInfo(file.fileName());
    QString filename(fileInfo.fileName());
    return filename;
}

generalWindow::generalWindow(QWidget* parent) : QMainWindow(parent),
                                                ui(new Ui::generalWindow) {
    srand(static_cast<unsigned int>(time(0)));
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window);
    m_playMusic = new PlayMusic(this);
    this->ui->generalLayout->addWidget(m_playMusic);
    m_MusicList = new MusicList(this);
    this->ui->horizontalLayout->addWidget(m_MusicList);
    m_WindowTag = new DTagMusic(this);
    m_WindowSetting = new WindowSetting(this);
}

generalWindow::~generalWindow() {
    delete ui;
    delete m_playMusic;
    delete m_MusicList;
    delete m_WindowTag;
    delete m_WindowSetting;
}

void generalWindow::setSort(WindowSetting::Sort type) {
    this->m_MusicList->chengeTypeSort(type);
}

WindowSetting::Sort generalWindow::getSortType(void) {
    return m_WindowSetting->getTypeSort();
}


void generalWindow::setSortType(WindowSetting::Sort type) {
    this->m_MusicList->chengeTypeSort(type);
    m_WindowSetting->setSortType(type);
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

void generalWindow::playMusic(const QString& name, const QString& path) {
    this->m_playMusic->setNewMusicAndPlay(name, path);
}

void generalWindow::nextMusic(bool isButton) {
    if (isButton) {
        m_MusicList->nextMusic();
        return;
    }
    WindowSetting::nextMusic type = this->m_WindowSetting->getTypeNext();
    if (type == WindowSetting::nextMusic::loopQueue)
        m_MusicList->nextMusic();
    else if (type == WindowSetting::nextMusic::repeatSong)
        m_playMusic->play();
    else if (type == WindowSetting::nextMusic::onePlay)
        return;
    else if (type == WindowSetting::nextMusic::randomMusic)
        m_MusicList->playRandom();
}

void generalWindow::cleanListMusic(void) {
    m_MusicList->cleanList();
}

void generalWindow::previousMusic(void) {
    m_MusicList->previousMusic();
}

#include <QDir>
#include <QFileDialog>

void generalWindow::on_action_Add_music_to_Queue_triggered() {
    QString path = QFileDialog::getOpenFileName(this, tr("Open Track"), QDir::currentPath(),
                                                tr("Audio-Files(*.mp3 *.wav *.mp4 *.flac)"));
    if (path.size()) {
        this->addNewMusicToQueue(path);
    }
}

void generalWindow::on_action_Setting_triggered() {
    m_WindowSetting->show();
}

void generalWindow::on_action_Next_triggered()
{
    nextMusic(true);
}

void generalWindow::on_action_Previous_triggered()
{
    previousMusic();
}

void generalWindow::on_action_Play_Pause_triggered()
{
    m_playMusic->clickShortKeyPlay();
}


void generalWindow::on_action_Rewind_triggered()
{
    m_playMusic->clickShortKeyRewind();
}

void generalWindow::on_action_Fast_forwsrd_triggered()
{
    m_playMusic->clickShortKeyFastForward();
}
