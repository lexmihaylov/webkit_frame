/********************************************************************************
** Form generated from reading UI file 'btmspopup.ui'
**
** Created: Mon Feb 11 17:01:48 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTMSPOPUP_H
#define UI_BTMSPOPUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_BtmsPopup
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWebView *webView;

    void setupUi(QMainWindow *BtmsPopup)
    {
        if (BtmsPopup->objectName().isEmpty())
            BtmsPopup->setObjectName(QString::fromUtf8("BtmsPopup"));
        BtmsPopup->resize(640, 480);
        centralwidget = new QWidget(BtmsPopup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(centralwidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("about:blank"));

        gridLayout->addWidget(webView, 0, 0, 1, 1);

        BtmsPopup->setCentralWidget(centralwidget);

        retranslateUi(BtmsPopup);

        QMetaObject::connectSlotsByName(BtmsPopup);
    } // setupUi

    void retranslateUi(QMainWindow *BtmsPopup)
    {
        BtmsPopup->setWindowTitle(QApplication::translate("BtmsPopup", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BtmsPopup: public Ui_BtmsPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTMSPOPUP_H
