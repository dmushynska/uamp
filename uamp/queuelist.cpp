#include "queuelist.h"
#include "ui_queuelist.h"
#include <iostream>

QueueList::QueueList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueueList)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    connect(ui->tableWidget, &QHeaderView::clicked, this, []{
        std::cout << "222" << std::endl;
    });
}

QueueList::~QueueList()
{
    delete ui;
}
