#include "windowsetting.h"
#include "ui_windowsetting.h"
#include "generalwindow.h"
#include <QtDebug>

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
}

WindowSetting::~WindowSetting()
{
    delete ui;
}

void WindowSetting::on_pushButton_Save_clicked()
{
    this->m_TypeNextMusic = static_cast <nextMusic>(ui->TypePlay->currentIndex());
    if (this->m_TypeSort != static_cast <Sort>(ui->TypeSort->currentIndex())) {
        this->m_TypeSort = static_cast <Sort>(ui->TypeSort->currentIndex());
        this->m_main->setSort(this->m_TypeSort);
    }
}

void WindowSetting::on_pushButton_Cancel_clicked()
{
    ui->TypePlay->setCurrentIndex(static_cast<int>(this->m_TypeNextMusic));
    ui->TypeSort->setCurrentIndex(static_cast<int>(this->m_TypeSort));
}

WindowSetting::nextMusic WindowSetting::getTypeNext() {
    return this->m_TypeNextMusic;
}

WindowSetting::Sort WindowSetting::getTypeSort(void) {
    return this->m_TypeSort;
}
