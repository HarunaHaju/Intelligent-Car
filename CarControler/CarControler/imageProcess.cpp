#include "imageProcess.h"
#include "removeRegion.h"

/*
*������:imageProcess
*����˵��:
*		Mat IN src���������ͼ��
*		Mat& INOUT dst����������ʾ���û���ͼ��
*		vector<Scalar> IN scalars���������ɫ�ʣ�����Ҫ��ĲŻ�����ж�
*����ֵ:ö������CarSignal����������С���Ķ���
*����˵��:���������ͼ�񣬽���ͼ�����ж�С�����еķ���
*/
CarSignal imageProcess(Mat IN src, Mat& INOUT dst, vector<Scalar> IN scalars)
{
	Mat mBin(src.size(), CV_8UC1, Scalar(0));
	Mat mColorMap(src.size(), CV_8UC1, Scalar(0));
	if (hasRoi(src, mBin, mColorMap, scalars))
	{
		std::vector<EdgeInfo> veInfos;

		dilate(mBin, mBin, Mat(Size(3, 3), CV_8UC1), Point(-1, -1), 3);//����
		erode(mBin, mBin, Mat(Size(3, 3), CV_8UC1), Point(-1, -1), 3);//��ʴ

		threshold(mBin, mBin, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
		removeSmallRegion(mBin, mBin, mColorMap, veInfos, 0.05, 0.4, 1, 0);

		if (!veInfos.empty())
		{
			//�ҵ����������ͨ��
			int nMaxIndex = 0;
			for (int nIndex = 0; nIndex < veInfos.size(); nIndex++)
			{
				if (veInfos.at(nIndex).getArea()>veInfos.at(nMaxIndex).getArea())
				{
					nMaxIndex = nIndex;
				}
			}

			//ͨ��������ͨ����ԭͼ�ϻ�ȡ��roi
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
		return CAR_DO_NOTHING;//С��������Ӧ
	}
}

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
bool hasRoi(Mat IN src, Mat& INOUT dst, Mat& INOUT colorMap, vector<Scalar> IN scalars)
{
	//ֻ�ᴦ������Ҫ���ͼ��
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

	//����ÿ���㣬������������ɫ�Ĳ���
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

					//Map�ļ�¼��ö������Color��ͬ
					dataOfMap[nIndexOfY*nWidth + nIndexOfX] = i + 1;
					npCount[i]++;
					break;
				}
			}
		}
	}

	//�ж��Ƿ��и���Ȥ����
	for (int i = 0; i < nSizeOfScalar; i++)
	{
		if ((double)npCount[i] / (double)nArea >= 0.05)
		{
			hasRoi = true;
			break;
		}
	}

	//������Ҫ��ĵ�ӳ�䵽ĳһ��ͼ��
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
*������:deltaOfScalar
*����˵��:
*		Scalar IN scalar1���������ĳ��RGBֵ
*		Scalar IN scalar2���������ĳ��RGBֵ
*����ֵ:������ɫ��RGB����
*����˵��:����������ɫ��RGB����
*/
int deltaOfScalar(Scalar IN scalar1, Scalar IN scalar2)
{
	int b = abs(scalar1.val[0] - scalar2.val[0]);
	int g = abs(scalar1.val[1] - scalar2.val[1]);
	int r = abs(scalar1.val[2] - scalar2.val[2]);
	return b + g + r;
}

/*
*������:judgePosition
*����˵��:
*		Mat IN roi���������roi
*����ֵ:roi��λ����Ϣ��ˮƽ����ֱ��
*����˵��:�ж�roi��λ����Ϣ��ˮƽ����ֱ��
*/
Position judgePosition(Mat IN roi)
{
	double dRateOfHW = (double)roi.cols / (double)roi.rows;
	//ͨ�������ȷ������ˮƽ����ֱ��
	if (dRateOfHW > 1.4)
	{
		//ˮƽ
		return POSITION_HORIZONTAL;
	}
	else if (dRateOfHW < 0.7)
	{
		//��ֱ
		return POSITION_VERTICAL;
	}
	else
	{
		//���������Ϊ�ɼ�ͼ�񲻼�
		return POSITION_NOT_DEFINED;
	}
}

/*
*������:judgeCarSignal
*����˵��:
*		Mat IN roi���������roi����ͨ��
*		Position IN position������roi��ˮƽ��ֱ����
*����ֵ:С���Ķ���
*����˵��:ͨ��roi�ж�С���Ķ���
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