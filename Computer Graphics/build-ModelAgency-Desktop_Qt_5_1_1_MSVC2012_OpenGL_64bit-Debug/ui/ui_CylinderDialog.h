/********************************************************************************
** Form generated from reading UI file 'CylinderDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYLINDERDIALOG_H
#define UI_CYLINDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CylinderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *slicesSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CylinderDialog)
    {
        if (CylinderDialog->objectName().isEmpty())
            CylinderDialog->setObjectName(QStringLiteral("CylinderDialog"));
        CylinderDialog->resize(350, 127);
        CylinderDialog->setModal(true);
        verticalLayout = new QVBoxLayout(CylinderDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(CylinderDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        slicesSpinBox = new QSpinBox(groupBox);
        slicesSpinBox->setObjectName(QStringLiteral("slicesSpinBox"));
        slicesSpinBox->setMinimum(2);
        slicesSpinBox->setMaximum(99999);
        slicesSpinBox->setValue(10);

        horizontalLayout->addWidget(slicesSpinBox);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(CylinderDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(slicesSpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(slicesSpinBox, buttonBox);

        retranslateUi(CylinderDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CylinderDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CylinderDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CylinderDialog);
    } // setupUi

    void retranslateUi(QDialog *CylinderDialog)
    {
        CylinderDialog->setWindowTitle(QApplication::translate("CylinderDialog", "Cylinder Creation Parameters", 0));
        groupBox->setTitle(QApplication::translate("CylinderDialog", "Cylinder Mesh Parameters", 0));
        label_2->setText(QApplication::translate("CylinderDialog", "Subdivisions around (slices):", 0));
    } // retranslateUi

};

namespace Ui {
    class CylinderDialog: public Ui_CylinderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYLINDERDIALOG_H
