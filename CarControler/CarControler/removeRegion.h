#ifndef REMOVEREGION_H
#define REMOVEREGION_H

#include <opencv.hpp>
#include "defines.h"

using namespace cv;
using namespace std;

class EdgeInfo
{
public:
	EdgeInfo();
	EdgeInfo(int nMinX, int nMaxX, int nMinY, int nMaxY,int nColor);
	~EdgeInfo();
	EdgeInfo& operator= (EdgeInfo info);

	int getMaxX();
	void setMaxX(int nX);

	int getMinX();
	void setMinX(int nX);

	int getMaxY();
	void setMaxY(int nY);

	int getMinY();
	void setMinY(int nY);

	int getArea();
	void setArea(int nArea);

	int getColor();
	void setColor(int nColor);
private:
	int nMaxX_;
	int nMinX_;
	int nMaxY_;
	int nMinY_;
	int nArea_;
	int nColor_;
};

/*
*������:removeSmallRegion
*����˵��:
*		Mat IN src���������ͼ��
*		Mat& INOUT dst���������Ľ��
*		Mat IN mMap����ԭͼ��ɫ�ʵ�ͼ
*		vector<EdgeInfo>& INOUT veInfos�������ڼ�¼�߽���Ϣ��vector
*		double IN dAreaMinRate��������Ҫ�����С�������
*		double IN dAreaMaxRate��������Ҫ�������������
*		int IN nCheckMode�������ķ�ʽ
*		int IN nNeihborMod��������ھӵķ�ʽ,0Ϊ4�����1Ϊ8����
*����ֵ:��
*����˵��:���������ͼ�񣬽���ͼ�����ж�С�����еķ���
*ע������:dAreaMinRate < x < dAreaMaxRate
*/
void removeSmallRegion(Mat& IN src, Mat& INOUT dst,Mat IN mMap,
	vector<EdgeInfo>& INOUT veInfos,
	double IN dAreaMinRate, double IN dAreaMaxRate,int IN nCheckMode, int IN nNeihborMode);

#endif