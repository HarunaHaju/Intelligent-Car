#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <opencv.hpp>
#include "defines.h"
using namespace std;
using namespace cv;

/*
*函数名:imageProcess
*参数说明:
*		Mat IN src——输入的图像
*		Mat& INOUT dst——用于显示给用户的图像
*		vector<Scalar> IN scalars——输入的色彩，满足要求的才会进行判断
*返回值:枚举类型CarSignal，用于描述小车的动作
*函数说明:对于输入的图像，进行图像处理，判断小车运行的方向
*/
CarSignal imageProcess(Mat IN src, Mat& INOUT dst, vector<Scalar> IN scalars);

/*
*函数名:hasRoi
*参数说明:
*		Mat IN src——输入的图像，三通道
*		Mat& INOUT dst——用于后续处理的图像，单通道
*		Mat& INOUT colorMap——输入图像的色彩地图，单通道
*		vector<Scalar> IN scalars——输入的色彩，满足要求的才会进行判断
*返回值:是否有感兴趣区域
*函数说明:判断输入图像是否有感兴趣区域
*/
bool hasRoi(Mat IN src, Mat& INOUT dst, Mat& INOUT colorMap, vector<Scalar> IN scalars);

/*
*函数名:deltaOfScalar
*参数说明:
*		Scalar IN scalar1——输入的某个RGB值
*		Scalar IN scalar2——输入的某个RGB值
*返回值:两种颜色的RGB距离
*函数说明:计算两种颜色的RGB距离
*/
int deltaOfScalar(Scalar IN scalar1, Scalar IN scalar2);

/*
*函数名:judgePosition
*参数说明:
*		Mat IN roi——输入的roi
*返回值:roi的位姿信息（水平，垂直）
*函数说明:判断roi的位姿信息（水平，垂直）
*/
Position judgePosition(Mat IN roi);

/*
*函数名:judgeCarSignal
*参数说明:
*		Mat IN roi——输入的roi
*		Position IN position——此roi的水平竖直方向
*返回值:roi的位姿信息（水平，垂直）
*函数说明:判断roi的位姿信息（水平，垂直）
*/
CarSignal judgeCarSignal(Mat IN roi, Position IN position);

#endif