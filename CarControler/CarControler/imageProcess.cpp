#include "imageProcess.h"
#include "removeRegion.h"

/*
*函数名:imageProcess
*参数说明:
*		Mat IN src——输入的图像
*		Mat& INOUT dst——用于显示给用户的图像
*		vector<Scalar> IN scalars——输入的色彩，满足要求的才会进行判断
*返回值:枚举类型CarSignal，用于描述小车的动作
*函数说明:对于输入的图像，进行图像处理，判断小车运行的方向
*/
CarSignal imageProcess(Mat IN src, Mat& INOUT dst, vector<Scalar> IN scalars)
{
	Mat mBin(src.size(), CV_8UC1, Scalar(0));
	Mat mColorMap(src.size(), CV_8UC1, Scalar(0));
	if (hasRoi(src, mBin, mColorMap, scalars))
	{
		std::vector<EdgeInfo> veInfos;

		dilate(mBin, mBin, Mat(Size(3, 3), CV_8UC1), Point(-1, -1), 3);//膨胀
		erode(mBin, mBin, Mat(Size(3, 3), CV_8UC1), Point(-1, -1), 3);//腐蚀

		threshold(mBin, mBin, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
		removeSmallRegion(mBin, mBin, mColorMap, veInfos, 0.05, 0.4, 1, 0);

		if (!veInfos.empty())
		{
			//找到面积最大的连通域
			int nMaxIndex = 0;
			for (int nIndex = 0; nIndex < veInfos.size(); nIndex++)
			{
				if (veInfos.at(nIndex).getArea()>veInfos.at(nMaxIndex).getArea())
				{
					nMaxIndex = nIndex;
				}
			}

			//通过最大的连通域在原图上获取到roi
			Rect rect(Point(veInfos.at(nMaxIndex).getMinX(), veInfos.at(nMaxIndex).getMinY())
				, Point(veInfos.at(nMaxIndex).getMaxX(), veInfos.at(nMaxIndex).getMaxY()));
			Mat mRoi = src(rect).clone();
			Mat mRoiBin = mBin(rect).clone();
			Mat mMapOfROI = mColorMap(rect).clone();
			//dst = mRoiBin.clone();

			switch (veInfos.at(nMaxIndex).getColor())
			{
			case COLOR_RED:
				rectangle(dst, rect, Scalar(0, 0, 255), 5);
				if (RED_ENABLE)
				{
					switch (judgePosition(mRoi))
					{
					case POSITION_HORIZONTAL:
						switch (judgeCarSignal(mRoiBin, POSITION_HORIZONTAL))
						{
						case CAR_MOVE_LEFT:
							putText(dst, "left", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_LEFT;
						case CAR_MOVE_RIGHT:
							putText(dst, "right", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_RIGHT;
						case CAR_DO_NOTHING:
						default:
							return CAR_DO_NOTHING;
						}
					case POSITION_VERTICAL:
						switch (judgeCarSignal(mRoiBin, POSITION_VERTICAL))
						{
						case CAR_MOVE_BACK:
							putText(dst, "back", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_BACK;
						case CAR_MOVE_FORWARD:
							putText(dst, "forward", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_FORWARD;
						case CAR_DO_NOTHING:
						default:
							return CAR_DO_NOTHING;
						}
					default:
						return CAR_DO_NOTHING;
					}
				}
				else
				{
					return CAR_DO_NOTHING;
				}
				break;
			case COLOR_BLUE:
				rectangle(dst, rect, Scalar(255, 255, 0), 5);
				if (BLUE_ENABLE)
				{
					switch (judgePosition(mRoi))
					{
					case POSITION_HORIZONTAL:
						switch (judgeCarSignal(mRoiBin, POSITION_HORIZONTAL))
						{
						case CAR_MOVE_LEFT:
							putText(dst, "left", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_LEFT;
						case CAR_MOVE_RIGHT:
							putText(dst, "right", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_RIGHT;
						case CAR_DO_NOTHING:
						default:
							return CAR_DO_NOTHING;
						}
					case POSITION_VERTICAL:
						switch (judgeCarSignal(mRoiBin, POSITION_VERTICAL))
						{
						case CAR_MOVE_BACK:
							putText(dst, "back", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_BACK;
						case CAR_MOVE_FORWARD:
							putText(dst, "forward", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_FORWARD;
						case CAR_DO_NOTHING:
						default:
							return CAR_DO_NOTHING;
						}
					default:
						return CAR_DO_NOTHING;
					}
				}
				else
				{
					return CAR_DO_NOTHING;
				}
				break;
			case COLOR_GREEN:
				rectangle(dst, rect, Scalar(0, 255, 0), 5);
				if (GREEN_ENABLE)
				{
					switch (judgePosition(mRoi))
					{
					case POSITION_HORIZONTAL:
						switch (judgeCarSignal(mRoiBin, POSITION_HORIZONTAL))
						{
						case CAR_MOVE_LEFT:
							putText(dst, "left", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_LEFT;
						case CAR_MOVE_RIGHT:
							putText(dst, "right", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_RIGHT;
						case CAR_DO_NOTHING:
						default:
							return CAR_DO_NOTHING;
						}
					case POSITION_VERTICAL:
						switch (judgeCarSignal(mRoiBin, POSITION_VERTICAL))
						{
						case CAR_MOVE_BACK:
							putText(dst, "back", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_BACK;
						case CAR_MOVE_FORWARD:
							putText(dst, "forward", Point(20, 20),
								CV_FONT_BLACK, 1, Scalar(0, 0, 255));
							return CAR_MOVE_FORWARD;
						case CAR_DO_NOTHING:
						default:
							return CAR_DO_NOTHING;
						}
					default:
						return CAR_DO_NOTHING;
					}
				}
				else
				{
					return CAR_DO_NOTHING;
				}
				break;
			default:
				return CAR_DO_NOTHING;
			}
		}
	}
	else
	{
		return CAR_DO_NOTHING;//小车不作反应
	}
}

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
bool hasRoi(Mat IN src, Mat& INOUT dst, Mat& INOUT colorMap, vector<Scalar> IN scalars)
{
	//只会处理满足要求的图像
	if (src.type() != CV_8UC3 || dst.size() != src.size() || dst.type() != CV_8UC1)
		return false;
	bool hasRoi = false;

	
	int nWidth = src.cols;
	int nHeight = src.rows;
	uchar* dataOfSrc = src.data;
	uchar* dataOfDst = dst.data;
	uchar* dataOfMap = colorMap.data;
	int nSizeOfScalar = scalars.size();
	int nArea = nWidth*nHeight;
	vector<Point> points;

	int *npCount = new int[nSizeOfScalar];
	memset(npCount, 0, sizeof(int)*nSizeOfScalar);

	//遍历每个点，计算与输入颜色的差异
	for (int nIndexOfY = 0; nIndexOfY < nHeight; nIndexOfY++)
	{
		for (int nIndexOfX = 0; nIndexOfX < nWidth; nIndexOfX++)
		{
			int b = dataOfSrc[nIndexOfY*nWidth * 3 + nIndexOfX * 3 + 0];
			int g = dataOfSrc[nIndexOfY*nWidth * 3 + nIndexOfX * 3 + 1];
			int r = dataOfSrc[nIndexOfY*nWidth * 3 + nIndexOfX * 3 + 2];
			Scalar myScalar(b, g, r);
			for (int i = 0; i < nSizeOfScalar; i++)
			{
				int nDelta = deltaOfScalar(myScalar, scalars[i]);
				if (nDelta <= 220)
				{
					points.push_back(Point(nIndexOfX, nIndexOfY));

					//Map的记录与枚举类型Color相同
					dataOfMap[nIndexOfY*nWidth + nIndexOfX] = i + 1;
					npCount[i]++;
					break;
				}
			}
		}
	}

	//判断是否有感兴趣区域
	for (int i = 0; i < nSizeOfScalar; i++)
	{
		if ((double)npCount[i] / (double)nArea >= 0.05)
		{
			hasRoi = true;
			break;
		}
	}

	//将满足要求的点映射到某一个图上
	if (hasRoi)
	{
		for (const auto point : points)
		{
			dataOfDst[point.y*nWidth + point.x] = 255;
		}
	}
	delete[] npCount;
	return hasRoi;
}

/*
*函数名:deltaOfScalar
*参数说明:
*		Scalar IN scalar1——输入的某个RGB值
*		Scalar IN scalar2——输入的某个RGB值
*返回值:两种颜色的RGB距离
*函数说明:计算两种颜色的RGB距离
*/
int deltaOfScalar(Scalar IN scalar1, Scalar IN scalar2)
{
	int b = abs(scalar1.val[0] - scalar2.val[0]);
	int g = abs(scalar1.val[1] - scalar2.val[1]);
	int r = abs(scalar1.val[2] - scalar2.val[2]);
	return b + g + r;
}

/*
*函数名:judgePosition
*参数说明:
*		Mat IN roi——输入的roi
*返回值:roi的位姿信息（水平，垂直）
*函数说明:判断roi的位姿信息（水平，垂直）
*/
Position judgePosition(Mat IN roi)
{
	double dRateOfHW = (double)roi.cols / (double)roi.rows;
	//通过长宽比确定朝向（水平，竖直）
	if (dRateOfHW > 1.4)
	{
		//水平
		return POSITION_HORIZONTAL;
	}
	else if (dRateOfHW < 0.7)
	{
		//竖直
		return POSITION_VERTICAL;
	}
	else
	{
		//其他情况认为采集图像不佳
		return POSITION_NOT_DEFINED;
	}
}

/*
*函数名:judgeCarSignal
*参数说明:
*		Mat IN roi——输入的roi，单通道
*		Position IN position——此roi的水平竖直方向
*返回值:小车的动作
*函数说明:通过roi判断小车的动作
*/
CarSignal judgeCarSignal(Mat IN roi, Position IN position)
{
	int nWidth = roi.cols;
	int nHeight = roi.rows;

	Mat mRoiBin = roi.clone();
	Mat mVer;

	vector<int> vnTempHorizontal(mRoiBin.cols);
	vector<int> vnTempVertical(mRoiBin.rows);
	vector<int> vnAbs;
	vector<int> vnResult;
	float* iptr;
	int nIndex = 0;
	switch (position)
	{
	case POSITION_VERTICAL:
		mRoiBin.convertTo(mRoiBin, CV_32FC1);
		reduce(mRoiBin, mVer, 1, CV_REDUCE_SUM);
		iptr = ((float*)mVer.data);
		for (int i = 0; i < mVer.rows - 1; i++, iptr++)
		{
			vnTempVertical[i] = *(iptr + 1) - *iptr;
			vnAbs.push_back(abs(vnTempVertical[i]));
		}
		for (int i = 0; i < vnAbs.size(); i++)
		{
			if (vnAbs[i] > vnAbs[nIndex])
			{
				nIndex = i;
			}
		}
		if (vnTempVertical[nIndex] < 0)
		{
			return CAR_MOVE_FORWARD;
		}
		else
		{
			return CAR_MOVE_BACK;
		}
		
	case POSITION_HORIZONTAL:
		mRoiBin.convertTo(mRoiBin, CV_32FC1);
		reduce(mRoiBin, mVer, 0, CV_REDUCE_SUM);
		iptr = ((float*)mVer.data);
		for (int i = 0; i < mVer.cols - 1; i++, iptr++)
		{
			vnTempHorizontal[i] = *(iptr + 1) - *iptr;
			vnAbs.push_back(abs(vnTempHorizontal[i]));
		}
		for (int i = 0; i < vnAbs.size(); i++)
		{
			if (vnAbs[i]>vnAbs[nIndex])
			{
				nIndex = i;
			}
		}
		if (vnTempHorizontal[nIndex] < 0)
		{
			return CAR_MOVE_LEFT;
		}
		else
		{
			return CAR_MOVE_RIGHT;
		}
	case POSITION_NOT_DEFINED:
	default:
		return CAR_DO_NOTHING;
	}
}