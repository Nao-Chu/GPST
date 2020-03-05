/********************************************************************
    > File Name: 04.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 02时33分25秒
 *******************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class Teacher
{
	public:
		int age;
		int name[32];
		void printT()
		{
			cout << "age: " << age << endl;
		}
};
int main()
{
	stack<int> s;
	for (int i = 0;i < 10; i++)
	{
		s.push(i+1);
	}
	
	cout << "s.size() = " << s.size() << endl;
	while(!s.empty())
	{
		int tmp = s.top();
		cout << tmp << " ";
		s.pop();
	}

	cout << endl << "\nstack<Teacher>:" << endl;
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	stack<Teacher> sT;
	sT.push(t1);
	sT.push(t2);
	sT.push(t3);
	while(!sT.empty())
	{
		Teacher tmp = sT.top();
		cout << tmp.age << " ";
		sT.pop();
	}

	cout << endl << "\nstack<*Teacher>:" << endl;
	stack<Teacher *> sTe;
	sTe.push(&t1);
	sTe.push(&t2);
	sTe.push(&t3);
	while(!sTe.empty())
	{
		Teacher* tmp = sTe.top();
		tmp->printT();
		sTe.pop();
	}

}
