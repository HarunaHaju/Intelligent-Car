#include "removeRegion.h"

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
void removeSmallRegion(Mat& IN src, Mat& INOUT dst, Mat IN mMap,
	vector<EdgeInfo>& INOUT veInfos,
	double IN dAreaMinRate, double IN dAreaMaxRate, int IN nCheckMode, int IN nNeihborMode)
{
	int RemoveCount = 0;//��¼��ȥ�ĸ���

	//��¼ÿ�����ص����״̬�ı�ǩ
	//0����δ��飬1�������ڼ��,2�����鲻�ϸ���Ҫ��ת��ɫ����3������ϸ������
	cv::Mat mPointLabel = cv::Mat::zeros(src.size(), CV_8UC1);

	uchar* pucDataOfLabel = mPointLabel.data;
	uchar* pucDataOfSrc = src.data;
	uchar* pucDataOfDst = dst.data;
	int nHeight = src.rows;
	int nWidth = src.cols;
	int nArea = nWidth*nHeight;

	//��Label���г�ʼ��
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

	//��¼�����λ��
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
	//��ʼ���
	for (int nIndexOfY = 0; nIndexOfY < nHeight; nIndexOfY++)
	{
		for (int nIndexOfX = 0; nIndexOfX < nWidth; nIndexOfX++)
		{
			if (pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] == 0)
			{
				//��ʼ�õ㴦�ļ��
				std::vector<cv::Point2i> vptGrowBuffer;//��ջ�����ڴ洢������  
				vptGrowBuffer.push_back(cv::Point2i(nIndexOfX, nIndexOfY));
				pucDataOfLabel[nIndexOfY*nWidth + nIndexOfX] = 1;
				int nCheckResult = 0;//�����жϽ�����Ƿ񳬳���С����0Ϊδ������1Ϊ����
				for (int nIndexOfBuffer = 0; nIndexOfBuffer < vptGrowBuffer.size(); nIndexOfBuffer++)
				{
					for (int nIndexOfNeihbor = 0; nIndexOfNeihbor < nNeihborCount; nIndexOfNeihbor++)//��������
					{
						nCurrX = vptGrowBuffer.at(nIndexOfBuffer).x
							+ vptNeihborPos.at(nIndexOfNeihbor).x;
						nCurrY = vptGrowBuffer.at(nIndexOfBuffer).y
							+ vptNeihborPos.at(nIndexOfNeihbor).y;

						//��ֹԽ��
						if (nCurrX >= 0 && nCurrX < nWidth&&nCurrY >= 0
							&& nCurrY < nHeight)
						{
							if (pucDataOfLabel[nCurrY*nWidth + nCurrX] == 0)
							{
								//��������buffer
								vptGrowBuffer.push_back(cv::Point2i(nCurrX, nCurrY));

								//���������ļ���ǩ�������ظ����
								pucDataOfLabel[nCurrY*nWidth + nCurrX] = 1;
							}
						}
					}//for nIndexOfBuffer end
				}//for nIndexOfNeihbor end

				double dRate = (double)vptGrowBuffer.size() / (double)nArea;

				//�жϽ�����Ƿ񳬳��޶��Ĵ�С����1Ϊδ������2Ϊ���� 
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

				//����Label��¼,��Ѱ�������Сxֵ��yֵ
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
	//��ʼ��ת�����С������
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