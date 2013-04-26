#include "btms.h"
#include "ui_btms.h"
#include "btmspage.h"
#include "btmsjavascript.h"
#include "btmssettings.h"

#include <QtWidgets/QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QErrorMessage>
#include <QFile>
#include <QProcess>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QStyleFactory>
#include <QFileInfo>
#include <QtWidgets/QFileDialog>
#include <QSystemTrayIcon>
#include <QTimer>

Btms::Btms(QWidget *parent, BtmsPage *page) :
    QMainWindow(parent),
    ui(new Ui::Btms)
{
    ui->setupUi(this);
    initProgressBar();

    systray = new QSystemTrayIcon(this);
    systray->setIcon(QIcon(QPixmap("://images/bus.ico")));

    ui->webView->setAttribute(Qt::WA_DeleteOnClose, true);

    if(page != 0) {
        ui->webView->setPage(page);
    } else {
        Btms::showMaximized();
        ui->webView->setPage(new BtmsPage(ui->webView));
        ui->webView->load(QUrl(BtmsSettings::Config->value("system/launch").toString()));
    }

    loadWebSettings();
}

Btms::~Btms()
{
    delete ui;
}

void Btms::loadPageSettings() {
    connect(ui->webView->page()->networkAccessManager(),
            SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),
            this,
            SLOT(sslErrorHandler(QNetworkReply*, const QList<QSslError> & )));

    connect(ui->webView->page(), SIGNAL(printRequested(QWebFrame*)), SLOT(doPrint(QWebFrame*)));

    btmsJs = new BtmsJavascript();

    QObject::connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                          this, SLOT(addJSObject()));

    connect(ui->webView->page(), SIGNAL(windowCloseRequested()), SLOT(close()));
    connect(ui->webView->page(), SIGNAL(downloadRequested(const QNetworkRequest&)), this, SLOT(downloadRequested(const QNetworkRequest&)));
    connect(ui->webView->page(), SIGNAL(unsupportedContent(QNetworkReply*)), this, SLOT(downloadContent(QNetworkReply*)));
}

void Btms::loadWebSettings() {
    loadPageSettings();
    ui->webView->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
    ui->webView->settings()->setAttribute(QWebSettings::LocalStorageDatabaseEnabled,false);
    ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled,false);
    ui->webView->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    ui->webView->settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,false);
    ui->webView->settings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled,true);
    ui->webView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanCloseWindows, true);
    ui->webView->settings()->setAttribute(QWebSettings::XSSAuditingEnabled, true);
    ui->webView->settings()->setFontFamily(QWebSettings::StandardFont, "Arial");
    ui->webView->settings()->setFontSize(QWebSettings::DefaultFontSize, 14);
    ui->webView->settings()->setAttribute(QWebSettings::PrintElementBackgrounds, true);
    ui->webView->settings()->setDefaultTextEncoding("utf8");
    ui->webView->setStyle(QStyleFactory::create("fusion"));
    ui->webView->page()->setForwardUnsupportedContent(true);
}

void Btms::initProgressBar() {
    progress = new QProgressBar(ui->statusBar);
    progress->setMaximumWidth(100);
    progress->setRange(0, 100);
    progress->hide();

    ui->statusBar->addPermanentWidget(progress, 0);
    connect(ui->webView, SIGNAL(loadProgress(int)), SLOT(updateProgress(int)));
}

void Btms::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Btms::showStatusMessage(QString message){
    ui->statusBar->showMessage(message);
}

void Btms::sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist)
{
    Q_UNUSED(errlist);
    qnr->ignoreSslErrors();
}

void Btms::pageStartLoading() {
    progress->reset();
    progress->show();

    showStatusMessage("Loading Content ...");
}

void Btms::pageLoaded(bool status) {
    if(status) {
        showStatusMessage("Content loaded");
    } else {
        showStatusMessage("Error loading the content");
    }

    progress->hide();
}

void Btms::doPrint(QWebFrame *frame) {
    Q_UNUSED(frame);

    QPrintDialog printDialog;
    printDialog.printer()->setOrientation(QPrinter::Portrait);
    printDialog.printer()->setColorMode(QPrinter::GrayScale);
    printDialog.printer()->setPageSize(QPrinter::A4);
    if(printDialog.exec()){
        ui->webView->print(printDialog.printer());
    }
}

void Btms::addJSObject() {
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("Btms", btmsJs);
}

void Btms::updateProgress(int i) {
    progress->setValue(i);
}

void Btms::closeEvent(QCloseEvent *e) {
    Q_UNUSED(e);
    ui->webView->page()->deleteLater();
}

void Btms::downloadRequested(const QNetworkRequest &req) {
    QNetworkAccessManager *networkManager = ui->webView->page()->networkAccessManager();
    QNetworkReply *reply = networkManager->get(req);
    this->downloadContent(reply);
}

void Btms::downloadContent(QNetworkReply *reply) {
    QString defaultName(reply->rawHeader("Content-Disposition").mid(22));
    defaultName.chop(1);

    if(defaultName.isEmpty()) {
        QFileInfo info(reply->url().toString());
        defaultName = info.fileName();
    }

    QFileDialog dialog;
    dialog.setOptions(QFileDialog::DontUseNativeDialog);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setDirectory(QDir::homePath());
    dialog.selectFile(defaultName);

    QString fileName;
    int ret = dialog.exec();
    if (ret == QDialog::Accepted) {
        fileName = dialog.selectedFiles().first();
    }
    if(ui->webView->url().isEmpty()) {
        this->close();
    }
    if (fileName.isEmpty()) return;

    if(!reply->isFinished()) {
        showStatusMessage("Downloading ("+fileName+") ... ");

        QEventLoop loop;
        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));

        loop.exec();
    }

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());

    systray->show();
    systray->showMessage("Download Complete", "File "+ fileName +" downloaded", QSystemTrayIcon::Information, 5000);
    QTimer::singleShot(5000, systray, SLOT(hide()));

    reply->deleteLater();
}

void Btms::downloadProgress(qint64 bytesDownloaded, qint64 bytesAll) {
    int persent((double(bytesDownloaded)/double(bytesAll))*100);
    this->updateProgress(persent);
}
