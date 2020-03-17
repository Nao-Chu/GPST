/********************************************************************
    > File Name: appearance.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 18时39分42秒
 *******************************************************************/

#include<iostream>
using namespace std;

class SubSystemA
{
public:
	void doThing()
	{
		cout << "do A" << endl;
	}

};

class SubSystemB
{
public:
	void doThing()
	{
		cout << "do B" << endl;
	}

};

class SubSystemC
{
public:
	void doThing()
	{
		cout << "do C" << endl;
	}

};

class Facade
{
public:
	Facade()
	{
		sysA = new SubSystemA;
		sysB = new SubSystemB;
		sysC = new SubSystemC;
	}
	void doThing()
	{
		sysA->doThing();
		sysB->doThing();
		sysC->doThing();
	}
	~Facade()
	{
		delete sysA;
		delete sysB;
		delete sysC;
	}

private:
	SubSystemA *sysA;
	SubSystemB *sysB;
	SubSystemC *sysC;
};

int main()
{
	Facade* facade = new Facade;
	facade->doThing();
	return 0;

