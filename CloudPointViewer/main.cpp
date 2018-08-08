#include "CloudPointViewer.h"
#include <QtWidgets/QApplication>
#include <qobject.h>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CloudPointViewer window;
	window.show();
	return app.exec();
}