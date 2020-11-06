#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <iostream>
#include <QEvent>
#include <QMouseEvent>
#include <QtDebug>
#include <QStyleOption>
#include <QPainter>

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
    bool setMusic(const QString& name);
    QString getMusic(void);
    bool eventFilter(QObject *obj, QEvent *event);
    void clickDubleWidget(void);
signals:
    void clicked();
    void rightClicked();
    void dubleClick();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::musicWidget *ui;
    generalWindow *m_main;
    QString m_path;
};

#endif // MUSICWIDGET_H
