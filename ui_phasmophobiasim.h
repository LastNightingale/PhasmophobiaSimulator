/********************************************************************************
** Form generated from reading UI file 'phasmophobiasim.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHASMOPHOBIASIM_H
#define UI_PHASMOPHOBIASIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhasmophobiaSim
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PhasmophobiaSim)
    {
        if (PhasmophobiaSim->objectName().isEmpty())
            PhasmophobiaSim->setObjectName(QString::fromUtf8("PhasmophobiaSim"));
        PhasmophobiaSim->resize(800, 600);
        centralwidget = new QWidget(PhasmophobiaSim);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PhasmophobiaSim->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PhasmophobiaSim);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        PhasmophobiaSim->setMenuBar(menubar);
        statusbar = new QStatusBar(PhasmophobiaSim);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PhasmophobiaSim->setStatusBar(statusbar);

        retranslateUi(PhasmophobiaSim);

        QMetaObject::connectSlotsByName(PhasmophobiaSim);
    } // setupUi

    void retranslateUi(QMainWindow *PhasmophobiaSim)
    {
        PhasmophobiaSim->setWindowTitle(QCoreApplication::translate("PhasmophobiaSim", "PhasmophobiaSim", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhasmophobiaSim: public Ui_PhasmophobiaSim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHASMOPHOBIASIM_H
