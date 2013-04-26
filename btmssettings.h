#ifndef BTMSSETTINGS_H
#define BTMSSETTINGS_H

#include <QSettings>
#include <QtWidgets/QMessageBox>

class BtmsSettings
{
public:
    BtmsSettings();

    static QSettings *Config;

    static void loadBtmsSettings();
};

#endif // BTMSSETTINGS_H
