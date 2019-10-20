/*CCH,控制硬件类。
 包含摄像头的相关操作和对从摄像头读取的数据的处理算法。
*/

#include "CDIP.h"

#ifndef CCH_H
#define CCH_H

class CCH : public CDIP
{
public:
	CCH();
	CCH(int n);
	~CCH();
	void OpenCamera();
	void ShowVideo();
public:
	VideoCapture cap;
	Mat frame;
private:
	int nCam;
};

#endif
