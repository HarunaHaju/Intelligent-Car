#include "matQImageConvert.h"

/*
*������:CvImageToQImage
*����˵��:
*		Mat IN src���������CV::Matͼ��
*		QImage INOUT &Qimage���������QImageͼ��
*����ֵ:ת���Ƿ�ɹ�
*����˵��:�������Matͼ��ת��ΪQImageͼ��
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
*������:QImageToMat
*����˵��:
*		Mat INOUT src���������CV::Matͼ��
*		QImage IN &Qimage���������QImageͼ��
*����ֵ:ת���Ƿ�ɹ�
*����˵��:�������QImageͼ��ת��ΪMatͼ��
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