/********************************************************************************
** Form generated from reading UI file 'test3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3_H
#define UI_TEST3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test3Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *disordersList;
    QLineEdit *lineEdit;
    QPushButton *symptomButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test3Class)
    {
        if (test3Class->objectName().isEmpty())
            test3Class->setObjectName(QString::fromUtf8("test3Class"));
        test3Class->resize(600, 400);
        centralWidget = new QWidget(test3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        disordersList = new QListWidget(centralWidget);
        disordersList->setObjectName(QString::fromUtf8("disordersList"));

        verticalLayout->addWidget(disordersList);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        symptomButton = new QPushButton(centralWidget);
        symptomButton->setObjectName(QString::fromUtf8("symptomButton"));

        verticalLayout->addWidget(symptomButton);

        test3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(test3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        test3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        test3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(test3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test3Class->setStatusBar(statusBar);

        retranslateUi(test3Class);

        QMetaObject::connectSlotsByName(test3Class);
    } // setupUi

    void retranslateUi(QMainWindow *test3Class)
    {
        test3Class->setWindowTitle(QApplication::translate("test3Class", "test3", nullptr));
        symptomButton->setText(QApplication::translate("test3Class", "Show symptoms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test3Class: public Ui_test3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3_H
