#include "removeRegion.h"

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
void removeSmallRegion(Mat& IN src, Mat& INOUT dst, Mat IN mMap,
	vector<EdgeInfo>& INOUT veInfos,
	double IN dAreaMinRate, double IN dAreaMaxRate, int IN nCheckMode, int IN nNeihborMode)
{
	int RemoveCount = 0;//记录除去的个数

	//记录每个像素点检验状态的标签
	//0代表未检查，1代表正在检查,2代表检查不合格（需要反转颜色），3代表检查合格或不需检查
	cv::Mat mPointLabel = cv::Mat::zeros(src.size(), CV_8UC1);

	uchar* pucDataOfLabel = mPointLabel.data;
	uchar* pucDataOfSrc = src.data;
	uchar* pucDataOfDst = dst.data;
	int nHeight = src.rows;
	int nWidth = src.cols;
	int nArea = nWidth*nHeight;

	//对Label进行初始化
	if (nCheckMode == 0)
	{
		for (int nIndexOfY = 0; nIndexOfY < nHeight; nIndexOfY++)
		{
			for (int nIndexOfX = 0; nIndexOfX < nWidth; nIndexOfX++)
			{
				if (pucDataOfSrc[nIndexOfY*nWidth + nIndexOfX] >= 220)
				{
					pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] = 3;
				}
			}
		}
	}
	else
	{
		for (int nIndexOfY = 0; nIndexOfY < nHeight; nIndexOfY++)
		{
			for (int nIndexOfX = 0; nIndexOfX < nWidth; nIndexOfX++)
			{
				if (pucDataOfSrc[nIndexOfY*nWidth + nIndexOfX] <= 50)
				{
					pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] = 3;
				}
			}
		}
	}

	//记录邻域点位置
	std::vector<cv::Point2i>vptNeihborPos;
	vptNeihborPos.push_back(cv::Point2i(-1, 0));
	vptNeihborPos.push_back(cv::Point2i(1, 0));
	vptNeihborPos.push_back(cv::Point2i(0, -1));
	vptNeihborPos.push_back(cv::Point2i(0, 1));
	if (nNeihborMode == 1)
	{
		vptNeihborPos.push_back(cv::Point2i(-1, -1));
		vptNeihborPos.push_back(cv::Point2i(-1, 1));
		vptNeihborPos.push_back(cv::Point2i(1, -1));
		vptNeihborPos.push_back(cv::Point2i(1, 1));
	}


	int nNeihborCount = 4 + 4 * nNeihborMode;
	int nCurrX = 0, nCurrY = 0;
	//开始检测
	for (int nIndexOfY = 0; nIndexOfY < nHeight; nIndexOfY++)
	{
		for (int nIndexOfX = 0; nIndexOfX < nWidth; nIndexOfX++)
		{
			if (pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] == 0)
			{
				//开始该点处的检查
				std::vector<cv::Point2i> vptGrowBuffer;//堆栈，用于存储生长点  
				vptGrowBuffer.push_back(cv::Point2i(nIndexOfX, nIndexOfY));
				pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] = 1;
				int nCheckResult = 0;//用于判断结果（是否超出大小），0为未超出，1为超出
				for (int nIndexOfBuffer = 0; nIndexOfBuffer < vptGrowBuffer.size(); nIndexOfBuffer++)
				{
					for (int nIndexOfNeihbor = 0; nIndexOfNeihbor < nNeihborCount; nIndexOfNeihbor++)//检查邻域点
					{
						nCurrX = vptGrowBuffer.at(nIndexOfBuffer).x
							+ vptNeihborPos.at(nIndexOfNeihbor).x;
						nCurrY = vptGrowBuffer.at(nIndexOfBuffer).y
							+ vptNeihborPos.at(nIndexOfNeihbor).y;

						//防止越界
						if (nCurrX >= 0 && nCurrX < nWidth&&nCurrY >= 0
							&& nCurrY < nHeight)
						{
							if (pucDataOfLabel[nCurrY*nWidth + nCurrX] == 0)
							{
								//邻域点加入buffer
								vptGrowBuffer.push_back(cv::Point2i(nCurrX, nCurrY));

								//更新邻域点的检查标签，避免重复检查
								pucDataOfLabel[nCurrY*nWidth + nCurrX] = 1;
							}
						}
					}//for nIndexOfBuffer end
				}//for nIndexOfNeihbor end

				double dRate = (double)vptGrowBuffer.size() / (double)nArea;

				//判断结果（是否超出限定的大小），1为未超出，2为超出 
				if (dRate>dAreaMinRate && dRate<dAreaMaxRate)
				{
					nCheckResult = 2;
				}
				else
				{
					nCheckResult = 1;
					RemoveCount++;
				}

				int nMinX = vptGrowBuffer.at(0).x;
				int nMaxX = vptGrowBuffer.at(0).x;
				int nMinY = vptGrowBuffer.at(0).y;
				int nMaxY = vptGrowBuffer.at(0).y;
				int nColor = 0;

				//更新Label记录,并寻找最大最小x值与y值
				if (nCheckResult == 1)
				{
					for (int nIndexOfBuffer = 0; nIndexOfBuffer < vptGrowBuffer.size(); nIndexOfBuffer++)
					{
						nCurrX = vptGrowBuffer.at(nIndexOfBuffer).x;
						nCurrY = vptGrowBuffer.at(nIndexOfBuffer).y;
						pucDataOfLabel[nCurrY*nWidth + nCurrX] += nCheckResult;
					}
				}
				else if(nCheckResult == 2)
				{
					nColor = mMap.data[vptGrowBuffer.at(5).y*nWidth + vptGrowBuffer.at(5).x];
					for (int nIndexOfBuffer = 0; nIndexOfBuffer < vptGrowBuffer.size();
						nIndexOfBuffer++)
					{
						nCurrX = vptGrowBuffer.at(nIndexOfBuffer).x;
						nCurrY = vptGrowBuffer.at(nIndexOfBuffer).y;
						if (nCurrX < nMinX)
							nMinX = nCurrX;
						if (nCurrX > nMaxX)
							nMaxX = nCurrX;
						if (nCurrY < nMinY)
							nMinY = nCurrY;
						if (nCurrY > nMaxY)
							nMaxY = nCurrY;
						pucDataOfLabel[nCurrY*nWidth + nCurrX] += nCheckResult;
					}
					EdgeInfo info(nMinX, nMaxX, nMinY, nMaxY, nColor);
					veInfos.push_back(info);
				}
			}//check end
		}//for nIndexOfX end
	}//for nIndexOfY end

	nCheckMode = 255 * (1 - nCheckMode);
	//开始反转面积过小的区域
	for (int nIndexOfY = 0; nIndexOfY < nHeight; nIndexOfY++)
	{
		for (int nIndexOfX = 0; nIndexOfX < nWidth; nIndexOfX++)
		{
			if (pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] == 2)
			{
				pucDataOfDst[nIndexOfY*nWidth + nIndexOfX] = nCheckMode;
			}
			else if (pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] == 3)
			{
				pucDataOfDst[nIndexOfY*nWidth + nIndexOfX]
					= pucDataOfSrc[nIndexOfY*nWidth + nIndexOfX];
			}
		}
	}
}

