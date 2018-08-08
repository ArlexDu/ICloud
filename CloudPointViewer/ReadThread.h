#pragma once

#include <QThread>
#include <fstream>
#include <time.h>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>
#include <boost\algorithm\string\classification.hpp>
#include"CloudStruct.h"
#include <qdebug.h>
#include <qfileinfo.h>

class ReadThread : public QThread
{
	Q_OBJECT

public:
	ReadThread(QObject *parent=0);
	~ReadThread();
	void setPath(std::string p);
public slots:
	signals:
		void readComplete(Cloud c);
		void sendProgress(double c);
protected:
	std::string path;
	void run();
private:	
	Cloud cloud;
	int getFileCount();
	bool readPointCloudFromPath();
	bool ReadPointCloudFromTXT();
};
