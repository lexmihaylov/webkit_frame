/********************************************************************************
** Form generated from reading UI file 'btms.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTMS_H
#define UI_BTMS_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Btms
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWebView *webView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Btms)
    {
        if (Btms->objectName().isEmpty())
            Btms->setObjectName(QStringLiteral("Btms"));
        Btms->resize(800, 600);
        centralWidget = new QWidget(Btms);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        webView = new QWebView(centralWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(webView, 0, 0, 1, 1);

        Btms->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Btms);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Btms->setStatusBar(statusBar);

        retranslateUi(Btms);
        QObject::connect(webView, SIGNAL(titleChanged(QString)), Btms, SLOT(setWindowTitle(QString)));
        QObject::connect(webView, SIGNAL(loadStarted()), Btms, SLOT(pageStartLoading()));
        QObject::connect(webView, SIGNAL(loadFinished(bool)), Btms, SLOT(pageLoaded(bool)));

        QMetaObject::connectSlotsByName(Btms);
    } // setupUi

    void retranslateUi(QMainWindow *Btms)
    {
        Btms->setWindowTitle(QApplication::translate("Btms", "Btms", 0));
    } // retranslateUi

};

namespace Ui {
    class Btms: public Ui_Btms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTMS_H
