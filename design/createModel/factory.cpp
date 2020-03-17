/********************************************************************
    > File Name: 02.cpp
    > Author: zzp
    > Created Time: 2020年03月15日 星期日 00时05分23秒
 *******************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class Fruit
{
public:
	virtual void nameFruit() = 0;
};

class Banana : public Fruit
{
public:
	virtual void nameFruit()
	{
		cout << "banana" << endl;
	}
};

class Pear : public Fruit
{
public:
	virtual void nameFruit()
	{
		cout << "pear" << endl;
	}
};

class Factory
{
public:
	Fruit *Create(char *name)
	{
		if (strcmp(name,"Pear") == 0)
		{
			return new Pear;
		}
		else if (strcmp(name,"Banana") == 0)
		{
			return new Banana;
		}
		return NULL;
	}

	virtual Fruit *getFruit()
	{
		return NULL;
	}
};

class BananaFactory : public Factory
{
public:
	virtual Fruit *getFruit()
	{
		return new Banana;
	}
};

class PearFactory : public Factory
{
public:
	virtual Fruit *getFruit()
	{
		return new Pear;
	}
};

int FactoryMain()
{
	Factory *factory = NULL;
	Fruit *fruit = NULL;

	factory = new BananaFactory;
	fruit = factory->getFruit();
	fruit->nameFruit();
	delete fruit;
	delete factory;

	factory = new PearFactory;
	fruit = factory->getFruit();
	fruit->nameFruit();
	delete fruit;
	delete factory;
	return 0;
}

int easyFactoryMain()
{
	Factory *ff = NULL;
	Fruit *fruit = NULL;

	ff = new Factory;
	fruit = ff->Create((char *)"Pear");
	fruit->nameFruit();
	delete fruit;

	fruit = ff->Create((char *)"Banana");
	fruit->nameFruit();
	delete fruit;

	return 0;
}
