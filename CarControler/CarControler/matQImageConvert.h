/*
*�ļ�˵��:����ת��CV::Mat��QImage
*/

#ifndef MATQIMAGECONVERT_H
#define MATQIMAGECONVERT_H

#include <opencv.hpp>
#include <qimage.h>
#include "defines.h"

using namespace std;
using namespace cv;

/*
*������:CvImageToQImage
*����˵��:
*		Mat IN src���������CV::Matͼ��
*		QImage INOUT &Qimage���������QImageͼ��
*����ֵ:ת���Ƿ�ɹ�
*����˵��:�������Matͼ��ת��ΪQImageͼ��
*/
bool MatToQImage(Mat& IN mCVImage, QImage INOUT &Qimage);

/*
*������:QImageToMat
*����˵��:
*		Mat INOUT src���������CV::Matͼ��
*		QImage IN &Qimage���������QImageͼ��
*����ֵ:ת���Ƿ�ɹ�
*����˵��:�������QImageͼ��ת��ΪMatͼ��
*/
bool QImageToMat(Mat& INOUT CVImage, QImage IN &Qimage);

#endif