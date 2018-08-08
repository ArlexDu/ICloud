#include "ReadThread.h"

ReadThread::ReadThread(QObject *parent)
	: QThread(parent)
{

}

ReadThread::~ReadThread()
{
}

void ReadThread::setPath(std::string p) {
	path = p;
	cloud.cloudPath = path;
	QFileInfo fileInfo(QString::fromStdString(path));
	cloud.folderPath = fileInfo.path().toStdString();
	cloud.name = fileInfo.fileName().toStdString();
}

//�������߳�
void ReadThread::run() {
	qDebug() << "run in thread";
	readPointCloudFromPath();
}

//����ļ��ĵ���������
int ReadThread::getFileCount() {
	std::ifstream fin;
	fin.open(cloud.cloudPath);
	int lineCt = 0;
	char c;
	while (fin.get(c)) {
		if (c == '\n') {
			lineCt++;
		}
	}
	lineCt++;
	fin.close();
	return lineCt;
}

//��ȡ��������
bool ReadThread::readPointCloudFromPath() {
	return ReadPointCloudFromTXT();
}

//��txt��ȡ��������
bool ReadThread::ReadPointCloudFromTXT() {
	qDebug() << "Read TXT";
	long start, end;
	start = clock();
	int lineCt = getFileCount();
	cloud.pointer = new Vertex[lineCt];
	cloud.cloudSize = lineCt;
	//��ʹ����ͨ��fstream���ļ���֮���Ǹ���Ϊ�ڴ��ļ�ӳ��
	std::ifstream fin;
	fin.open(cloud.cloudPath);
	std::string str;
	int i = 0;
	double minX = 0, maxX = 0, minY = 0, maxY = 0, minZ = 0, maxZ = 0;
	double progress = 0.0;
	while (!fin.eof()) {
		getline(fin, str);
		boost::trim(str);
		std::vector<std::string> vec;
		boost::split(vec, str, boost::is_any_of(","));
		if (vec.size() == 3) {
			cloud.pointer[i].x = atof(vec[0].c_str());
			cloud.pointer[i].y = atof(vec[1].c_str());
			cloud.pointer[i].z = atof(vec[2].c_str());
		}
		if (i == 0) {
			minX = cloud.pointer[i].x;
			minY = cloud.pointer[i].y;
			minZ = cloud.pointer[i].z;
			maxX = cloud.pointer[i].x;
			maxY = cloud.pointer[i].y;
			maxZ = cloud.pointer[i].z;
		}
		else {
			minX = cloud.pointer[i].x < minX ? cloud.pointer[i].x : minX;
			maxX = cloud.pointer[i].x > maxX ? cloud.pointer[i].x : maxX;
			minY = cloud.pointer[i].y < minY ? cloud.pointer[i].y : minY;
			maxY = cloud.pointer[i].y > minY ? cloud.pointer[i].y : maxY;
			minZ = cloud.pointer[i].z < minZ ? cloud.pointer[i].z : minZ;
			maxZ = cloud.pointer[i].z > maxZ ? cloud.pointer[i].z : maxZ;
		}
		progress = (double)i / lineCt;
		emit sendProgress(progress);
		i++;
	}
	cloud.bounds[0] = minX;
	cloud.bounds[1] = maxX;
	cloud.bounds[2] = minY;
	cloud.bounds[3] = maxY;
	cloud.bounds[4] = minZ;
	cloud.bounds[5] = maxZ;
	cloud.center[0] = (minX + maxX) / 2;
	cloud.center[1] = (minY + maxY) / 2;
	cloud.center[2] = (minZ + maxZ) / 2;
	fin.close();
	end = clock();
	qDebug() << "Totle Time : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	emit readComplete(cloud);
	return true;
}
