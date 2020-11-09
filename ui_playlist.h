/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Playlist
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Playlist)
    {
        if (Playlist->objectName().isEmpty())
            Playlist->setObjectName(QString::fromUtf8("Playlist"));
        Playlist->resize(607, 431);
        verticalLayout = new QVBoxLayout(Playlist);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(Playlist);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        retranslateUi(Playlist);

        QMetaObject::connectSlotsByName(Playlist);
    } // setupUi

    void retranslateUi(QWidget *Playlist)
    {
        Playlist->setWindowTitle(QCoreApplication::translate("Playlist", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Playlist: public Ui_Playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
