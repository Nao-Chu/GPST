#pragma once
#include <iostream>
#include "CSocketProtocol.h"
using namespace std;

class CSckFactoryImp1 : public CSocketProtocol
{
public:
	virtual int cltSocketInit();
	virtual int cltSocketSend(unsigned char *buf,int buflen);
	virtual int cltSocketRev(unsigned char *buf,int *buflen);
	virtual int cltSocketDestory();
	CSckFactoryImp1();
	virtual ~CSckFactoryImp1();
private:
	unsigned char *p;
	int len;
};
