#include "adbcontroller.h"
#include "qprocess.h"

AdbController::AdbController()
{

}

QString AdbController::execCommand(QString cmd)
{
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<cmd);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    return strTemp;
}
