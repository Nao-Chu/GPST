/********************************************************************
    > File Name: broker.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 00时33分13秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Mediator;

class Person
{
public:
	Person(string name,int sex, int condi,Mediator *m)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
		mediator = m;
	}
	string getName()
	{
		return m_name;
	}
	int getSex()
	{
		return m_sex;
	}
	int getCondi()
	{
		return m_condi;
	}
	virtual void setParter(Person *p) = 0;

private:
	string m_name;
	int m_sex;
	int m_condi;

protected:
	Mediator *mediator; 
};

class Mediator
{
public:
	virtual void getParter()
	{
		if(pMan->getSex() == pWoman->getSex())
		{
			cout << "gay" << endl;
		}
		if(pMan->getCondi() == pWoman->getCondi())
		{
			cout << pMan->getName() << " == " << pWoman->getName() << endl;
		}
	}
	void setMan(Person *man)
	{
		pMan = man;
	}
	void setWoman(Person *Woman)
	{
		pWoman = Woman;
	}
private:
	Person *pMan;
	Person *pWoman;
};

class Woman : public Person
{
public:
	Woman(string name,int sex, int condi,Mediator *m) : Person(name,sex,condi,m)
	{
		
	}
	virtual void setParter(Person *p)
	{
		mediator->setWoman(p);
		mediator->setMan(this);
		mediator->getParter();
	}
};

class Man : public Person
{
public:
	Man(string name,int sex, int condi,Mediator *m) : Person(name,sex,condi,m)
	{
		
	}
	virtual void setParter(Person *p)
	{
		mediator->setMan(p);
		mediator->setWoman(this);
		mediator->getParter();
	}
};

int main()
{
	Mediator *m = new Mediator;
	Person *buli = new Woman("Buli",2,5,m);
	Person *joil = new Man("Joil",1,4,m);
	Person *momo = new Man("Momo",1,5,m);
	buli->setParter(joil);
	joil->setParter(joil);
	return 0;
}
