/********************************************************************
    > File Name: 13.cpp
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 00时54分55秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include"iterator"
using namespace std;

void my_foreach(int &n)
{
	cout << n << " ";
}

int increase(int i)
{
	return i+100;
}

class CMyshow
{
public:
	void operator()(int &n)
	{
		cout << n << " ";
	}
};
int mysum(int &t1,int &t2)
{
	return t1+t2;
}
int main()
{
	vector<int> v1 = vector<int>({1,2,3});
	for_each(v1.begin(),v1.end(),my_foreach);
	cout << endl;
	transform(v1.begin(),v1.end(),v1.begin(),increase);
	CMyshow my1 = for_each(v1.begin(),v1.end(),CMyshow());
	cout << endl;
	transform(v1.begin(),v1.end(),v1.begin(),negate<int>());
	for_each(v1.begin(),v1.end(),my_foreach);
	cout << endl;
	
	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(),v1.end(),mylist.begin(),bind2nd(multiplies<int>(),-10));
	for_each(mylist.begin(),mylist.end(),my_foreach);
	cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	transform(v1.begin(),v1.end(),v1.begin(),v2.begin(),mysum);
	transform(v2.begin(),v2.end(),ostream_iterator<int>(cout," "),negate<int>());
	return 0;
}
