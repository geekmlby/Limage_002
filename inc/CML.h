#ifndef CML_H
#define CML_H

#include "CDIP.h"
#include "math.h"

class CML:public CDIP
{
public:
    CML();
    ~CML();

	int* ExtrFeat();
	void ExtrHOGFeat();
	void ExtrHaarFeat();
	void ExtrLBPFeat(uchar* Matrix_out,
					 uchar* Matrix,
					 int h,
					 int w);
private:

};

#endif
