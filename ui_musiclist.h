/********************************************************************************
** Form generated from reading UI file 'musiclist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICLIST_H
#define UI_MUSICLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicList
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabListMusic;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *Qwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *layaoutPlayMusicList;
    QSpacerItem *verticalSpacer;
    QWidget *Playlists_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *Playlists;

    void setupUi(QWidget *MusicList)
    {
        if (MusicList->objectName().isEmpty())
            MusicList->setObjectName(QString::fromUtf8("MusicList"));
        MusicList->resize(400, 360);
        verticalLayout = new QVBoxLayout(MusicList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabListMusic = new QTabWidget(MusicList);
        tabListMusic->setObjectName(QString::fromUtf8("tabListMusic"));
        tabListMusic->setFocusPolicy(Qt::WheelFocus);
        tabListMusic->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        Qwidget = new QWidget();
        Qwidget->setObjectName(QString::fromUtf8("Qwidget"));
        Qwidget->setGeometry(QRect(0, 0, 392, 329));
        verticalLayout_3 = new QVBoxLayout(Qwidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        layaoutPlayMusicList = new QVBoxLayout();
        layaoutPlayMusicList->setSpacing(5);
        layaoutPlayMusicList->setObjectName(QString::fromUtf8("layaoutPlayMusicList"));
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layaoutPlayMusicList->addItem(verticalSpacer);


        verticalLayout_3->addLayout(layaoutPlayMusicList);

        scrollArea->setWidget(Qwidget);

        horizontalLayout->addWidget(scrollArea);

        tabListMusic->addTab(tab, QString());
        Playlists_3 = new QWidget();
        Playlists_3->setObjectName(QString::fromUtf8("Playlists_3"));
        verticalLayout_2 = new QVBoxLayout(Playlists_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, -1, 0);
        Playlists = new QVBoxLayout();
        Playlists->setObjectName(QString::fromUtf8("Playlists"));

        verticalLayout_2->addLayout(Playlists);

        tabListMusic->addTab(Playlists_3, QString());

        verticalLayout->addWidget(tabListMusic);


        retranslateUi(MusicList);

        tabListMusic->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MusicList);
    } // setupUi

    void retranslateUi(QWidget *MusicList)
    {
        MusicList->setWindowTitle(QCoreApplication::translate("MusicList", "Form", nullptr));
        tabListMusic->setTabText(tabListMusic->indexOf(tab), QCoreApplication::translate("MusicList", "Queue", nullptr));
        tabListMusic->setTabText(tabListMusic->indexOf(Playlists_3), QCoreApplication::translate("MusicList", "Playlists", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicList: public Ui_MusicList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICLIST_H
