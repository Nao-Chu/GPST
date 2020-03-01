#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class CSocketProtocol
{
public:
	CSocketProtocol();
	virtual ~CSocketProtocol();
	virtual int cltSocketInit() = 0;
	virtual int cltSocketSend(unsigned char *buf,int buflen) = 0;
	virtual int cltSocketRev(unsigned char *buf,int *buflen) = 0;
	virtual int cltSocketDestory() = 0;
};
