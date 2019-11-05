/********************************************************************************
** Form generated from reading UI file 'observer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBSERVER_H
#define UI_OBSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_observerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *chatWindow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *observerClass)
    {
        if (observerClass->objectName().isEmpty())
            observerClass->setObjectName(QString::fromUtf8("observerClass"));
        observerClass->resize(600, 400);
        centralWidget = new QWidget(observerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 1, 1, 1);

        chatWindow = new QListWidget(centralWidget);
        chatWindow->setObjectName(QString::fromUtf8("chatWindow"));

        gridLayout_2->addWidget(chatWindow, 0, 0, 1, 1);

        observerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(observerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        observerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(observerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        observerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(observerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        observerClass->setStatusBar(statusBar);

        retranslateUi(observerClass);

        QMetaObject::connectSlotsByName(observerClass);
    } // setupUi

    void retranslateUi(QMainWindow *observerClass)
    {
        observerClass->setWindowTitle(QApplication::translate("observerClass", "observer", nullptr));
        pushButton->setText(QApplication::translate("observerClass", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class observerClass: public Ui_observerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSERVER_H
