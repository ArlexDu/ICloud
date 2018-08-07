#include "CenterWindow.h"
#include "cloudIO.h"
#include <qfileinfo.h>
CenterWindow::CenterWindow() {
	CenterWindow("");
}

CenterWindow::CenterWindow(QString path) { 

}

bool CenterWindow::initFromPath(QString path) {
	QFileInfo pathAnalyser(path);
	if (pathAnalyser.isFile()) {
		isDrawCloud = true;
		cloudIO* cloudio = new cloudIO(path.toStdString());
		if (cloudio->Read()) {
			Cloud c = cloudio->getCloud();
			//��ÿ������һ����Ӧ������ռ䣨�����������꣩
			ManipulatedFrame* frame = new ManipulatedFrame();
			frame->setTranslation(Vec(c.center[0],c.center[1],c.center[2]));
			frames.append(frame);
			//���¿��ǿռ�λ��
			if (bounds[0]==0&& bounds[1] == 0 && bounds[2] == 0 && bounds[3] == 0 && bounds[4] == 0 && bounds[5] == 0 ) {
				for (int i = 0; i < 6; i++) {
					bounds[i] = c.bounds[i];
				}
			}
			else {
				bounds[0] = c.bounds[0] < bounds[0] ? c.bounds[0]: bounds[0];
				bounds[1] = c.bounds[1] > bounds[1] ? c.bounds[1] : bounds[1];
				bounds[2] = c.bounds[2] < bounds[2] ? c.bounds[2] : bounds[2];
				bounds[3] = c.bounds[3] > bounds[3] ? c.bounds[3] : bounds[3];
				bounds[4] = c.bounds[4] < bounds[4] ? c.bounds[4] : bounds[4];
				bounds[5] = c.bounds[5] > bounds[5] ? c.bounds[5] : bounds[5];
			}
			cloudList.push_back(c);
			firstOpen = true;
			return true;
		}
	}
	else {
		qDebug() << "File is invalid";
	}
	return false;
}

void CenterWindow::postDraw() {
	QGLViewer::postDraw();
	drawCornerAxis();
}

void CenterWindow::drawWithNames() {
	drawCloud(true);
}
// Draws a spiral
void CenterWindow::draw() {
	Vec pos = camera()->position();
	//qDebug() << "camera postion "<<pos.x<<","<<pos.y<<","<<pos.z;
	if (isDrawCloud) {
		drawCloud();
	}
	else {
		const float nbSteps = 200.0;
		//drawAxis();
		glBegin(GL_QUADS);
		//��һ����
		glColor4f(1.0, 0.0, 0.0, 1.0f);
		glVertex3d(-0.5f, -0.5f, 0.5f);
		glVertex3d(-0.5f, 0.5f, 0.5f);
		glVertex3d(0.5f, 0.5f, 0.5f);
		glVertex3d(0.5f, -0.5f, 0.5f);
		//�ڶ�����
		glColor4f(0.0, 1.0, 0.0, 1.0f);
		glVertex3d(0.5f, -0.5f, 0.5f);
		glVertex3d(0.5f, 0.5f, 0.5f);
		glVertex3d(0.5f, 0.5f, -0.5f);
		glVertex3d(0.5f, -0.5f, -0.5f);
		//��������
		glColor4f(0.0, 0.0, 1.0, 1.0f);
		glVertex3d(0.5f, 0.5f, -0.5f);
		glVertex3d(0.5f, -0.5f, -0.5f);
		glVertex3d(-0.5f, -0.5f, -0.5f);
		glVertex3d(-0.5f, 0.5f, -0.5f);
		//���ĸ���
		glColor4f(1.0, 1.0, 0.0, 1.0f);
		glVertex3d(-0.5f, -0.5f, -0.5f);
		glVertex3d(-0.5f, 0.5f, -0.5f);
		glVertex3d(-0.5f, 0.5f, 0.5f);
		glVertex3d(-0.5f, -0.5f, 0.5f);
		//�������
		glColor4f(0.0, 1.0, 1.0, 1.0f);
		glVertex3d(-0.5f, 0.5f, 0.5f);
		glVertex3d(0.5f, 0.5f, 0.5f);
		glVertex3d(0.5f, 0.5f, -0.5f);
		glVertex3d(-0.5f, 0.5f, -0.5f);
		//�������
		glColor4f(1.0, 0.0, 1.0, 1.0f);
		glVertex3d(-0.5f, -0.5f, 0.5f);
		glVertex3d(0.5f, -0.5f, 0.5f);
		glVertex3d(0.5f, -0.5f, -0.5f);
		glVertex3d(-0.5f, -0.5f, -0.5f);
		glEnd();
	}
	//�������ӷ�Χ
	drawAxisCircle(ratio);
}

