#include "CCH.h"

CCH::CCH()
{

}

CCH::CCH(int n)
{
	nCam = n;
}

CCH::~CCH()
{

}

void CCH::OpenCamera()
{
	cap.open(nCam);
}

void CCH::ShowVideo()
{
	if(!cap.isOpened())
	{
		cout << "Cannot open a camera or file!" << endl;
		return;
	}
	else
	{
		cout << "Opened a camera!" << endl;
	}
	bool stop = false;
	IplImage* src;
	IplImage temp;
	while(!stop)
	{
		cap >> frame;
		imshow("Video",frame);
		temp = IplImage(frame);
		src = &temp;
		/*cout << src->nChannels << endl;
		cout << src->depth << endl;
		ShowImage("Video",
				  (uchar*)(src -> imageData),
				  imgH,
				  imgW,
				  8,
				  3);*/

		if(waitKey(13) >= 0)   //等待按下回车键。
			break;
	}
}
























