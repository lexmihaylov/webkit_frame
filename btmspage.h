#ifndef BTMSPAGE_H
#define BTMSPAGE_H

#include <QtWebKitWidgets/QWebPage>

class BtmsPage : public QWebPage
{
public:
    BtmsPage(QObject *parent = 0);

    QWebPage *createWindow(WebWindowType type);
    bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type);
    QString userAgentForUrl(const QUrl &url) const;
};

#endif // BTMSPAGE_H
