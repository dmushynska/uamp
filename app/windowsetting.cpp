#include "windowsetting.h"
#include "ui_windowsetting.h"

WindowSetting::WindowSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSetting)
{
    ui->setupUi(this);
    this->setModal(true);
}

WindowSetting::~WindowSetting()
{
    delete ui;
}
