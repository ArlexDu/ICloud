#include "CloudPointViewer.h"
#include <qmetatype.h>
CloudPointViewer::CloudPointViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initAll();
	
}

void CloudPointViewer::initAll() {
	resizeWindow();
	CenterWindow* centerWindow = new CenterWindow();
	//绑定槽函数
	qRegisterMetaType<Cloud>("Cloud");
	QObject::connect(&thread, SIGNAL(readComplete(Cloud)), this, SLOT(addFileTree(Cloud)));
	QObject::connect(&thread, SIGNAL(readComplete(Cloud)), centerWindow, SLOT(addCloud(Cloud)));
	QObject::connect(&thread, SIGNAL(sendProgress(double)), centerWindow, SLOT(setProgress(double)));
	std::string title = std::string("CloudPoint Viewer");
	setWindowTitle(QString::fromLocal8Bit(title.c_str()));
	//初始化3D控件
	ui.ViewLayout->addWidget(centerWindow);
	//初始化文件列表
	fileModel = new QStandardItemModel();
	ui.fileview->header()->hide();
	ui.fileview->setModel(fileModel);
}

void CloudPointViewer::resizeWindow(){
	int ScreenWidth = getScreenWidth();
	int ScreenHeight = getScreenHeight();
	qDebug() << ScreenWidth << " " << ScreenHeight << endl;
	this->resize(QSize(ScreenWidth, ScreenHeight));
	move(0,0);

}

void CloudPointViewer::on_actionOpen_triggered() {
	QString filename = QFileDialog::getOpenFileName(
		0, "open cloud point file", "", "Cloud Files(*.*)");
	qDebug() << "open file is " << filename;
	QFileInfo pathAnalyser(filename);
	if (pathAnalyser.isFile()) {
		
		thread.setPath(filename.toStdString());
		if (!thread.isRunning()) {
			thread.start();
		}
	}
	else {
		qDebug() << "File is invalid";
	}
}

//当文件读取完毕后展示在右侧文件树
void CloudPointViewer::addFileTree(Cloud cloud) {
	qDebug() << "read complete";
	QStandardItem* nameRoot = new QStandardItem(QString::fromLocal8Bit(cloud.name.c_str()));
	fileModel->appendRow(nameRoot);
	QStandardItem* information = new QStandardItem(QString::fromLocal8Bit("属性"));
	nameRoot->appendRow(information);
}