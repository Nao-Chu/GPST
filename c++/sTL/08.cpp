/********************************************************************
    > File Name: 08.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 03时03分00秒
 *******************************************************************/

#include<iostream>
#include<string.h>
#include<set>
using namespace std;

void setbase()
{
	set <int> set1;
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand() % 100;
		set1.insert(tmp);
	}

	set1.insert(100);
	set1.insert(100);
	set1.insert(100);

	for(set<int>::iterator it = set1.begin(); it!=set1.end(); it++)
	{
		cout << *it << " ";
	}

	cout << "\nerase" << endl;
	while(!set1.empty())
	{
		set<int>::iterator it = set1.begin();
		cout << *it << " ";
		set1.erase(set1.begin());
	}
	cout << "\nset2" << endl;
	set <int,greater<int> > set2;
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand() % 100;
		set2.insert(tmp);
	}
	for(set<int>::iterator it = set2.begin(); it!=set2.end(); it++)
	{
		cout << *it << " ";
	}
}

class Student
{
public:
	Student(char *name,int age)
	{
		strcpy(this->name,name);
		this->age = age;
	}
	char name[64];
	int age;
};
struct FuncStudent
{
	bool operator()(const Student &left,const Student &right)
	{
		return left.age < right.age;
	}
};

void reversefunc()
{
	Student s1((char*)"s1",31);
	Student s2((char*)"s2",33);
	Student s3((char*)"s3",3);
	Student s4((char*)"s4",34);
	Student s5((char*)"s5",3);

	set<Student,FuncStudent> set1;
	pair<set<Student,FuncStudent>::iterator,bool > pair1 = set1.insert(s3);
	pair<set<Student,FuncStudent>::iterator,bool > pair5 = set1.insert(s5);
	if (pair1.second == true)
	{
		cout << "pair1 insert succer" << endl;
	}

	else
	{
		cout << "pair5 insert succer" << endl;
	}
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	set1.insert(s5);

	for(set<Student,FuncStudent>::iterator it = set1.begin(); it!=set1.end(); it++)
	{
		cout << it->name << " " << it->age << endl;
	}
}

void myfind()
{
	set <int> set1;
	for (int i = 0; i < 5; i++)
	{
		set1.insert(i+1);
	}
	for(set<int>::iterator it = set1.begin(); it!=set1.end(); it++)
	{
		cout << *it << " ";
	}
	set<int>::iterator it0 = set1.find(3);
	cout << "\nit0:" << *it0 << endl;

	int num1 = set1.count(3);
	cout << "num1:" << num1 << endl;

	set<int>::iterator it1 = set1.lower_bound(3);
	cout << ">=3 it1:" << *it1 << endl;

	set<int>::iterator it2 = set1.upper_bound(3);
	cout << ">3  it2:" << *it2 << endl;

	cout << "erase 3" << endl;
	set1.erase(3);
	pair<set<int>::iterator,set<int>::iterator > pair1 = set1.equal_range(3);
	set<int>::iterator it3 = pair1.first;
	cout << ">=3 it3:" << *it3 << endl;

	set<int>::iterator it4 = pair1.second;
	cout << ">3  it4:" << *it4 << endl;
}
int main()
{
//	setbase();
//	reversefunc();
	myfind();
}
