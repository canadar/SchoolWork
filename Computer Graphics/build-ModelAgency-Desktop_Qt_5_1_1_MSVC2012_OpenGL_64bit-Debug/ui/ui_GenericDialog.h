/********************************************************************************
** Form generated from reading UI file 'GenericDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERICDIALOG_H
#define UI_GENERICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GenericDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QDoubleSpinBox *parameter3SpinBox;
    QDoubleSpinBox *parameter2SpinBox;
    QDoubleSpinBox *parameter1SpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GenericDialog)
    {
        if (GenericDialog->objectName().isEmpty())
            GenericDialog->setObjectName(QStringLiteral("GenericDialog"));
        GenericDialog->resize(292, 223);
        GenericDialog->setModal(true);
        verticalLayout = new QVBoxLayout(GenericDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(GenericDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        parameter3SpinBox = new QDoubleSpinBox(groupBox);
        parameter3SpinBox->setObjectName(QStringLiteral("parameter3SpinBox"));
        parameter3SpinBox->setMaximum(999999);
        parameter3SpinBox->setValue(10);

        gridLayout->addWidget(parameter3SpinBox, 2, 1, 1, 1);

        parameter2SpinBox = new QDoubleSpinBox(groupBox);
        parameter2SpinBox->setObjectName(QStringLiteral("parameter2SpinBox"));
        parameter2SpinBox->setMaximum(999999);
        parameter2SpinBox->setValue(10);

        gridLayout->addWidget(parameter2SpinBox, 1, 1, 1, 1);

        parameter1SpinBox = new QDoubleSpinBox(groupBox);
        parameter1SpinBox->setObjectName(QStringLiteral("parameter1SpinBox"));
        parameter1SpinBox->setMaximum(999999);
        parameter1SpinBox->setValue(10);

        gridLayout->addWidget(parameter1SpinBox, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(GenericDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(parameter2SpinBox);
        label->setBuddy(parameter1SpinBox);
        label_3->setBuddy(parameter3SpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(parameter1SpinBox, parameter2SpinBox);
        QWidget::setTabOrder(parameter2SpinBox, buttonBox);

        retranslateUi(GenericDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GenericDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GenericDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GenericDialog);
    } // setupUi

    void retranslateUi(QDialog *GenericDialog)
    {
        GenericDialog->setWindowTitle(QApplication::translate("GenericDialog", "Generic Mesh Creation Parameters", 0));
        groupBox->setTitle(QApplication::translate("GenericDialog", "Generic Mesh Parameters (optional)", 0));
        label_2->setText(QApplication::translate("GenericDialog", "Parameter 2:", 0));
        label->setText(QApplication::translate("GenericDialog", "Parameter 1:", 0));
        label_3->setText(QApplication::translate("GenericDialog", "Parameter 3:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenericDialog: public Ui_GenericDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERICDIALOG_H
