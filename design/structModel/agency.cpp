/********************************************************************
    > File Name: agency.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 14时46分29秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Subject
{
public:
	virtual void sailbook() = 0;
};

class RealSubjectBook : public Subject
{
public:
	virtual void sailbook()
	{
		cout << "sailbook" << endl;
	}
};

class dangdangProxy : public Subject
{
public:
	virtual void sailbook()
	{
		RealSubjectBook *rsb = new RealSubjectBook;
		dazhe();
		rsb->sailbook();
	}
	void dazhe()
	{
		cout << "dazhe" << endl;
	}
};

int main()
{
	Subject *subject = new dangdangProxy;
	subject->sailbook();
	subject->dazhe();
	return 0;
}
