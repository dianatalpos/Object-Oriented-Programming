/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *ideaView;
    QLabel *label;
    QLineEdit *descriptionEdit;
    QLabel *label_2;
    QLineEdit *actEdit;
    QPushButton *addButton;
    QPushButton *acceptButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *screenClass)
    {
        if (screenClass->objectName().isEmpty())
            screenClass->setObjectName(QString::fromUtf8("screenClass"));
        screenClass->resize(600, 400);
        centralWidget = new QWidget(screenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ideaView = new QTableView(centralWidget);
        ideaView->setObjectName(QString::fromUtf8("ideaView"));

        gridLayout->addWidget(ideaView, 0, 0, 1, 3);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        descriptionEdit = new QLineEdit(centralWidget);
        descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));

        gridLayout->addWidget(descriptionEdit, 1, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        actEdit = new QLineEdit(centralWidget);
        actEdit->setObjectName(QString::fromUtf8("actEdit"));

        gridLayout->addWidget(actEdit, 2, 1, 1, 1);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 2, 2, 1, 1);

        acceptButton = new QPushButton(centralWidget);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        gridLayout->addWidget(acceptButton, 3, 2, 1, 1);

        screenClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(screenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        screenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(screenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        screenClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(screenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        screenClass->setStatusBar(statusBar);

        retranslateUi(screenClass);

        QMetaObject::connectSlotsByName(screenClass);
    } // setupUi

    void retranslateUi(QMainWindow *screenClass)
    {
        screenClass->setWindowTitle(QApplication::translate("screenClass", "screen", nullptr));
        label->setText(QApplication::translate("screenClass", "Description", nullptr));
        label_2->setText(QApplication::translate("screenClass", "Act", nullptr));
        addButton->setText(QApplication::translate("screenClass", "Add Idea", nullptr));
        acceptButton->setText(QApplication::translate("screenClass", "Accept Idea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenClass: public Ui_screenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H
