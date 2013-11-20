/********************************************************************************
** Form generated from reading UI file 'SphereDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHEREDIALOG_H
#define UI_SPHEREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SphereDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *stacksSpinBox;
    QLabel *label_2;
    QSpinBox *slicesSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SphereDialog)
    {
        if (SphereDialog->objectName().isEmpty())
            SphereDialog->setObjectName(QStringLiteral("SphereDialog"));
        SphereDialog->resize(397, 182);
        SphereDialog->setModal(true);
        verticalLayout = new QVBoxLayout(SphereDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(SphereDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        stacksSpinBox = new QSpinBox(groupBox);
        stacksSpinBox->setObjectName(QStringLiteral("stacksSpinBox"));
        stacksSpinBox->setMinimum(2);
        stacksSpinBox->setMaximum(99999);
        stacksSpinBox->setValue(10);

        gridLayout->addWidget(stacksSpinBox, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        slicesSpinBox = new QSpinBox(groupBox);
        slicesSpinBox->setObjectName(QStringLiteral("slicesSpinBox"));
        slicesSpinBox->setMinimum(2);
        slicesSpinBox->setMaximum(99999);
        slicesSpinBox->setValue(10);

        gridLayout->addWidget(slicesSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(SphereDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(stacksSpinBox);
        label_2->setBuddy(slicesSpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(stacksSpinBox, slicesSpinBox);
        QWidget::setTabOrder(slicesSpinBox, buttonBox);

        retranslateUi(SphereDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SphereDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SphereDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SphereDialog);
    } // setupUi

    void retranslateUi(QDialog *SphereDialog)
    {
        SphereDialog->setWindowTitle(QApplication::translate("SphereDialog", "Sphere Creation Parameters", 0));
        groupBox->setTitle(QApplication::translate("SphereDialog", "Sphere Mesh Parameters", 0));
        label->setText(QApplication::translate("SphereDialog", "Subdivisions bottom-to-top (stacks):", 0));
        label_2->setText(QApplication::translate("SphereDialog", "Subdivisions around (slices):", 0));
    } // retranslateUi

};

namespace Ui {
    class SphereDialog: public Ui_SphereDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHEREDIALOG_H
