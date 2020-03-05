/********************************************************************
    > File Name: 07.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 02时56分46秒
 *******************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	priority_queue<int> p1;
	priority_queue<int,vector<int>,less<int>> p2;
	priority_queue<int,vector<int>,greater<int>> p3;

	p1.push(33);
	p1.push(11);
	p1.push(41);
	p1.push(21);
	cout << "top = " << p1.top() << endl;
	cout << p1.size() << endl;

	while(p1.size() > 0)
	{
		cout << p1.top() << " ";
		p1.pop();
	}
	cout << endl << "\np3:" << endl;

	p3.push(33);
	p3.push(11);
	p3.push(41);
	p3.push(21);
	cout << "top = " << p3.top() << endl;
	cout << p3.size() << endl;

	while(p3.size() > 0)
	{
		cout << p3.top() << " ";
		p3.pop();
	}
}
