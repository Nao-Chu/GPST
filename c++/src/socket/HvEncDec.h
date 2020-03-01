#include<iostream>
using namespace std;

#include "CEncDesProtocol.h"

class HvEncDec : public CEncDesProtocol
{
public:
	HvEncDec();
	virtual ~HvEncDec();
	virtual int EncData(unsigned char *plain,int plainlen,unsigned char *cryptdata,int *cryptlen);
	virtual int DecData(unsigned char *cryptdata,int cryptlen,unsigned char *plain,int *plainlen);
};
