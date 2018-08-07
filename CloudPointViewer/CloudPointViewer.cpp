#include "CloudPointViewer.h"
#include "Function.h"
#include <qfiledialog.h>
CloudPointViewer::CloudPointViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initAll();
	
}

void CloudPointViewer::initAll() {
	resizeWindow();
	initWindow();
}

void CloudPointViewer::initWindow() {
	std::string title = std::string("CloudPoint Viewer");
	setWindowTitle(QString::fromLocal8Bit(title.c_str()));
	//³õÊ¼»¯3D¿Ø¼þ
	ViewerWindow = new CenterWindow();
	ui.ViewLayout->addWidget(ViewerWindow);
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
		0, "open cloud point file", "", "Cloud Files(*.txt)");
	qDebug() << "open file is " << filename;
	ViewerWindow->initFromPath(filename);
}