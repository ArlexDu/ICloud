#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CloudPointViewer.h"
#include "CenterWindow.h"
#include "Function.h"
#include "ReadThread.h"
#include <qfiledialog.h>
#include <qstandarditemmodel.h>
#include <qobject.h>
#include <qprogressbar.h>

class CloudPointViewer : public QMainWindow
{
	Q_OBJECT

public:
	CloudPointViewer(QWidget *parent = Q_NULLPTR);

public slots:
	void on_actionOpen_triggered();
	void addFileTree(Cloud cloud);
	signals:
	void deleteFile(int i);

private:
	QList<QDockWidget*> m_docks;
	Ui::CloudPointViewerClass ui;
	//�ļ��б�ģ��
	QStandardItemModel* fileModel;
	//��ȡ�ļ��߳�
	ReadThread thread;
	//������
	QProgressBar* pProgressBar;
	void initAll();
	void resizeWindow();
};
