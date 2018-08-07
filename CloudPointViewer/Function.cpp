#include "Function.h"
#include <QApplication>
int getScreenHeight() {
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect screenRect = desktopWidget->screenGeometry();
	return screenRect.height();
}

int getScreenWidth() {
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect screenRect = desktopWidget->screenGeometry();
	return screenRect.width();
}