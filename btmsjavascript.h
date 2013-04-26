#ifndef BTMSJAVASCRIPT_H
#define BTMSJAVASCRIPT_H

#include <QObject>
#include <QVariantMap>

class BtmsJavascript : public QObject
{
    Q_OBJECT
public:
    BtmsJavascript();

    Q_INVOKABLE QString shell(QString command);
    Q_INVOKABLE QVariantMap fprint(QString command);
    Q_INVOKABLE void filePutContents(QString file, QString text);
    Q_INVOKABLE QString fileGetContents(QString file);
    Q_INVOKABLE void fileRemove(QString file);
};

#endif // BTMSJAVASCRIPT_H
