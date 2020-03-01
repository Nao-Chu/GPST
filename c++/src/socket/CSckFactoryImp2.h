#pragma once
#include <iostream>
#include "CSocketProtocol.h"
using namespace std;

class CSckFactoryImp2 : public CSocketProtocol
{
public:
	virtual int cltSocketInit();
	virtual int cltSocketSend(unsigned char *buf,int buflen);
	virtual int cltSocketRev(unsigned char *buf,int *buflen);
	virtual int cltSocketDestory();
	CSckFactoryImp2();
	virtual ~CSckFactoryImp2();
private:
	unsigned char *p;
	int len;
};
