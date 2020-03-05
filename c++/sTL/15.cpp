/********************************************************************
    > File Name: 15.cpp
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 01时40分21秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
using namespace std;

class Student
{
public:
	Student(string name,int id)
	{
		m_name = name;
		m_id = id;
	}
	string m_name;
	int m_id;
};

bool CompareS(Student s1,Student s2)
{
	return (s1.m_id < s2.m_id);
}

int main()
{
	vector<int> v1 = vector<int>({5,2,3,1});
	vector<int> v2 = vector<int>({6,4,5,7,9});
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v1.begin());

	vector<Student> v3;
	sort(v3.begin(),v3.end(),CompareS);

	random_shuffle(v1.begin(),v1.end());

	reverse(v1.begin(),v1.end());
	return 0;
}
