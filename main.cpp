#include <QtWidgets/QApplication>
#include <btmssettings.h>
#include "btms.h"
//#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->addLibraryPath(qApp->applicationDirPath()+"/plugins");

    a.setApplicationName("BTMS");
    a.setApplicationVersion("0.1.2");

    BtmsSettings::loadBtmsSettings();

    Btms w;
    w.show();
    return a.exec();
}
