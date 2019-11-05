/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

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

class Ui_chatClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chatClass)
    {
        if (chatClass->objectName().isEmpty())
            chatClass->setObjectName(QString::fromUtf8("chatClass"));
        chatClass->resize(600, 400);
        centralWidget = new QWidget(chatClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        chatClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chatClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        chatClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chatClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        chatClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chatClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        chatClass->setStatusBar(statusBar);

        retranslateUi(chatClass);

        QMetaObject::connectSlotsByName(chatClass);
    } // setupUi

    void retranslateUi(QMainWindow *chatClass)
    {
        chatClass->setWindowTitle(QApplication::translate("chatClass", "chat", nullptr));
        pushButton->setText(QApplication::translate("chatClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatClass: public Ui_chatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
