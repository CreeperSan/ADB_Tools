#include "adbcontroller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmessagebox.h>
#include <qprocess.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    AdbController a;
    // 检查环境
    if(checkEnviroment(a))
    {
        ui->setupUi(this);
    }
    else
    {
        showMessageBox("应用程序启动失败，请检查您的环境是否配置正确");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessageBox(QString content)
{
    QMessageBox tmpMessageBox;
    tmpMessageBox.setText(content);
    tmpMessageBox.exec();
}

bool MainWindow::checkEnviroment(AdbController adb)
{
    // 检查ADB是否正常
    QString txtVersion = adb.execCommand("adb --version");
    if(!txtVersion.contains("Android Debug Bridge version") || !txtVersion.contains("Version") || !txtVersion.contains("Installed as "))
    {
        showMessageBox("ADB环境尚未配置");
    }
    // 检查设备是否连接正常
    QString txtDevices = adb.execCommand("adb devices");
    showMessageBox(txtDevices);
}
