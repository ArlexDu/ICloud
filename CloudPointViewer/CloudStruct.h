#pragma once
#include <iostream>
//每个点的数据格式
struct Vertex {
	int ID;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double R = 0.0;
	double G = 0.0;
	double B = 0.0;
	double A = 0.0;
};

//点云文件的数据格式
struct Cloud {
	Vertex* pointer;
	std::string cloudPath;
	std::string basePath;
	std::string FolderPath;
	int cloudSize;
	double bounds[6];
	double center[3];
};
