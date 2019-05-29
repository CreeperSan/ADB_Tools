#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adbcontroller.h"

#include <QMainWindow>
#include <qmessagebox.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void showMessageBox(QString content);
    bool checkEnviroment(AdbController controller);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