EdgeInfo& EdgeInfo::operator=(EdgeInfo info)
{
	this->nMaxX_ = info.getMaxX();
	this->nMinX_ = info.getMinX();
	this->nMaxY_ = info.getMaxY();
	this->nMinY_ = info.getMinY();
	this->nArea_ = info.getArea();
	return *this;
}
EdgeInfo::~EdgeInfo()
{

}
EdgeInfo::EdgeInfo()
{
	nMaxX_ = 0;
	nMinX_ = 0;
	nMaxY_ = 0;
	nMinY_ = 0;
	nArea_ = 0;
	nColor_ = 0;
}
EdgeInfo::EdgeInfo(int nMinX, int nMaxX, int nMinY, int nMaxY,int nColor)
{
	nMinX_ = nMinX;
	nMaxX_ = nMaxX;
	nMinY_ = nMinY;
	nMaxY_ = nMaxY;
	nColor_ = nColor;
	nArea_ = (nMaxX_ - nMinX_) * (nMaxY_ - nMinY_);
}
int EdgeInfo::getMaxX()
{
	return nMaxX_;
}
int EdgeInfo::getMinX()
{
	return nMinX_;
}
int EdgeInfo::getMaxY()
{
	return nMaxY_;
}
int EdgeInfo::getMinY()
{
	return nMinY_;
}
int EdgeInfo::getArea()
{
	return nArea_;
}
int EdgeInfo::getColor()
{
	return nColor_;
}

void EdgeInfo::setMaxX(int nX)
{
	nMaxX_ = nX;
}
void EdgeInfo::setMinX(int nX)
{
	nMinX_ = nX;
}
void EdgeInfo::setMaxY(int nY)
{
	nMaxY_ = nY;
}
void EdgeInfo::setMinY(int nY)
{
	nMinY_ = nY;
}
void EdgeInfo::setArea(int nArea)
{
	nArea_ = nArea;
}
void EdgeInfo::setColor(int nColor)
{
	nColor_ = nColor;
}