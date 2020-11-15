#include "musicwidget.h"
#include "ui_musicwidget.h"
#include "generalwindow.h"
#include "musiclist.h"
#include <QtDebug>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>

musicWidget::musicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicWidget)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    m_main = qobject_cast<generalWindow*>(parent);
    connect(this, &musicWidget::dubleClick, this, &musicWidget::clickDubleWidget);
}

void musicWidget::clickDubleWidget(void) {
    m_main->resetObjectName();
    setObjectName("Play");
    this->m_main->playMusic(this->ui->nameMusic->text(), this->m_path);
    this->style()->unpolish(this);
    this->style()->polish(this);
}

void musicWidget::setStylePlay(void) {
    setObjectName("Play");
    this->m_main->setPlayMusic(this->ui->nameMusic->text(), this->m_path);
    this->style()->unpolish(this);
    this->style()->polish(this);
}

bool musicWidget::setMusic(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox messageBox;
        messageBox.critical(this,"Error","Permision ERROR!");
        messageBox.setFixedSize(500,200);
        file.close();
        return false;
    }
    file.close();
    TagLib::FileRef f(path.toUtf8().constData());
    if (!f.isNull()) {
        ui->Artist->setText(f.tag()->artist().toCString());
        int time = f.file()->audioProperties()->lengthInSeconds();
        ui->time->setText(QString::number(time / 60) + ":" + QString::number(time % 60));
    }
    ui->nameMusic->setText(m_main->GetFileName(path));
    m_ChekFile.addPath(path);
    connect(&m_ChekFile, &QFileSystemWatcher::fileChanged, this, &musicWidget::fileChanged);
    m_path = path;
    return true;
}

void musicWidget::fileChanged(const QString &path) {
    if (m_ChekFile.files().contains(path)) {
        TagLib::FileRef f(path.toUtf8().constData());
        ui->Artist->setText(f.tag()->artist().toCString());
        ui->nameMusic->setText(m_main->GetFileName(path));
        m_main->setSort(this->m_main->getSortType());
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(this,"Info","Not found file " + path);
        messageBox.setFixedSize(500,200);
        this->~musicWidget();
    }
}

QString musicWidget::getPathMusic(void) {
    return m_path;
}

musicWidget::~musicWidget()
{
    delete ui;
}

void musicWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool musicWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this) {
        if (event->type() == QEvent::MouseButtonDblClick &&  static_cast<QMouseEvent*>(event)->button() == Qt::LeftButton) {
            emit dubleClick();
            return  true;

        }
    } else {
        return eventFilter(obj, event);
    }
    return false;
};
