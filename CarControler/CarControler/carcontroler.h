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
	//打开相机，创建VideoCapture
	void openCam();
	//关闭相机，释放VideoCapture
	void closeCam();
	//每次timer计时达到预期后调用，截取一帧，进行图像处理
	void readFrame();
	//通过串口连接小车
	void connectCar();
	//断开与小车的连接
	void disconnectCar();

private:
	Ui::CarControlerClass ui;

	bool isCamOpen_;//相机是否打开
	VideoCapture *pvcCapture_;//用于获取相机信息的类

	QTimer *camTimer_;//定时器，用于定时获取相机的一帧
	Mat mFrame_;//相机的一帧
	QImage img_;//显示在界面上的帧

	vector<Scalar> scalars;//满足要求的颜色,格式BGR

	QSerialPort *serial_;//用于串口通讯的类
	bool isSerialOpen_;//串口是否打开
};

#endif // CARCONTROLER_H
