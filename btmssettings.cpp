#include "btmssettings.h"
#include <QFile>

BtmsSettings::BtmsSettings()
{
}

QSettings *BtmsSettings::Config;

void BtmsSettings::loadBtmsSettings() {
    if(QFile::exists("config/settings.ini")) {
        Config = new QSettings("config/settings.ini", QSettings::IniFormat);

        if(Config->value("system/launch").toString().length() == 0) {
            Config->setValue("system/launch", "http://localhost");
        }
    } else {
        QMessageBox::critical(0, "Settings Error", "Settings file does not exist\nPlease make sure that config/settings.ini exists.");
        exit(1);
    }
}
