/********************************************************************************
** Form generated from reading UI file 'generalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALWINDOW_H
#define UI_GENERALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_generalWindow
{
public:
    QAction *action_Add_music_to_Queue;
    QAction *action_Setting;
    QAction *action_Stop;
    QAction *action_Next;
    QAction *action_Previous;
    QAction *action_Rewind;
    QAction *action_Fast_forwsrd;
    QAction *action_Play_Pause;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *generalLayout;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menu_Queue;
    QMenu *menu_Settings;
    QMenu *menu_Player;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *generalWindow)
    {
        if (generalWindow->objectName().isEmpty())
            generalWindow->setObjectName(QString::fromUtf8("generalWindow"));
        generalWindow->resize(454, 300);
        action_Add_music_to_Queue = new QAction(generalWindow);
        action_Add_music_to_Queue->setObjectName(QString::fromUtf8("action_Add_music_to_Queue"));
        action_Setting = new QAction(generalWindow);
        action_Setting->setObjectName(QString::fromUtf8("action_Setting"));
        action_Stop = new QAction(generalWindow);
        action_Stop->setObjectName(QString::fromUtf8("action_Stop"));
        action_Next = new QAction(generalWindow);
        action_Next->setObjectName(QString::fromUtf8("action_Next"));
        action_Previous = new QAction(generalWindow);
        action_Previous->setObjectName(QString::fromUtf8("action_Previous"));
        action_Rewind = new QAction(generalWindow);
        action_Rewind->setObjectName(QString::fromUtf8("action_Rewind"));
        action_Fast_forwsrd = new QAction(generalWindow);
        action_Fast_forwsrd->setObjectName(QString::fromUtf8("action_Fast_forwsrd"));
        action_Play_Pause = new QAction(generalWindow);
        action_Play_Pause->setObjectName(QString::fromUtf8("action_Play_Pause"));
        centralWidget = new QWidget(generalWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        generalLayout = new QVBoxLayout();
        generalLayout->setSpacing(6);
        generalLayout->setObjectName(QString::fromUtf8("generalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        generalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(generalLayout);

        generalWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(generalWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 454, 22));
        menu_Queue = new QMenu(menuBar);
        menu_Queue->setObjectName(QString::fromUtf8("menu_Queue"));
        menu_Settings = new QMenu(menuBar);
        menu_Settings->setObjectName(QString::fromUtf8("menu_Settings"));
        menu_Player = new QMenu(menuBar);
        menu_Player->setObjectName(QString::fromUtf8("menu_Player"));
        generalWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(generalWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        generalWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(generalWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        generalWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Queue->menuAction());
        menuBar->addAction(menu_Settings->menuAction());
        menuBar->addAction(menu_Player->menuAction());
        menu_Queue->addAction(action_Add_music_to_Queue);
        menu_Settings->addAction(action_Setting);
        menu_Player->addAction(action_Stop);
        menu_Player->addAction(action_Next);
        menu_Player->addAction(action_Previous);
        menu_Player->addAction(action_Rewind);
        menu_Player->addAction(action_Fast_forwsrd);
        menu_Player->addAction(action_Play_Pause);
        mainToolBar->addAction(action_Add_music_to_Queue);
        mainToolBar->addAction(action_Setting);

        retranslateUi(generalWindow);

        QMetaObject::connectSlotsByName(generalWindow);
    } // setupUi

    void retranslateUi(QMainWindow *generalWindow)
    {
        generalWindow->setWindowTitle(QCoreApplication::translate("generalWindow", "generalWindow", nullptr));
        action_Add_music_to_Queue->setText(QCoreApplication::translate("generalWindow", "&Add music to Queue", nullptr));
        action_Setting->setText(QCoreApplication::translate("generalWindow", "&Setting", nullptr));
        action_Stop->setText(QCoreApplication::translate("generalWindow", "&Stop", nullptr));
        action_Next->setText(QCoreApplication::translate("generalWindow", "&Next", nullptr));
#if QT_CONFIG(shortcut)
        action_Next->setShortcut(QCoreApplication::translate("generalWindow", "Down", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Previous->setText(QCoreApplication::translate("generalWindow", "&Previous", nullptr));
#if QT_CONFIG(shortcut)
        action_Previous->setShortcut(QCoreApplication::translate("generalWindow", "Up", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Rewind->setText(QCoreApplication::translate("generalWindow", "&Rewind", nullptr));
#if QT_CONFIG(shortcut)
        action_Rewind->setShortcut(QCoreApplication::translate("generalWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Fast_forwsrd->setText(QCoreApplication::translate("generalWindow", "&Fast forwsrd", nullptr));
#if QT_CONFIG(shortcut)
        action_Fast_forwsrd->setShortcut(QCoreApplication::translate("generalWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Play_Pause->setText(QCoreApplication::translate("generalWindow", "&Play/Pause", nullptr));
#if QT_CONFIG(shortcut)
        action_Play_Pause->setShortcut(QCoreApplication::translate("generalWindow", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        menu_Queue->setTitle(QCoreApplication::translate("generalWindow", "&Queue", nullptr));
        menu_Settings->setTitle(QCoreApplication::translate("generalWindow", "&Settings", nullptr));
        menu_Player->setTitle(QCoreApplication::translate("generalWindow", "&Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generalWindow: public Ui_generalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALWINDOW_H
