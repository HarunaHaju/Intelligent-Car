#include "matQImageConvert.h"

/*
*函数名:CvImageToQImage
*参数说明:
*		Mat IN src——输入的CV::Mat图像
*		QImage INOUT &Qimage——输出的QImage图像
*返回值:转化是否成功
*函数说明:将输入的Mat图像转化为QImage图像
*/
bool MatToQImage(Mat& IN mCVImage, QImage INOUT &Qimage)
{
	if (mCVImage.empty())
		return false;
	Qimage = QImage(mCVImage.cols, mCVImage.rows, QImage::Format_RGB888);
	if (mCVImage.isContinuous()){
		mCVImage.reshape(1, mCVImage.cols*mCVImage.rows);
	}
	int nrow = mCVImage.rows;
	int ncol = mCVImage.cols;
	int channel = mCVImage.channels();
	uchar* data = (uchar *)mCVImage.ptr<uchar>(0);
	for (int i = 0; i<nrow; i++){
		int r, g, b;
		for (int j = 0; j<ncol; j++){
			r = data[i*ncol*channel + j*channel + 2];
			g = data[i*ncol*channel + j*channel + 1];
			b = data[i*ncol*channel + j*channel + 0];
			Qimage.setPixel(j, i, qRgb(r, g, b));
		}
	}
	return true;
}

/*
*函数名:QImageToMat
*参数说明:
*		Mat INOUT src——输出的CV::Mat图像
*		QImage IN &Qimage——输入的QImage图像
*返回值:转化是否成功
*函数说明:将输入的QImage图像转化为Mat图像
*/
bool QImageToMat(Mat& INOUT CVImage, QImage IN &Qimage)
{
	switch (Qimage.format())
	{
	case QImage::Format_RGB888:
		CVImage = cv::Mat(Qimage.height(), Qimage.width(), CV_8UC3, (void*)Qimage.constBits(), Qimage.bytesPerLine());
		cv::cvtColor(CVImage, CVImage, CV_BGR2RGB);
		break;
	case QImage::Format_Indexed8:
		CVImage = cv::Mat(Qimage.height(), Qimage.width(), CV_8UC1, (void*)Qimage.constBits(), Qimage.bytesPerLine());
		break;
	default:
		break;
	}
	return true;
}