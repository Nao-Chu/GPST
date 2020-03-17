/********************************************************************
    > File Name: filweight.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 18时49分40秒
 *******************************************************************/

#include<iostream>
#include<map>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	virtual void printT() = 0;
protected:
	string m_name;
	int m_age;
};

class Teacher : public Person
{
public:
	Teacher(string name,int age,string id) : Person(name,age)
	{
		m_id = id;
	}
	void printT()
	{
		cout << m_name << "-";
		cout << m_age << "-" << m_id << endl;
	}

private:
	string m_id;
};

class FlyWeightTeacherFactory
{
public:
	FlyWeightTeacherFactory()
	{
		map1.clear();
	}
	~FlyWeightTeacherFactory()
	{
		while(map1.empty())
		{
			Person *tmp = NULL;
			map<string,Person*>::iterator it = map1.begin();
			tmp = it->second;
			map1.erase(it);
			delete tmp;
		}
	}
	Person * GetTeacher(string id)
	{
		map<string,Person*>::iterator it;
		it = map1.find(id);
		if (it == map1.end())
		{
			string t_name;
			int t_age;
			cout << "please teacher name:" << endl;
			cin >> t_name; 
			cout << "please teacher age:" << endl;
			cin >> t_age; 
			Person *tmp = new Teacher(t_name,t_age,id);
//			map1[id] = tmp;
			map1.insert(pair<string,Person*>(id,tmp));			
			return tmp;
		}
		else
		{
			return it->second;
		}
	}

private:
	map<string,Person*> map1;
};

int main()
{
	Person *p1 = NULL;
	FlyWeightTeacherFactory *fwtf = new FlyWeightTeacherFactory;
	p1 = fwtf->GetTeacher("001");
	p1->printT();

	Person *p2 = NULL;
	p2 = fwtf->GetTeacher("002");
	p2->printT();
	return 0;
}
