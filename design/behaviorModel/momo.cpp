/********************************************************************
    > File Name: momo.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 17时07分01秒
 *******************************************************************/

#include<iostream>
using namespace std;

class MememTo 
{
public:
	MememTo(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setAge(int age)
	{
		m_age = age;
	}
	MememTo* createMememTo()
	{
		return new MememTo(m_name,m_age);
	}
	void setMememTo(MememTo* memto)
	{
		m_name = memto->getName();
		m_age = memto->getAge();
	}
	void printT()
	{
		cout << m_name << " : " << m_age << endl;
	}

private:
	string m_name;
	int m_age;
};

class Person 
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setAge(int age)
	{
		m_age = age;
	}
	MememTo* createMememTo()
	{
		return new MememTo(m_name,m_age);
	}
	void setMememTo(MememTo* memto)
	{
		m_name = memto->getName();
		m_age = memto->getAge();
	}
	void printT()
	{
		cout << m_name << " : " << m_age << endl;
	}

private:
	string m_name;
	int m_age;
};

class Caretaker
{
public:
	Caretaker(MememTo *memto)
	{
		this->memto = memto;
	}
	MememTo *getMememTo()
	{
		return memto;
	}
	void setMememTo(MememTo *memto)
	{
		this->memto = memto;
	}

private:
	MememTo *memto;
};

int main()
{
	Person *p = new Person("Lili",23);
	p->printT();
	Caretaker *caretaker = new Caretaker(p->createMememTo()); 
	p->setName("Lisa");
	p->setAge(18);
	p->printT();

	p->setMememTo(caretaker->getMememTo());
	p->printT();

	delete caretaker;
	delete p;
	return 0;
}
