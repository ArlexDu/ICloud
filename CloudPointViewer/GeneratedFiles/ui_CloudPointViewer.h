/********************************************************************************
** Form generated from reading UI file 'CloudPointViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDPOINTVIEWER_H
#define UI_CLOUDPOINTVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloudPointViewerClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionColorBar;
    QAction *action;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *fileLayout;
    QTreeView *fileview;
    QHBoxLayout *ViewLayout;
    QHBoxLayout *InforLayout;
    QTableView *information;
    QHBoxLayout *WaveLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CloudPointViewerClass)
    {
        if (CloudPointViewerClass->objectName().isEmpty())
            CloudPointViewerClass->setObjectName(QStringLiteral("CloudPointViewerClass"));
        CloudPointViewerClass->resize(952, 633);
        actionOpen = new QAction(CloudPointViewerClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(CloudPointViewerClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionColorBar = new QAction(CloudPointViewerClass);
        actionColorBar->setObjectName(QStringLiteral("actionColorBar"));
        action = new QAction(CloudPointViewerClass);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(CloudPointViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(6);
        fileLayout->setObjectName(QStringLiteral("fileLayout"));
        fileview = new QTreeView(centralWidget);
        fileview->setObjectName(QStringLiteral("fileview"));

        fileLayout->addWidget(fileview);


        horizontalLayout->addLayout(fileLayout);

        ViewLayout = new QHBoxLayout();
        ViewLayout->setSpacing(6);
        ViewLayout->setObjectName(QStringLiteral("ViewLayout"));

        horizontalLayout->addLayout(ViewLayout);

        InforLayout = new QHBoxLayout();
        InforLayout->setSpacing(6);
        InforLayout->setObjectName(QStringLiteral("InforLayout"));
        information = new QTableView(centralWidget);
        information->setObjectName(QStringLiteral("information"));

        InforLayout->addWidget(information);


        horizontalLayout->addLayout(InforLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        WaveLayout = new QHBoxLayout();
        WaveLayout->setSpacing(6);
        WaveLayout->setObjectName(QStringLiteral("WaveLayout"));

        verticalLayout->addLayout(WaveLayout);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);

        CloudPointViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CloudPointViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 952, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        CloudPointViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CloudPointViewerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CloudPointViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CloudPointViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CloudPointViewerClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menuEdit->addAction(actionColorBar);
        menuEdit->addAction(action);

        retranslateUi(CloudPointViewerClass);

        QMetaObject::connectSlotsByName(CloudPointViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CloudPointViewerClass)
    {
        CloudPointViewerClass->setWindowTitle(QApplication::translate("CloudPointViewerClass", "CloudPointViewer", nullptr));
        actionOpen->setText(QApplication::translate("CloudPointViewerClass", "\346\211\223\345\274\200", nullptr));
        actionSave->setText(QApplication::translate("CloudPointViewerClass", "\344\277\235\345\255\230", nullptr));
        actionColorBar->setText(QApplication::translate("CloudPointViewerClass", "ColorBar", nullptr));
        action->setText(QApplication::translate("CloudPointViewerClass", "\347\211\207\351\235\242\345\214\226", nullptr));
        menu->setTitle(QApplication::translate("CloudPointViewerClass", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QApplication::translate("CloudPointViewerClass", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CloudPointViewerClass: public Ui_CloudPointViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDPOINTVIEWER_H
