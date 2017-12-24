#ifndef CARCONTROLER_H
#define CARCONTROLER_H

#include <QtWidgets/QMainWindow>
#include "ui_carcontroler.h"

#include "matQImageConvert.h"
#include "imageProcess.h"

#include "QtMultimedia\qcamerainfo.h"
#include "QtSerialPort\qserialport.h"
#include "QtSerialPort\qserialportinfo.h"
#include "qtimer.h"
#include "qmessagebox.h"

using namespace cv;

class CarControler : public QMainWindow
{
	Q_OBJECT

public:
	CarControler(QWidget *parent = 0);
	~CarControler();

private slots:
	//�����������VideoCapture
	void openCam();
	//�ر�������ͷ�VideoCapture
	void closeCam();
	//ÿ��timer��ʱ�ﵽԤ�ں���ã���ȡһ֡������ͼ����
	void readFrame();
	//ͨ����������С��
	void connectCar();
	//�Ͽ���С��������
	void disconnectCar();

private:
	Ui::CarControlerClass ui;

	bool isCamOpen_;//����Ƿ��
	VideoCapture *pvcCapture_;//���ڻ�ȡ�����Ϣ����

	QTimer *camTimer_;//��ʱ�������ڶ�ʱ��ȡ�����һ֡
	Mat mFrame_;//�����һ֡
	QImage img_;//��ʾ�ڽ����ϵ�֡

	vector<Scalar> scalars;//����Ҫ�����ɫ,��ʽBGR

	QSerialPort *serial_;//���ڴ���ͨѶ����
	bool isSerialOpen_;//�����Ƿ��
};

#endif // CARCONTROLER_H
