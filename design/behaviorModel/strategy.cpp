/********************************************************************
    > File Name: strategy.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 00时21分43秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Strategy
{
public:
	virtual void crypt() = 0;
};

class AES : public Strategy
{
public:
	virtual void crypt()
	{
		cout << "AES" << endl;
	}
};

class DES : public Strategy
{
public:
	virtual void crypt()
	{
		cout << "DES" << endl;
	}
};

class Context
{
public:
	void setStrategy(Strategy *strategy)
	{
		this->strategy = strategy;
	}
	void myoperator()
	{
		this->strategy->crypt(); 
	}

private:
	Strategy *strategy;
};

int main()
{
	Strategy *strategy = new DES;
	Context *context = new Context();
	context->setStrategy(strategy);
	context->myoperator();
	return 0;
}
