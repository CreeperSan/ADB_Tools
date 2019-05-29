#ifndef ADBCONTROLLER_H
#define ADBCONTROLLER_H

#include <qstring.h>



class AdbController
{
public:
    AdbController();
    QString execCommand(QString cmd);
};

#endif // ADBCONTROLLER_H
