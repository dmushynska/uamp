#ifndef WINDOWSETTING_H
#define WINDOWSETTING_H

#include <QDialog>

namespace Ui {
class WindowSetting;
}

class WindowSetting : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSetting(QWidget *parent = nullptr);
    ~WindowSetting();

private:
    Ui::WindowSetting *ui;
};

#endif // WINDOWSETTING_H
