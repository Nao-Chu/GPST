/********************************************************************
    > File Name: 05.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 02时42分54秒
 *******************************************************************/

#include<iostream>
#include<queue>
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
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << "front:" << q.front() << endl;
	cout << "size: " << q.size()  << endl;
	while(!q.empty())
	{
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();
	}
	Teacher t1,t2;
	t1.age = 41;
	t2.age = 42;
	queue<Teacher*> qu;
	qu.push(&t1);
	qu.push(&t2);
	while(!qu.empty())
	{
		Teacher* tmp = qu.front();
		tmp->printT();
		qu.pop();
	}

	return 0;
}
