# -------------------------------------------------
# Project created by QtCreator 2013-02-11T10:56:15
# -------------------------------------------------
QT += widgets \
    webkit \
    webkitwidgets
TARGET = btms
TEMPLATE = app
SOURCES += main.cpp \
    btms.cpp \
    btmspage.cpp \
    btmsjavascript.cpp \
    btmssettings.cpp
HEADERS += btms.h \
    btmspage.h \
    btmsjavascript.h \
    btmssettings.h
FORMS += btms.ui
OTHER_FILES += \ 
    config/settings.ini

win32:RC_FILE += icons.rc

RESOURCES += \
    images.qrc
