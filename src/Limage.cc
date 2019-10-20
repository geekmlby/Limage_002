#include <stdio.h>
#include <iostream>

#include "CDIP.h"
#include "CML.h"

using namespace std;

int main(int argc,char* argv[])
{
	CML limage;
	char path[PATHSIZE] = "/home/wangli/01_Limage/img/testArray4_4.bmp";
    /*cout << "Please input path:" << endl;     //注：手动输入图像路径。
    cin.get(path,100);*/ 	
	uchar* puc_Mat = new uchar[MAXHEIGHT * MAXWIDTH]; 
	uchar* puc_Mat2 = new uchar[MAXHEIGHT * MAXWIDTH];    

	limage.ReadImage(path);
	limage.ShowImage();
	limage.GetGrayImage(puc_Mat);
	limage.WriteTxt("/home/wangli/01_Limage/testArray4_4.txt",
					puc_Mat,
					4,
					4);
	limage.ExtrLBPFeat(puc_Mat2,
					   puc_Mat,
					   4,
					   4);
	limage.WriteTxt("/home/wangli/01_Limage/LBP.txt",
					puc_Mat2,
					4,
					4);
	
	delete puc_Mat;
	delete puc_Mat2;
	puc_Mat = NULL;
	puc_Mat2 = NULL;

  	return 0;
}


























