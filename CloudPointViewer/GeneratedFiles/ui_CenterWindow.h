/********************************************************************************
** Form generated from reading UI file 'CenterWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTERWINDOW_H
#define UI_CENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CenterWindow
{
public:
    QDockWidget *Viewer3D;
    QWidget *dockWidgetContents;
    QTabWidget *Tab_3D;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *CenterWindow)
    {
        if (CenterWindow->objectName().isEmpty())
            CenterWindow->setObjectName(QStringLiteral("CenterWindow"));
        CenterWindow->resize(696, 538);
        Viewer3D = new QDockWidget(CenterWindow);
        Viewer3D->setObjectName(QStringLiteral("Viewer3D"));
        Viewer3D->setGeometry(QRect(0, 0, 121, 541));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        Tab_3D = new QTabWidget(dockWidgetContents);
        Tab_3D->setObjectName(QStringLiteral("Tab_3D"));
        Tab_3D->setGeometry(QRect(0, 0, 127, 80));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Tab_3D->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Tab_3D->addTab(tab_2, QString());
        Viewer3D->setWidget(dockWidgetContents);

        retranslateUi(CenterWindow);

        Tab_3D->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CenterWindow);
    } // setupUi

    void retranslateUi(QWidget *CenterWindow)
    {
        CenterWindow->setWindowTitle(QApplication::translate("CenterWindow", "CenterWindow", nullptr));
        Tab_3D->setTabText(Tab_3D->indexOf(tab), QApplication::translate("CenterWindow", "Tab 1", nullptr));
        Tab_3D->setTabText(Tab_3D->indexOf(tab_2), QApplication::translate("CenterWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CenterWindow: public Ui_CenterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTERWINDOW_H
