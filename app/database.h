#pragma once
#include "mytreewidgetitem.h"
#include <QDebug>
#include <QPushButton>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QSqlQueryModel>
#include <QTreeWidget>
#include <QBuffer>


class DataBase {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
public:

    explicit DataBase() {
        db.setDatabaseName("myDb.db");
        db.open();
    }

    ~DataBase() {
        db.close();
    }

    void addTrack(QString path, QTreeWidgetItem *topLevelItem) {
        MyTreeWidgetItem *widgetitem = new MyTreeWidgetItem(topLevelItem, "name", path);
        widgetitem->setText(0, "name");
    }

    void addPlaylist(QTreeWidget *treeWidget, QString name, int id) {
        QSqlQuery query;
        query.exec("select Path from Tracks where NumbTrack in (select NumbTrack from TrackPlaylists where NumbPlaylist =  " + QString::number(id) + ");");
        QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(treeWidget);
        treeWidget->addTopLevelItem(topLevelItem);
        topLevelItem->setText(0, name);
        while(query.next()) {
                addTrack(query.value(0).toString(), topLevelItem);
        }
    }

    void selectPlaylistFromDataBase(QTreeWidget *treeWidget) {
        QSqlQuery query;
        query.exec("select Name, NumbPlaylist from Playlists");
        while (query.next()) {
            addPlaylist(treeWidget, query.value(0).toString(), query.value(1).toInt());
        }
    }

    void createDataBase() {
        QSqlQuery query;
        qDebug() << query.exec("create table IF NOT EXISTS Tracks (NumbTrack integer primary key AUTOINCREMENT, Path TEXT UNIQUE, Stars iINT, Rating INT)");
        qDebug() << query.exec("create table IF NOT EXISTS Playlists (NumbPlaylist integer primary key AUTOINCREMENT, Name TEXT UNIQUE, IMAGES BLOB)");
        qDebug() << query.exec("create table IF NOT EXISTS TrackPlaylists (NumbTrack INT, NumbPlaylist INT, PRIMARY KEY (NumbTrack, NumbPlaylist))");
    }

    int NumbPlaylist(QString name) {
        QSqlQuery query;
        query.exec("select NumbPlaylist from Playlists where Name = '" + name + "';");
        query.first();
        return query.value(0).toInt();
    }

    int addToPlaylists(QString name) {
        QSqlQuery query;
        query.prepare("INSERT INTO Playlists (Name) "
                            "VALUES (:Name)");
        query.bindValue(":Name", name);
        bool exec = query.exec();
        if (exec == 0)
            return -1;
        return NumbPlaylist(name);
    }

    int addToTracks(QString path) {
        QSqlQuery query;
           query.prepare("INSERT INTO Tracks(Path, Stars, Rating) "
                  "VALUES (:Path, :Stars, :Rating)");
           query.bindValue(":Path", path);
           query.bindValue(":Stars", 0);
           query.bindValue(":Rating", 0);
           query.exec();
           query.exec("select NumbTrack from Tracks where Path = '" + path + "';");
           query.first();
           return query.value(0).toInt();
    }

    void deleteTrack(QString path) {
        QSqlQuery query;
        qDebug() << query.exec("select NumbTrack from Tracks where Path = '" + path + "';");
        query.first();
        qDebug() << query.exec("delete from TrackPlaylists where NumbTrack = " + query.value(0).toString());
    }

    bool addToTrackPlaylists(int track, int playlist) {
        QSqlQuery query;
        query.prepare("INSERT INTO TrackPlaylists(NumbTrack, NumbPlaylist) "
               "VALUES (:NumbTrack, :NumbPlaylist)");
        query.bindValue(":NumbTrack", track);
        query.bindValue(":NumbPlaylist", playlist);
        return query.exec();
    }

    void deletePlaylists(QString name) {
        QSqlQuery query;
//        qDebug() << name;
        qDebug() << query.exec("select NumbPlaylist from Playlists where Name = '" + name + "';");
        query.first();
        QString string = query.value(0).toString();
        qDebug() << query.exec("delete from TrackPlaylists where NumbPlaylist = " + string);
        qDebug() << query.exec("delete from Playlists where NumbPlaylist = " + string);
    }

    bool renamePlaylist(QString string, QString newName) {
        QSqlQuery query;
        return  query.exec("UPDATE Playlists SET Name = '"+ newName +"' WHERE Name ='" + string + "';");
    }

//     void insertImage(QPixmap image, QString name) {
//         QSqlQuery query;
//         QByteArray inByteArray;
//         QBuffer inBuffer( &inByteArray );
//         inBuffer.open( QIODevice::WriteOnly );
//         image.save( &inBuffer, "PNG" );
//         query.prepare("UPDATE Playlists (IMAGES) "
//                       "VALUES (:IMAGES) where Name = '" + name + "';");
//                 query.bindValue(":IMAGES", inByteArray);
//         qDebug() << "photo " <<  query.exec();
//     }

//     QByteArray GetImage(QString name) {
//         QSqlQuery query;
//         query.exec("select IMAGES from Playlists where Name = '" + name + "';");
//         query.first();
//         return query.value(0).toByteArray();
// //        QImage image = QImage();
// //        image.loadFromData(outByteArray);
// //        return  image;
//     }
};
