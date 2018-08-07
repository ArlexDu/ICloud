#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CloudPointViewer.h"
#include "CenterWindow.h"

class CloudPointViewer : public QMainWindow
{
	Q_OBJECT

public:
	CloudPointViewer(QWidget *parent = Q_NULLPTR);

public slots:
	void on_actionOpen_triggered();

private:
	QList<QDockWidget*> m_docks;
	Ui::CloudPointViewerClass ui;
	CenterWindow* ViewerWindow;
	void initAll();
	void initWindow();
	void resizeWindow();
	void setCenterView(QWidget* viewer);
};
