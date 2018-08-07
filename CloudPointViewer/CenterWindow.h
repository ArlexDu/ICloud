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
	//draw之后调用的函数
	virtual void postDraw();
	//默认调用函数，画出场景
	virtual void draw();
	//默认调用函数，初始化函数
	virtual void init();
	//当用户发出select事件之后，调用该函数
	virtual void drawWithNames();
	//选择完成之后，的回调函数
	virtual void postSelection(const QPoint &point);
signals:
private:
	//场景的边界
	double bounds[6];//minX maxX minY maxY minZ maxZ
	//是否是新添加点云
	bool firstOpen;
	bool isDrawCloud;
	//点云数组
	QList<Cloud> cloudList;
	double ratio;
	int AxisCirStep;
	vector<Vector3d> VolumeData;
	//每个点云对应的坐标空间
	QList<ManipulatedFrame*> frames;
	const GLfloat PI = 3.1415926536f;
	//得到对象物体的包围圈数据
	void generateVolumeData(double radius, Vector3d center);
	//画出对象的旋转包围圈
	void drawAxisCircle(double ratio);
	//画出右下角的世界空间的坐标系
	void drawCornerAxis();
	void drawBackground();
	void drawLight();
	void displatText();
	//画出点云
	void drawCloud(bool postSelection = false);
	//设置点的大小
	void setPointSize(int size);
};