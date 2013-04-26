#include "btmspage.h"
#include "btms.h"
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWidgets/QMessageBox>

BtmsPage::BtmsPage(QObject *parent):
        QWebPage(parent)
{
}

QWebPage *BtmsPage::createWindow(WebWindowType type){
    BtmsPage *page = new BtmsPage(0);

    //get permissions and user session for page access
    Btms *newWin = new Btms(0, page);
    page->setParent(newWin);
    page->setNetworkAccessManager(this->networkAccessManager());
    if (type == QWebPage::WebModalDialog) {
        newWin->setWindowModality(Qt::ApplicationModal);
    }

    newWin->show();

    return page;
}

bool BtmsPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type){

    if(type == NavigationTypeFormResubmitted){
        frame->load(request.url());

        return false;
    }

    return QWebPage::acceptNavigationRequest(frame, request, type);
}

QString BtmsPage::userAgentForUrl(const QUrl &url) const {
    Q_UNUSED(url);
    return "{\"Name\":\"Btms\",\"Version\":\"0.1.2\"}";
}
