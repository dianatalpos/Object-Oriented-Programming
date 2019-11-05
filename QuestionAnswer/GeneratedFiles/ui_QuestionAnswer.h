/********************************************************************************
** Form generated from reading UI file 'QuestionAnswer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONANSWER_H
#define UI_QUESTIONANSWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionAnswerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListView *questionView;
    QLineEdit *questionEdit;
    QPushButton *addButton;
    QListWidget *answerList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuestionAnswerClass)
    {
        if (QuestionAnswerClass->objectName().isEmpty())
            QuestionAnswerClass->setObjectName(QString::fromUtf8("QuestionAnswerClass"));
        QuestionAnswerClass->resize(600, 400);
        centralWidget = new QWidget(QuestionAnswerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        questionView = new QListView(centralWidget);
        questionView->setObjectName(QString::fromUtf8("questionView"));

        gridLayout->addWidget(questionView, 0, 0, 1, 2);

        questionEdit = new QLineEdit(centralWidget);
        questionEdit->setObjectName(QString::fromUtf8("questionEdit"));

        gridLayout->addWidget(questionEdit, 1, 0, 1, 1);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 1, 1, 1, 1);

        answerList = new QListWidget(centralWidget);
        answerList->setObjectName(QString::fromUtf8("answerList"));

        gridLayout->addWidget(answerList, 0, 2, 1, 1);

        QuestionAnswerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QuestionAnswerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        QuestionAnswerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuestionAnswerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QuestionAnswerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QuestionAnswerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QuestionAnswerClass->setStatusBar(statusBar);

        retranslateUi(QuestionAnswerClass);

        QMetaObject::connectSlotsByName(QuestionAnswerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QuestionAnswerClass)
    {
        QuestionAnswerClass->setWindowTitle(QApplication::translate("QuestionAnswerClass", "QuestionAnswer", nullptr));
        addButton->setText(QApplication::translate("QuestionAnswerClass", "Add Question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionAnswerClass: public Ui_QuestionAnswerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONANSWER_H
