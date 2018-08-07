#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <boost\algorithm\string.hpp>
#include <boost\algorithm\string\split.hpp>
#include <boost\algorithm\string\classification.hpp>
#include"CloudStruct.h"
#include <qdebug.h>

using namespace std;
using namespace boost;

class cloudIO {
public:
	cloudIO();
	cloudIO(string path);
	bool Read();
	Cloud getCloud();
private:
	Cloud cloud;
	void setPath(string path);
	int getFileCount();
	bool readPointCloudFromPath();
	bool ReadPointCloudFromTXT();
};