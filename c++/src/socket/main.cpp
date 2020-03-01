#include "CSckFactoryImp1.h"
#include "CSckFactoryImp2.h"

using namespace std;

int SckSendAndRec(CSocketProtocol *sp,unsigned char *in,int inlen,unsigned char *out,int *outlen);
int main()
{
	CSocketProtocol *sp = NULL;
	CSocketProtocol *sp2 = NULL;
	int ret;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;
	strcpy((char*)in,"abdsds");
	inlen = 9;
	sp = new CSckFactoryImp1;
	ret = SckSendAndRec(sp,in,inlen,out,&outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRec() err:%d\n",ret);
		return ret;
	}
	delete sp;

	sp2 = new CSckFactoryImp2;
	ret = SckSendAndRec(sp2,in,inlen,out,&outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRec() err:%d\n",ret);
		return ret;
	}
	delete sp2;
	return 0;
}
int SckSendAndRec(CSocketProtocol *sp,unsigned char *in,int inlen,unsigned char *out,int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketSend(in,inlen);
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketRev(out,outlen);
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketDestory();
	if (ret != 0)
	{
		goto End;
	}

End:
	ret = sp->cltSocketDestory();
	return 0;
}
