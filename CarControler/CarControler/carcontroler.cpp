#include "carcontroler.h"

CarControler::CarControler(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	camTimer_ = new QTimer(this);
	isCamOpen_ = false;
	isSerialOpen_ = false;

	//为label加边框
	ui.labelOri->setFrameShape(QFrame::Box);
	ui.labelOri->setStyleSheet(QStringLiteral("border:1px solid #000"));

	ui.labelProcessed->setFrameShape(QFrame::Box);
	ui.labelProcessed->setStyleSheet(QStringLiteral("border:1px solid #000"));
	
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		ui.comboBoxPort->addItem(info.portName());
	}

	//ui.comboBoxPort->addItem("COM1");
	//ui.comboBoxPort->addItem("COM2");
	//ui.comboBoxPort->addItem("COM3");
	//ui.comboBoxPort->addItem("COM4");
	//ui.comboBoxPort->addItem("COM5");

	scalars.push_back(Scalar(10,10,200));
	scalars.push_back(Scalar(255, 0, 0));
	scalars.push_back(Scalar(0, 190, 0));
	//在此添加更多的颜色

	for (const auto Iter : QCameraInfo::availableCameras())
	{
		ui.comboBoxCam->addItem(Iter.description());
	}

	QObject::connect(ui.btnOpenCam, SIGNAL(released()), this, SLOT(openCam()));
	QObject::connect(ui.btnCloseCam, SIGNAL(released()), this, SLOT(closeCam()));
	QObject::connect(camTimer_, SIGNAL(timeout()), this, SLOT(readFrame()));
	QObject::connect(ui.btnConnect, SIGNAL(released()), this, SLOT(connectCar()));
	QObject::connect(ui.btnDisconnect, SIGNAL(released()), this, SLOT(disconnectCar()));
}

CarControler::~CarControler()
{
	if (isCamOpen_)
		delete pvcCapture_;
	if (camTimer_ != NULL)
		delete camTimer_;
}

void CarControler::openCam()
{
	if (isCamOpen_)
		return;
	pvcCapture_ = new VideoCapture(ui.comboBoxCam->currentIndex());
	ui.checkBoxCamInfo->setChecked(true);
	ui.comboBoxCam->setEnabled(false);
	isCamOpen_ = true;
	camTimer_->start(37);
}

void CarControler::closeCam()
{
	if (isCamOpen_)
	{
		delete pvcCapture_;
	}
	camTimer_->stop();
	ui.checkBoxCamInfo->setChecked(false);
	ui.comboBoxCam->setEnabled(true);
	isCamOpen_ = false;
	//ui.labelOri->setPixmap(QPixmap());
	//ui.labelProcessed->setPixmap(QPixmap());
}

void CarControler::readFrame()
{
	*pvcCapture_ >> mFrame_;
	
	cv::resize(mFrame_, mFrame_, Size(480, 360));
	flip(mFrame_, mFrame_,1);
	MatToQImage(mFrame_, img_);
	ui.labelOri->setPixmap(QPixmap::fromImage(img_));

	switch (imageProcess(mFrame_, mFrame_, scalars))
	{
	case CAR_MOVE_FORWARD:
		MatToQImage(mFrame_, img_);
		ui.labelProcessed->setPixmap(QPixmap::fromImage(img_));
		if (ui.radioButtonTrue->isChecked() && isSerialOpen_)
		{
			serial_->write(QString('1').toLatin1());
			serial_->waitForBytesWritten(0);
		}
		break;
	case CAR_MOVE_BACK:
		MatToQImage(mFrame_, img_);
		ui.labelProcessed->setPixmap(QPixmap::fromImage(img_));
		if (ui.radioButtonTrue->isChecked() && isSerialOpen_)
		{
			serial_->write(QString('4').toLatin1());
			serial_->waitForBytesWritten(0);
		}
		break;
	case CAR_MOVE_LEFT:
		MatToQImage(mFrame_, img_);
		ui.labelProcessed->setPixmap(QPixmap::fromImage(img_));
		if (ui.radioButtonTrue->isChecked() && isSerialOpen_)
		{
			serial_->write(QString('2').toLatin1());
			serial_->waitForBytesWritten(0);
		}
		break;
	case CAR_MOVE_RIGHT:
		MatToQImage(mFrame_, img_);
		ui.labelProcessed->setPixmap(QPixmap::fromImage(img_));
		if (ui.radioButtonTrue->isChecked() && isSerialOpen_)
		{
			serial_->write(QString('3').toLatin1());
			serial_->waitForBytesWritten(0);
		}
		break;
	default:
		ui.labelProcessed->setPixmap(QPixmap::fromImage(img_));
		break;
	}
}

void CarControler::connectCar()
{
	if (isSerialOpen_)
		return;
	serial_ = new QSerialPort;
	//设置串口名
	serial_->setPortName(ui.comboBoxPort->currentText());
	//打开串口
	serial_->open(QIODevice::WriteOnly);
	//设置波特率
	serial_->setBaudRate(QSerialPort::Baud9600);
	//设置数据位数
	serial_->setDataBits(QSerialPort::Data8);
	//设置奇偶校验
	serial_->setParity(QSerialPort::Parity::OddParity);
	//设置停止位
	switch (ui.comboBoxStop->currentIndex())
	{
	case 1: serial_->setStopBits(QSerialPort::OneStop); break;
	case 2: serial_->setStopBits(QSerialPort::TwoStop); break;
	default: break;
	}
	//设置流控制
	serial_->setFlowControl(QSerialPort::FlowControl::NoFlowControl);

	if ((*serial_).isOpen())
		isSerialOpen_ = true;
	else
	{
		//关闭串口
		serial_->clear();
		serial_->close();
		serial_->deleteLater();

		return;
	}

	//设置串口选项使能
	ui.comboBoxBaudRate->setEnabled(false);
	ui.comboBoxData->setEnabled(false);
	ui.comboBoxPort->setEnabled(false);
	ui.comboBoxStop->setEnabled(false);
	ui.comboBoxCheck->setEnabled(false);

	//设置监视板
	ui.checkBoxCarInfo->setChecked(true);
}

void CarControler::disconnectCar()
{
	if (isSerialOpen_ == false)
		return;
	//关闭串口
	serial_->clear();
	serial_->close();
	serial_->deleteLater();

	//设置串口选项使能
	ui.comboBoxBaudRate->setEnabled(true);
	ui.comboBoxData->setEnabled(true);
	ui.comboBoxPort->setEnabled(true);
	ui.comboBoxStop->setEnabled(true);
	ui.comboBoxCheck->setEnabled(true);

	//设置监视板
	ui.checkBoxCarInfo->setChecked(false);

	isSerialOpen_ = false;
}