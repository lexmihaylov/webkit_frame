#include "btmsjavascript.h"
#include <QtWidgets/QMessageBox>
#include <QProcess>
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include "btmssettings.h"

BtmsJavascript::BtmsJavascript()
{

}

QString BtmsJavascript::shell(QString command) {
    QProcess *process = new QProcess(this);

    process->start(command);
    process->waitForFinished();

    return QString(process->readAllStandardOutput());
}

void BtmsJavascript::filePutContents(QString file, QString text) {
    QFile fp(file);

    fp.open(QFile::WriteOnly);

    fp.write(text.toUtf8());

    fp.close();
}

QString BtmsJavascript::fileGetContents(QString file) {
    QFile fp(file);
    fp.open(QFile::ReadOnly);
    return QString(fp.readAll());
}

void BtmsJavascript::fileRemove(QString file) {
    QFile::remove(file);
}

QVariantMap BtmsJavascript::fprint(QString data) {
    QFile fp(BtmsSettings::Config->value("fprint/file").toString());
    fp.open(QFile::WriteOnly);

    QTextStream writer(&fp);
    writer.setCodec("windows-1251");
    writer << data;
    fp.close();

    QString command = BtmsSettings::Config->value("fprint/executable").toString()+" "+BtmsSettings::Config->value("fprint/port").toString()+" "
            + BtmsSettings::Config->value("fprint/speed").toString() + " "
            + BtmsSettings::Config->value("fprint/file").toString() + " "
            + BtmsSettings::Config->value("fprint/serial").toString();

    QString output = this->shell(command);

    QString response = this->fileGetContents(BtmsSettings::Config->value("fprint/file").toString());

    QVariantMap object;
    object["command"] = QVariant(command);
    object["output"] = QVariant(output);
    object["response"] = QVariant(response);

    return object;
}
