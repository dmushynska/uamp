#pragma once
#include <QBuffer>
#include <QDebug>
#include <QDir>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QTreeWidget>

#include "generalwindow.h"
#include "mytreewidgetitem.h"

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

    QString GetTrack() {
        QSqlQuery query;
        query.exec("select Path from SavePlaylist where NumbTrack = " + QString::number(GetId()));
        query.first();
        if (query.size() > 0)
            return query.value(0).toString();
        return nullptr;
    }

    void addIntoSavePlaylist(const QString &path) {
        QSqlQuery query;
        query.prepare(
            "INSERT INTO SavePlaylist (Path) "
            "VALUES (:Path)");
        query.bindValue(":Path", path);
        query.exec();
    }

    QList<QString> GetSavePlaylist() {
        QSqlQuery query;
        QList<QString> list;
        query.exec("select Path from SavePlaylist");
        query.first();
        if (query.value(0).toString().size() > 0)
            list.push_back(query.value(0).toString());
        while (query.next()) {
            list.push_back(query.value(0).toString());
        }
        return list;
    }

    void deleteSavePlaylist() {
        QSqlQuery query;
        query.exec("DELETE FROM SavePlaylist;");
    }

    void addVolumeAndPos(int Vol, int Pos) {
        QSqlQuery query;
        query.prepare("UPDATE Save SET Volume = :Vol, Pos = :pos WHERE Numb = 1;");
        query.bindValue(":Vol", Vol);
        query.bindValue(":pos", Pos);
        query.exec();
    }

    void addId(int id) {
        QSqlQuery query;
        query.prepare("UPDATE Save SET Id = :Id WHERE Numb = 1;");
        query.bindValue(":Id", id);
        query.exec();
    }

    void addTypeSort(int Type, int Sort) {
        QSqlQuery query;
        query.prepare("UPDATE Save SET Sort = :Sort, Type = :Type WHERE Numb = 1;");
        query.bindValue(":Sort", Sort);
        query.bindValue(":Type", Type);
        query.exec();
    }

    int GetVolume() {
        QSqlQuery query;
        query.exec("select Volume from Save WHERE Numb = 1");
        query.first();
        return query.value(0).toInt();
    }

    int GetPos() {
        QSqlQuery query;
        query.exec("select Pos from Save WHERE Numb = 1");
        query.first();
        return query.value(0).toInt();
    }

    int GetId() {
        QSqlQuery query;
        query.exec("select Id from Save WHERE Numb = 1");
        query.first();
        return query.value(0).toInt();
    }

    int GetSort() {
        QSqlQuery query;
        query.exec("select Sort from Save WHERE Numb = 1");
        query.first();
        return query.value(0).toInt();
    }

    int GetType() {
        QSqlQuery query;
        query.exec("select Type from Save WHERE Numb = 1");
        query.first();
        return query.value(0).toInt();
    }

    bool SignUp(const QString &user, const QString &pass) {
        QSqlQuery query;
        query.prepare(
            "INSERT INTO Users (User, Pass) "
            "VALUES (:User, :Pass)");
        query.bindValue(":User", user);
        query.bindValue(":Pass", pass);
        return query.exec();
    }

    bool SignIn(const QString &user, const QString &pass) {
        QSqlQuery query;
        query.exec("select User from Users where Pass = '" + pass + "';");
        query.first();
        if (query.value(0).toString() == user)
            return true;
        return false;
    }

    void addTrack(const QString &path, QTreeWidgetItem *topLevelItem, generalWindow *m_main) {
        QString name = m_main->GetFileName(path);
        MyTreeWidgetItem *widgetitem = new MyTreeWidgetItem(topLevelItem, name, path);
        widgetitem->setText(0, name);
    }

    MyTreeWidgetItem *addPlaylist(QTreeWidget *treeWidget, const QString &name, int id, generalWindow *m_main) {
        QSqlQuery query;
        saveImage(name);
        MyTreeWidgetItem *topLevelItem;
        if (QFile::exists(name + ".png")) {
            topLevelItem = new MyTreeWidgetItem(treeWidget, name, name);
        } else {
            topLevelItem = new MyTreeWidgetItem(treeWidget, name, nullptr);
        }
        treeWidget->addTopLevelItem(topLevelItem);
        topLevelItem->setText(0, name);
        query.exec("select Path from Tracks where NumbTrack in (select NumbTrack from TrackPlaylists where NumbPlaylist =  " + QString::number(id) + ");");
        while (query.next()) {
            addTrack(query.value(0).toString(), topLevelItem, m_main);
        }
        return topLevelItem;
    }

    int GetUserId(const QString &user) {
        QSqlQuery query;
        query.exec("select NumbUser from Users where User = '" + user + "';");
        query.first();
        return query.value(0).toInt();
    }

    void selectPlaylistFromDataBase(QTreeWidget *treeWidget, const QString &user, generalWindow *m_main) {
        QSqlQuery query;
        query.exec("select Name, NumbPlaylist from Playlists where NumbUser = " + QString::number(GetUserId(user)));
        while (query.next()) {
            addPlaylist(treeWidget, query.value(0).toString(), query.value(1).toInt(), m_main);
        }
    }

    void createDataBase() {
        QSqlQuery query;
        query.exec("create table IF NOT EXISTS Tracks (NumbTrack integer primary key AUTOINCREMENT, Path TEXT UNIQUE, Stars iINT, Rating INT)");
        query.exec("create table IF NOT EXISTS Playlists (NumbPlaylist integer primary key AUTOINCREMENT, NumbUser INT, Name TEXT UNIQUE, IMAGES BLOB)");
        query.exec("create table IF NOT EXISTS TrackPlaylists (NumbTrack INT, NumbPlaylist INT, PRIMARY KEY (NumbTrack, NumbPlaylist))");
        query.exec("create table IF NOT EXISTS Users (NumbUser integer primary key AUTOINCREMENT, User Text UNIQUE, Pass TEXT)");
        query.exec("create table IF NOT EXISTS SavePlaylist (NumbTrack integer primary key AUTOINCREMENT, Path TEXT)");
        query.exec("create table IF NOT EXISTS Save (Numb integer primary key AUTOINCREMENT, Id INT, Pos INT, Volume INT, Sort INT, Type INT)");
        query.prepare(
            "INSERT INTO Save (Volume) "
            "VALUES (:Vol)");
        query.bindValue(":Vol", 70);
        query.exec();
        query.exec("Delete from Save where Numb != 1");
    }

    int NumbPlaylist(const QString &name) {
        QSqlQuery query;
        query.exec("select NumbPlaylist from Playlists where Name = '" + name + "';");
        query.first();
        return query.value(0).toInt();
    }

    int addToPlaylists(const QString &name, const QString &user) {
        QSqlQuery query;
        query.prepare(
            "INSERT INTO Playlists (Name, NumbUser) "
            "VALUES (:Name, :NumbUser)");
        query.bindValue(":Name", name);
        query.bindValue(":NumbUser", GetUserId(user));
        bool exec = query.exec();
        if (exec == 0)
            return -1;
        return NumbPlaylist(name);
    }

    int addToTracks(const QString &path) {
        QSqlQuery query;
        query.prepare(
            "INSERT INTO Tracks(Path, Stars, Rating) "
            "VALUES (:Path, :Stars, :Rating)");
        query.bindValue(":Path", path);
        query.bindValue(":Stars", 0);
        query.bindValue(":Rating", 0);
        query.exec();
        query.exec("select NumbTrack from Tracks where Path = '" + path + "';");
        query.first();
        return query.value(0).toInt();
    }

    void deleteTrack(const QString &path) {
        QSqlQuery query;
        qDebug() << query.exec("select NumbTrack from Tracks where Path = '" + path + "';");
        query.first();
        qDebug() << query.exec("delete from TrackPlaylists where NumbTrack = " + query.value(0).toString());
    }

    bool addToTrackPlaylists(int track, int playlist) {
        QSqlQuery query;
        query.prepare(
            "INSERT INTO TrackPlaylists(NumbTrack, NumbPlaylist) "
            "VALUES (:NumbTrack, :NumbPlaylist)");
        query.bindValue(":NumbTrack", track);
        query.bindValue(":NumbPlaylist", playlist);
        return query.exec();
    }

    void deletePlaylists(const QString &name) {
        QSqlQuery query;
        //        qDebug() << name;
        qDebug() << query.exec("select NumbPlaylist from Playlists where Name = '" + name + "';");
        query.first();
        QString string = query.value(0).toString();
        qDebug() << query.exec("delete from TrackPlaylists where NumbPlaylist = " + string);
        qDebug() << query.exec("delete from Playlists where NumbPlaylist = " + string);
    }

    bool renamePlaylist(const QString &string, const QString &newName) {
        QSqlQuery query;
        return query.exec("UPDATE Playlists SET Name = '" + newName + "' WHERE Name ='" + string + "';");
    }

    void insertImage(const QString &name, const QString &filename) {
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        QSqlQuery query;
        query.prepare("UPDATE Playlists SET IMAGES = :image WHERE Name = :name;");
        query.bindValue(":image", ba, QSql::InOut | QSql::Binary);
        query.bindValue(":name", name);
        qDebug() << "photo " << query.exec();
        file.close();
    }

    QByteArray GetImage(const QString &name) {
        QSqlQuery query;
        qDebug() << query.exec("select IMAGES from Playlists where Name = '" + name + "';");
        query.first();
        return query.value(0).toByteArray();
    }

    void saveImage(const QString &filename) {
        QByteArray mass = GetImage(filename);
        QPixmap pixmap = QPixmap();
        pixmap.loadFromData(mass);
        QFile file(filename + ".png");
        QBuffer buffer(&mass);
        buffer.open(QIODevice::WriteOnly);
        pixmap.save(&file, "PNG");
    }

    void deleteImage(const QString &name) {
        QSqlQuery query;
        qDebug() << "delete photo "
                 << "UPDATE Playlists SET IMAGES = '' where Name = '" + name + "';" << query.exec("UPDATE Playlists SET IMAGES = '' where Name = '" + name + "';");
        QFile::remove(name + ".png");
    }
};
