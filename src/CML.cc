#include "CML.h"

CML::CML()
{

}

CML::~CML()
{

}

int* CML::ExtrFeat()
{

}

void CML::ExtrHOGFeat()
{

}

void CML::ExtrHaarFeat()
{

}

void CML::ExtrLBPFeat(uchar* Matrix_out,
					  uchar* Matrix,
					  int h,
					  int w)
{
	int i,j,k,l;
	uchar cenV;
	uchar* puc_flippedMat = new uchar[MAXHEIGHT * MAXWIDTH];
	uchar* aroundArr = new uchar[9];
	uchar* tmpArr = new uchar[9];

	FlipMat(puc_flippedMat,
			Matrix,
			4,
			4,
			3,
			3);
	/*WriteTxt("/home/wangli/01_Limage/flipped.txt",
			 puc_flippedMat,
			 6,
			 6);*/
	for(i = 0;i < h;i++)
	{
		for(j = 0;j < w;j++)
		{
			cenV = puc_flippedMat[(i + 1) * (w + 2) + (j + 1)];   //获取中心数据
			memset(aroundArr,0,8);
			for(k = i;k <= i + 2;k++)
			{
				for(l = j;l <= j + 2;l++)
				{
					tmpArr[(k - i) * 3 + (l - j)] = puc_flippedMat[k * (w + 2) + l];
					if(((i + 1) == k) && ((j + 1) == l))
					{
						//break;
					}
					else
					{
						//aroundArr[(k - i) * 3 + (l - j)] = puc_flippedMat[k * (w + 2) + l];
						if(puc_flippedMat[k * (w + 2) + l] >= cenV)
						{
							aroundArr[(k - i) * 3 + (l - j)] = 1;
						}
						else
						{
							aroundArr[(k - i) * 3 + (l - j)] = 0;
						}
					}
				}
			}

			WriteTxt("/home/wangli/01_Limage/tmpArr.txt",
			 		 tmpArr,
			 		 3,
			 		 3);
			WriteTxt("/home/wangli/01_Limage/aroundArr.txt",
			 		 aroundArr,
			 		 3,
			 		 3);

			Matrix_out[i * w + j] = aroundArr[0] * 1 + aroundArr[1] * 2 + aroundArr[2] * 4 +
									aroundArr[3] * 128 + aroundArr[5] * 8 + aroundArr[6] * 64 +
									aroundArr[7] * 32 + aroundArr[8] * 16;
		}
	}

	WriteTxt("/home/wangli/01_Limage/Matrix_out.txt",
			 Matrix_out,
			 h,
			 w);

	delete puc_flippedMat;
	delete aroundArr;
	delete tmpArr;
	puc_flippedMat = NULL;
	aroundArr = NULL;
	tmpArr = NULL;
}






















