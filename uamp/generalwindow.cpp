#include "generalwindow.h"
#include "ui_generalwindow.h"
#include "musiclist.h"

generalWindow::generalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::generalWindow)
{
    ui->setupUi(this);
    m_playMusic = new PlayMusic(this);
    this->ui->generalLayout->addWidget(m_playMusic);
    m_MusicList = new MusicList;
    this->ui->horizontalLayout->addWidget(m_MusicList);

}


generalWindow::~generalWindow()
{
    delete ui;
    delete m_playMusic;
    delete m_MusicList;
}
