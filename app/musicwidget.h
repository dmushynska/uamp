#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <iostream>
#include <QEvent>
#include <QMouseEvent>
#include <QtDebug>
#include <QStyleOption>
#include <QPainter>
#include <QFileSystemWatcher>

#include <taglib/tag.h>
#include <taglib/fileref.h>

namespace Ui {
class musicWidget;
}

class generalWindow;

class musicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit musicWidget(QWidget *parent = nullptr);
    ~musicWidget();


    void paintEvent(QPaintEvent *);
    bool setMusic(const QString& path);
    QString getPathMusic(void);
    bool eventFilter(QObject *obj, QEvent *event);
    void clickDubleWidget(void);
    void fileChanged(const QString &path);
signals:
    void clicked();
    void rightClicked();
    void dubleClick();

//protected:
//    void mousePressEvent(QMouseEvent* event);

private:
    Ui::musicWidget *ui;
    generalWindow *m_main;
    QString m_path;
    QFileSystemWatcher m_ChekFile;

};

#endif // MUSICWIDGET_H
