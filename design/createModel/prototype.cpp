/********************************************************************
    > File Name: prototype.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 14时15分47秒
 *******************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class CPlusPlusProgrammer;
class Person
{
	virtual void printT() = 0;
	virtual CPlusPlusProgrammer* clone() = 0;
};

class CPlusPlusProgrammer : Person
{
public:
	CPlusPlusProgrammer()
	{
		m_name = "";
		m_age = 0;
		m_resume = NULL;
	}

	CPlusPlusProgrammer(string name, int age)
	{
		m_name = name;
		m_age  = age;
	}
	virtual void printT()
	{
		cout << "m_name:" << m_name << endl;
	}
	virtual CPlusPlusProgrammer* clone()
	{
		CPlusPlusProgrammer *tmp = new CPlusPlusProgrammer;
		*tmp = *this;
		return tmp;
	}
	void setResume(char *p)
	{
		if (m_resume != NULL)
		{
			delete m_resume;
		}
		m_resume = new char(strlen(p) + 1);
		strcpy(m_resume,p);
	}

private:
	string m_name;
	int m_age;
	char *m_resume;
};
int main()
{
	CPlusPlusProgrammer *c1 = new CPlusPlusProgrammer("zs",32);
	c1->printT();

	CPlusPlusProgrammer *c2 = c1->clone();
	c2->printT();
	return 0;
}
