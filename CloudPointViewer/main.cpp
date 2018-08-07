#include "CloudPointViewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CloudPointViewer w;
	w.show();
	return a.exec();
}
