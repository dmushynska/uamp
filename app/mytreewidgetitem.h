#pragma once
#include <QTreeWidgetItem>

class MyTreeWidgetItem : public QObject, public QTreeWidgetItem {
    Q_OBJECT
    QString Name = "name";
    QString Path = "/Users/dmushynska/Desktop/eldzhey-morgenshtern_-_lollipop.mp3";
public:
    explicit MyTreeWidgetItem(QTreeWidgetItem *parent, QString name, QString path) : QTreeWidgetItem(parent), Name(name), Path(path) {}
    ~MyTreeWidgetItem() = default;

    void SetName(QString name) {
        Name = name;
    }
    QString GetName() {
        return Name;
    }
    QString GetPath() {
        return Path;
    }
};
