/*
*文件说明:用于转化CV::Mat与QImage
*/

#ifndef MATQIMAGECONVERT_H
#define MATQIMAGECONVERT_H

#include <opencv.hpp>
#include <qimage.h>
#include "defines.h"

using namespace std;
using namespace cv;

/*
*函数名:CvImageToQImage
*参数说明:
*		Mat IN src——输入的CV::Mat图像
*		QImage INOUT &Qimage——输出的QImage图像
*返回值:转化是否成功
*函数说明:将输入的Mat图像转化为QImage图像
*/
bool MatToQImage(Mat& IN mCVImage, QImage INOUT &Qimage);

/*
*函数名:QImageToMat
*参数说明:
*		Mat INOUT src——输出的CV::Mat图像
*		QImage IN &Qimage——输入的QImage图像
*返回值:转化是否成功
*函数说明:将输入的QImage图像转化为Mat图像
*/
bool QImageToMat(Mat& INOUT CVImage, QImage IN &Qimage);

#endif