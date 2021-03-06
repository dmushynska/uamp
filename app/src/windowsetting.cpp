#include "windowsetting.h"
#include "ui_windowsetting.h"
#include "generalwindow.h"
#include <QtDebug>
#include "database.h"

WindowSetting::WindowSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSetting)
{
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow*>(parent);
    this->setModal(true);
    connect(this, &WindowSetting::dialogClosed, this, &WindowSetting::on_pushButton_Cancel_clicked);
    this->m_TypeNextMusic = static_cast <nextMusic>(ui->TypePlay->currentIndex());
    this->m_TypeSort = static_cast <Sort>(ui->TypeSort->currentIndex());
    connect(&m_time, &QTimer::timeout, this, &WindowSetting::timeoutResetTimer);
    connect(&m_timeOf, &QTimer::timeout, m_main, &QApplication::closeAllWindows);

    m_time.setInterval(1000);
}

WindowSetting::~WindowSetting()
{
    m_main->m_db->addTypeSort(ui->TypePlay->currentIndex(), ui->TypeSort->currentIndex());

    delete ui;
}

void WindowSetting::on_pushButton_Save_clicked()
{
    this->m_TypeNextMusic = static_cast <nextMusic>(ui->TypePlay->currentIndex());
    if (this->m_TypeSort != static_cast <Sort>(ui->TypeSort->currentIndex())) {
        this->m_TypeSort = static_cast <Sort>(ui->TypeSort->currentIndex());
        this->m_main->setSort(this->m_TypeSort);
    }
    this->hide();
}

void WindowSetting::loadingSettings(DataBase *db) {
    ui->TypeSort->setCurrentIndex(db->GetSort());
    ui->TypePlay->setCurrentIndex(db->GetType());
    this->m_TypeNextMusic = static_cast <nextMusic>(ui->TypePlay->currentIndex());
    this->m_TypeSort = static_cast <Sort>(ui->TypeSort->currentIndex());
    this->m_main->setSort(this->m_TypeSort);
}

void WindowSetting::timeoutResetTimer(void) {
    if (!this->isHidden()) {
        int time = this->m_timeOf.remainingTime() / 1000;
        ui->TimeToShotdown->setText(QString::number(time / 60) + ":" + QString::number(time % 60));
    }
}

void WindowSetting::on_pushButton_Cancel_clicked()
{
    ui->TypePlay->setCurrentIndex(static_cast<int>(this->m_TypeNextMusic));
    ui->TypeSort->setCurrentIndex(static_cast<int>(this->m_TypeSort));
    this->hide();
}

WindowSetting::nextMusic WindowSetting::getTypeNext() {
    return this->m_TypeNextMusic;
}

WindowSetting::Sort WindowSetting::getTypeSort(void) {
    return this->m_TypeSort;
}

void WindowSetting::setSortType(WindowSetting::Sort type) {
    if (Sort::random == type)
        this->m_TypeSort = Sort::user;
    else {
        this->m_TypeSort = type;
    }
    ui->TypeSort->setCurrentIndex(static_cast<int>(this->m_TypeSort));
}

void WindowSetting::on_pushButtonStart_clicked()
{
    switch (this->ui->Times->currentIndex()) {
        case 0:
            m_time.stop();
            m_timeOf.stop();
            ui->TimeToShotdown->setText("Off");
            break;
        case 1:
            m_time.start();
            m_timeOf.setInterval(1*60*1000);
            m_timeOf.start();
            break;
        case 2:
            m_time.start();
            m_timeOf.setInterval(5*60*1000);
            m_timeOf.start();
            break;
        case 3:
            m_time.start();
            m_timeOf.setInterval(10*60*1000);
            m_timeOf.start();
            break;
        case 4:
            m_time.start();
            m_timeOf.setInterval(15*60*1000);
            m_timeOf.start();
            break;
    }
}
