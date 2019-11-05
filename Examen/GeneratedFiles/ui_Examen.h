/********************************************************************************
** Form generated from reading UI file 'Examen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMEN_H
#define UI_EXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamenClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListView *filesView;
    QGridLayout *gridLayout_2;
    QLineEdit *nameEdit;
    QPushButton *addButton;
    QPushButton *revisedButton;
    QLabel *revisedLabel;
    QLabel *revisedValue;
    QLabel *haveLabel;
    QLabel *haveTo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamenClass)
    {
        if (ExamenClass->objectName().isEmpty())
            ExamenClass->setObjectName(QString::fromUtf8("ExamenClass"));
        ExamenClass->resize(600, 400);
        centralWidget = new QWidget(ExamenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        filesView = new QListView(centralWidget);
        filesView->setObjectName(QString::fromUtf8("filesView"));

        gridLayout->addWidget(filesView, 0, 0, 1, 4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout_2->addWidget(nameEdit, 1, 0, 1, 1);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout_2->addWidget(addButton, 1, 1, 1, 1);

        revisedButton = new QPushButton(centralWidget);
        revisedButton->setObjectName(QString::fromUtf8("revisedButton"));

        gridLayout_2->addWidget(revisedButton, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 4, 1, 1);

        revisedLabel = new QLabel(centralWidget);
        revisedLabel->setObjectName(QString::fromUtf8("revisedLabel"));

        gridLayout->addWidget(revisedLabel, 1, 0, 1, 1);

        revisedValue = new QLabel(centralWidget);
        revisedValue->setObjectName(QString::fromUtf8("revisedValue"));

        gridLayout->addWidget(revisedValue, 1, 1, 1, 1);

        haveLabel = new QLabel(centralWidget);
        haveLabel->setObjectName(QString::fromUtf8("haveLabel"));

        gridLayout->addWidget(haveLabel, 1, 2, 1, 1);

        haveTo = new QLabel(centralWidget);
        haveTo->setObjectName(QString::fromUtf8("haveTo"));

        gridLayout->addWidget(haveTo, 1, 3, 1, 1);

        ExamenClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExamenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        ExamenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExamenClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExamenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ExamenClass->setStatusBar(statusBar);

        retranslateUi(ExamenClass);

        QMetaObject::connectSlotsByName(ExamenClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamenClass)
    {
        ExamenClass->setWindowTitle(QApplication::translate("ExamenClass", "Examen", nullptr));
        addButton->setText(QApplication::translate("ExamenClass", "Add", nullptr));
        revisedButton->setText(QApplication::translate("ExamenClass", "Revised", nullptr));
        revisedLabel->setText(QApplication::translate("ExamenClass", "Revised:", nullptr));
        revisedValue->setText(QString());
        haveLabel->setText(QApplication::translate("ExamenClass", "Have to revised:", nullptr));
        haveTo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExamenClass: public Ui_ExamenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMEN_H
