/********************************************************************************
** Form generated from reading UI file 'ecuatii.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECUATII_H
#define UI_ECUATII_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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

class Ui_ecuatiiClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *equationList;
    QVBoxLayout *verticalLayout;
    QLineEdit *alineEdit;
    QLineEdit *blineEdit;
    QLineEdit *clineEdit;
    QPushButton *computeButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelSol2;
    QLabel *labelSol1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ecuatiiClass)
    {
        if (ecuatiiClass->objectName().isEmpty())
            ecuatiiClass->setObjectName(QString::fromUtf8("ecuatiiClass"));
        ecuatiiClass->resize(600, 400);
        centralWidget = new QWidget(ecuatiiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(1677721, 1677721));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        equationList = new QListWidget(centralWidget);
        equationList->setObjectName(QString::fromUtf8("equationList"));
        equationList->setEnabled(true);
        equationList->setMaximumSize(QSize(250, 1000));

        horizontalLayout->addWidget(equationList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, -1, 10, -1);
        alineEdit = new QLineEdit(centralWidget);
        alineEdit->setObjectName(QString::fromUtf8("alineEdit"));

        verticalLayout->addWidget(alineEdit);

        blineEdit = new QLineEdit(centralWidget);
        blineEdit->setObjectName(QString::fromUtf8("blineEdit"));

        verticalLayout->addWidget(blineEdit);

        clineEdit = new QLineEdit(centralWidget);
        clineEdit->setObjectName(QString::fromUtf8("clineEdit"));

        verticalLayout->addWidget(clineEdit);

        computeButton = new QPushButton(centralWidget);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));

        verticalLayout->addWidget(computeButton);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 10, -1, -1);
        labelSol2 = new QLabel(centralWidget);
        labelSol2->setObjectName(QString::fromUtf8("labelSol2"));
        labelSol2->setMaximumSize(QSize(1400, 20));

        verticalLayout_2->addWidget(labelSol2);

        labelSol1 = new QLabel(centralWidget);
        labelSol1->setObjectName(QString::fromUtf8("labelSol1"));
        labelSol1->setEnabled(true);
        labelSol1->setMaximumSize(QSize(1400, 20));

        verticalLayout_2->addWidget(labelSol1);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        ecuatiiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ecuatiiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        ecuatiiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ecuatiiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ecuatiiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ecuatiiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ecuatiiClass->setStatusBar(statusBar);

        retranslateUi(ecuatiiClass);

        QMetaObject::connectSlotsByName(ecuatiiClass);
    } // setupUi

    void retranslateUi(QMainWindow *ecuatiiClass)
    {
        ecuatiiClass->setWindowTitle(QApplication::translate("ecuatiiClass", "ecuatii", nullptr));
        computeButton->setText(QApplication::translate("ecuatiiClass", "Solve", nullptr));
        labelSol2->setText(QString());
        labelSol1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ecuatiiClass: public Ui_ecuatiiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECUATII_H
