/********************************************************************
    > File Name: 06.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 02时48分24秒
 *******************************************************************/

#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> l;
	cout << "l.size()" << l.size() << endl;
	for (int i = 0 ; i < 5; i++)
	{
		l.push_back(i+1);
	}
	cout << "l.size()" << l.size() << endl;
	list<int>::iterator it = l.begin();
	it++;
	it++;
	l.insert(it,10);
	it = l.begin();
	while(it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	list<int>::iterator it1 = l.begin();
	it1++;
	it1++;
	l.erase(l.begin(),it1);	
	cout << "erase:" << endl;
	it1 = l.begin();
	while(it1 != l.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << "erase begin:" << endl;
	l.erase(l.begin());	
	it1 = l.begin();
	while(it1 != l.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << "remove 5:" << endl;
	l.remove(5);	
	it1 = l.begin();
	while(it1 != l.end())
	{
		cout << *it1 << " ";
		it1++;
	}
}
