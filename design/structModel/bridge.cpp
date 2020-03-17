/********************************************************************
    > File Name: bridge.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 15时32分33秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Engine
{
public:
	virtual void InstallEngine() = 0;
};

class e4400cc : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "4400cc" << endl;
	}
};

class e4500cc : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "4500cc" << endl;
	}
};

class car
{
public:
	virtual void carType() = 0;
};

class BaoMa : public car
{
public:
	BaoMa(Engine* engine)
	{
		m_install = engine;
	}
	virtual void carType()
	{
		cout << "BaoMa" << endl;
		m_install->InstallEngine();
	}

private:
	Engine* m_install;
};

class Jeep : public car
{
public:
	Jeep(Engine* engine)
	{
		m_install = engine;
	}
	virtual void carType()
	{
		cout << "Jeep" << endl;
		m_install->InstallEngine();
	}

private:
	Engine* m_install;
};

int main()
{
	e4400cc *a = new e4400cc; 
	car *c = new BaoMa(a);
	c->carType();
	return 0;
}