void CenterWindow::init() {
	firstOpen = false;
	isDrawCloud = false;
	AxisCirStep = 200;
	for (int i = 0; i < 6; i++) {
		bounds[i] = 0;
	}
	setSceneRadius(1);
	setSceneCenter(Vec(0,0,0));
	//camera()->fitSphere(Vec(0,0,0),8);
	glClearDepth(1.0);
	//������Ȳ���
	glEnable(GL_DEPTH_TEST);
	//������ɫ���
	glEnable(GL_BLEND);
	//���û�Ϸ�ʽ
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	//��������������ݵ�
	generateVolumeData(1,Vector3d(0,0,0));
	setMouseTracking(true);
	Vec camPos = camera()->position();
	ratio = sqrt(pow(camPos.x, 2)+pow(camPos.y, 2)+pow(camPos.z, 2));
	
	// Restore previous viewer state.
	//restoreStateFromFile();

	setFPSIsDisplayed();
	setManipulatedFrame(camera()->frame());
	//�󶨿�ݼ�
	setMouseBinding(Qt::AltModifier, Qt::LeftButton, QGLViewer::CAMERA,
		QGLViewer::ROTATE);
	setMouseBinding(Qt::AltModifier, Qt::RightButton, QGLViewer::CAMERA,
		QGLViewer::TRANSLATE);
	setMouseBinding(Qt::AltModifier, Qt::MidButton, QGLViewer::CAMERA,
		QGLViewer::ZOOM);
	setWheelBinding(Qt::AltModifier, QGLViewer::CAMERA, QGLViewer::ZOOM);

	setMouseBinding(Qt::NoModifier, Qt::LeftButton, QGLViewer::FRAME,
		QGLViewer::ROTATE);
	setMouseBinding(Qt::NoModifier, Qt::RightButton, QGLViewer::FRAME,
		QGLViewer::TRANSLATE);
	setMouseBinding(Qt::NoModifier, Qt::MidButton, QGLViewer::FRAME,
		QGLViewer::ZOOM);
	setWheelBinding(Qt::NoModifier, QGLViewer::FRAME, QGLViewer::ZOOM);


	// Opens help window
	//help();
}
void CenterWindow::drawBackground() {

}
void CenterWindow::drawLight() {

}
void CenterWindow::displatText() {

}

//������ת����Widgt
void CenterWindow::generateVolumeData(double radius, Vector3d center) {
	//��ɫ x��
	for (int i = 0; i < AxisCirStep; i++) {
		Vector3d point(0.0, radius*cos(2 * PI / AxisCirStep*i), radius*sin(2 * PI / AxisCirStep*i));
		point += center;
		VolumeData.push_back(point);
	}
	//��ɫ y��
	for (int i = 0; i < AxisCirStep; ++i)
	{
		Vector3d point(radius*cos(2 * PI / AxisCirStep*i), 0.0, radius*sin(2 * PI / AxisCirStep*i));
		point += center;
		VolumeData.push_back(point);//��������
	}
	//����Z��
	for (int i = 0; i < AxisCirStep; ++i)
	{
		Vector3d point(radius*cos(2 * PI / AxisCirStep*i), radius*sin(2 * PI / AxisCirStep*i), 0.0);
		point += center;
		VolumeData.push_back(point);//��������
	}
}

