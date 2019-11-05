/********************************************************************************
** Form generated from reading UI file 'Symptoms.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMPTOMS_H
#define UI_SYMPTOMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Symptoms
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *Symptoms)
    {
        if (Symptoms->objectName().isEmpty())
            Symptoms->setObjectName(QString::fromUtf8("Symptoms"));
        Symptoms->resize(400, 300);
        verticalLayout = new QVBoxLayout(Symptoms);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Symptoms);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(Symptoms);

        QMetaObject::connectSlotsByName(Symptoms);
    } // setupUi

    void retranslateUi(QWidget *Symptoms)
    {
        Symptoms->setWindowTitle(QApplication::translate("Symptoms", "Symptoms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Symptoms: public Ui_Symptoms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMPTOMS_H
