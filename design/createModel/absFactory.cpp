/********************************************************************
    > File Name: absFactory.cpp
    > Author: zzp
    > Created Time: 2020年03月16日 星期一 23时25分13秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void nameFruit() = 0;
};

class northBanana : public Fruit
{
public:
	virtual void nameFruit()
	{
		cout << "banana" << endl;
	}
};

class northPear : public Fruit
{
public:
	virtual void nameFruit()
	{
		cout << "pear" << endl;
	}
};

class sourthBanana : public Fruit
{
public:
	virtual void nameFruit()
	{
		cout << "sourthBanana" << endl;
	}
};

class sourthPear : public Fruit
{
public:
	virtual void nameFruit()
	{
		cout << "sourthPear" << endl;
	}
};

class abstractFactory 
{
public:
	virtual Fruit* createBanana() = 0;
	virtual Fruit* createPear() = 0;
};


class northAbstractFactory : public abstractFactory 
{
public:
	virtual Fruit* createBanana()
	{
		return new northBanana;
	}
	virtual Fruit* createPear()
	{
		return new northPear;
	}
};

class sourthAbstractFactory : public abstractFactory 
{
public:
	virtual Fruit* createBanana()
	{
		return new sourthBanana;
	}
	virtual Fruit* createPear()
	{
		return new sourthPear;
	}
};

int main()
{
	abstractFactory* factory = NULL; 
	Fruit* fruit = NULL;
	factory	= new sourthAbstractFactory;
	fruit = factory->createBanana();
	fruit->nameFruit();
	delete factory;
	
	return 0;
}