void CenterWindow::drawAxisCircle(double ratio) {
	glLineWidth(2.0);
	for (int a = 0; a < 3; a++) {
		glBegin(GL_LINE_LOOP);
		glColor4f(a == 0 ? 1.0f : 0.0f, a == 1 ? 1.0f : 0.0f, a == 2 ? 1.0f:0.0f,0.8f);
		for (int i = AxisCirStep*a; i < AxisCirStep*(a + 1); i++){
			glVertex3f(VolumeData[i](0)*ratio,
				VolumeData[i](1)*ratio, 
				VolumeData[i](2)*ratio);
		}
		glEnd();
	}

}


//��������
void CenterWindow::drawCloud(bool postSelection) {
	if (firstOpen) {//�����µĿ��ӿռ�Ĵ�С
		setSceneCenter(Vec((bounds[0] + bounds[1]) / 2, (bounds[2] + bounds[3]) / 2, (bounds[4] + bounds[5]) / 2));
		double radius = bounds[1] - bounds[0];
		radius = (bounds[3] - bounds[2])>radius?(bounds[3] - bounds[2]) : radius;
		radius = (bounds[5] - bounds[4])>radius ? (bounds[5] - bounds[4]) : radius;
		setSceneRadius(radius);
		showEntireScene();
		firstOpen = false;
	}
	//�����������飬�������е���
	for (int i = 0; i < cloudList.size(); i++) {
		Cloud cloud = cloudList[i];
		Vertex *cp = cloud.pointer;
		int cloudNum = cloud.cloudSize;
		//qDebug() << "cloud number is " << cloudNum;
		//����ÿ����Ĵ�С
		setPointSize(2);
		glPushMatrix();
		if (postSelection)
			glPushName(i);
		glMultMatrixd(frames[i]->matrix());
		if (i == selectedName()) {
			drawAxis(width() / 5.0f);
		}
		glBegin(GL_POINTS);
		if (i == selectedName()) {
			glColor4f(1.0, 1.0, 0.0, 1.0);
		}
		else
		{
			glColor4f(1.0, 0.0, 0.0, 1.0);
		}
		for (int k = 0; k < cloudNum; k++) {
			glVertex3d(cp[k].x-cloud.center[0], cp[k].y - cloud.center[1], cp[k].z-cloud.center[2]);
		}
		glEnd();
		//�ָ�Ĭ��opengl����Ĵ�С
		if (postSelection)
			glPopName();
		glPopMatrix();
		setPointSize(1);
	}
}

void CenterWindow::setPointSize(int size) {
	if (size <= 0 || size > 9) {
		glPointSize(1);
	}
	else
	{
		glPointSize(size);
	}
}

void CenterWindow::drawCornerAxis() {
	int viewport[4];
	int scissor[4];
	//���ڴ�С
	glGetIntegerv(GL_VIEWPORT,viewport);
	//�ü��ռ��С
	glGetIntegerv(GL_SCISSOR_BOX,scissor);

	//�����µĴ��ڴ�С
	const int size = 50;
	glViewport(0,0,size,size);
	//�����Ȼ���
	glClear(GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);
	glLineWidth(2.0);
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	//�������ڵļ��пռ�
	glOrtho(-1,1,-1,1,-1,1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixd(camera()->orientation().inverse().matrix());

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_LIGHTING);

	//�ָ�ԭ����״̬
	glScissor(scissor[0],scissor[1],scissor[2],scissor[3]);
	glViewport(viewport[0],viewport[1],viewport[2],viewport[3]);
	glLineWidth(1.0);
}

void CenterWindow::postSelection(const QPoint &point) {
	if (selectedName() == -1) {
		qDebug() << "No object selected under pixel " +
			QString::number(point.x()) + "," +
			QString::number(point.y());
		setManipulatedFrame(camera()->frame());
	}
	else {
		qDebug() << "Spiral number " + QString::number(selectedName()) +
			" selected under pixel " + QString::number(point.x()) + "," +
			QString::number(point.y());
		setManipulatedFrame(frames[selectedName()]);
	}
}