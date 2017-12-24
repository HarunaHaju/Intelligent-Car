#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <opencv.hpp>
#include "defines.h"
using namespace std;
using namespace cv;

/*
*������:imageProcess
*����˵��:
*		Mat IN src���������ͼ��
*		Mat& INOUT dst����������ʾ���û���ͼ��
*		vector<Scalar> IN scalars���������ɫ�ʣ�����Ҫ��ĲŻ�����ж�
*����ֵ:ö������CarSignal����������С���Ķ���
*����˵��:���������ͼ�񣬽���ͼ�����ж�С�����еķ���
*/
CarSignal imageProcess(Mat IN src, Mat& INOUT dst, vector<Scalar> IN scalars);

/*
*������:hasRoi
*����˵��:
*		Mat IN src���������ͼ����ͨ��
*		Mat& INOUT dst�������ں��������ͼ�񣬵�ͨ��
*		Mat& INOUT colorMap��������ͼ���ɫ�ʵ�ͼ����ͨ��
*		vector<Scalar> IN scalars���������ɫ�ʣ�����Ҫ��ĲŻ�����ж�
*����ֵ:�Ƿ��и���Ȥ����
*����˵��:�ж�����ͼ���Ƿ��и���Ȥ����
*/
bool hasRoi(Mat IN src, Mat& INOUT dst, Mat& INOUT colorMap, vector<Scalar> IN scalars);

/*
*������:deltaOfScalar
*����˵��:
*		Scalar IN scalar1���������ĳ��RGBֵ
*		Scalar IN scalar2���������ĳ��RGBֵ
*����ֵ:������ɫ��RGB����
*����˵��:����������ɫ��RGB����
*/
int deltaOfScalar(Scalar IN scalar1, Scalar IN scalar2);

/*
*������:judgePosition
*����˵��:
*		Mat IN roi���������roi
*����ֵ:roi��λ����Ϣ��ˮƽ����ֱ��
*����˵��:�ж�roi��λ����Ϣ��ˮƽ����ֱ��
*/
Position judgePosition(Mat IN roi);

/*
*������:judgeCarSignal
*����˵��:
*		Mat IN roi���������roi
*		Position IN position������roi��ˮƽ��ֱ����
*����ֵ:roi��λ����Ϣ��ˮƽ����ֱ��
*����˵��:�ж�roi��λ����Ϣ��ˮƽ����ֱ��
*/
CarSignal judgeCarSignal(Mat IN roi, Position IN position);

#endif