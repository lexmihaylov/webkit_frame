#ifndef BTMS_H
#define BTMS_H

#include <QtWidgets/QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QProgressBar>
#include <QSettings>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QMessageBox>
#include <QFile>
#include <QSystemTrayIcon>

#include "btmspage.h"
#include "btmsjavascript.h"

namespace Ui {
    class Btms;
}

class Btms : public QMainWindow {
    Q_OBJECT
public:
    Btms(QWidget *parent = 0, BtmsPage *page = 0);
    ~Btms();
    BtmsJavascript *btmsJs;

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::Btms *ui;
    QProgressBar *progress;
    QSettings *config;
    QSystemTrayIcon *systray;
    void showStatusMessage(QString message);
    void loadWebSettings();
    void initProgressBar();
    void loadPageSettings();

public slots:
    void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);
    void pageStartLoading();
    void pageLoaded(bool status);
    void doPrint(QWebFrame *frame);
    void addJSObject();
    void updateProgress(int i);
    void downloadRequested(const QNetworkRequest& req);
    void downloadContent(QNetworkReply *reply);
    void downloadProgress(qint64 bytesDownloaded, qint64 bytesAll);
};

#endif // BTMS_H
