#pragma once
#include <qglviewer.h>
#include <qstring.h>
#include <qdebug.h>
#include <qlist.h>
#include <qvector3d.h>
#include <gl\GLU.h>
#include <Eigen\Core>
#include <Eigen\Dense>

#include <manipulatedFrame.h>
#include <manipulatedCameraFrame.h>

#include "CloudStruct.h"

using namespace std;
using namespace Eigen;
using namespace qglviewer;

class CenterWindow : public QGLViewer {
	Q_OBJECT
public:
	CenterWindow();
	CenterWindow(QString path);
	bool initFromPath(QString path);

protected:
	//draw֮����õĺ���
	virtual void postDraw();
	//Ĭ�ϵ��ú�������������
	virtual void draw();
	//Ĭ�ϵ��ú�������ʼ������
	virtual void init();
	//���û�����select�¼�֮�󣬵��øú���
	virtual void drawWithNames();
	//ѡ�����֮�󣬵Ļص�����
	virtual void postSelection(const QPoint &point);
signals:
private:
	//�����ı߽�
	double bounds[6];//minX maxX minY maxY minZ maxZ
	//�Ƿ�������ӵ���
	bool firstOpen;
	bool isDrawCloud;
	//��������
	QList<Cloud> cloudList;
	double ratio;
	int AxisCirStep;
	vector<Vector3d> VolumeData;
	//ÿ�����ƶ�Ӧ������ռ�
	QList<ManipulatedFrame*> frames;
	const GLfloat PI = 3.1415926536f;
	//�õ���������İ�ΧȦ����
	void generateVolumeData(double radius, Vector3d center);
	//�����������ת��ΧȦ
	void drawAxisCircle(double ratio);
	//�������½ǵ�����ռ������ϵ
	void drawCornerAxis();
	void drawBackground();
	void drawLight();
	void displatText();
	//��������
	void drawCloud(bool postSelection = false);
	//���õ�Ĵ�С
	void setPointSize(int size);
};