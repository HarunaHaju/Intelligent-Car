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
*函数名:removeSmallRegion
*参数说明:
*		Mat IN src——输入的图像
*		Mat& INOUT dst——处理后的结果
*		Mat IN mMap——原图的色彩地图
*		vector<EdgeInfo>& INOUT veInfos——用于记录边界信息的vector
*		double IN dAreaMinRate——满足要求的最小区域比率
*		double IN dAreaMaxRate——满足要求的最大区域比率
*		int IN nCheckMode——检查的方式
*		int IN nNeihborMod——检测邻居的方式,0为4邻域而1为8邻域
*返回值:无
*函数说明:对于输入的图像，进行图像处理，判断小车运行的方向
*注意事项:dAreaMinRate < x < dAreaMaxRate
*/
void removeSmallRegion(Mat& IN src, Mat& INOUT dst,Mat IN mMap,
	vector<EdgeInfo>& INOUT veInfos,
	double IN dAreaMinRate, double IN dAreaMaxRate,int IN nCheckMode, int IN nNeihborMode);

#endif