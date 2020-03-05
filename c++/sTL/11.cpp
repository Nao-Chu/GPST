/********************************************************************
    > File Name: 11.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 20时05分24秒
 *******************************************************************/

#include<iostream>
#include<list>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

template <typename T>
class ShowElemt
{
public:
	void operator()(T &t)
	{
		n++;
		cout << t << " ";
	}

	void printN()
	{
		cout << n << " ";
	}
	int n = 0;
};

template <typename T>
void FuncShowElemt2(T &t)
{
	cout << t << " ";
}


void main01()
{
	int a = 10;
	ShowElemt<int> showElemt;
	showElemt(a);
	FuncShowElemt2<int>(a);
}

void main02()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	for_each(v1.begin(),v1.end(),ShowElemt<int>());
	cout << endl;
	for_each(v1.begin(),v1.end(),FuncShowElemt2<int>);
	cout << endl;

	ShowElemt<int> showElemt;
	showElemt = for_each(v1.begin(),v1.end(),showElemt);
	showElemt.printN();
}

template <typename T>
class IsDiv 
{
public:
	IsDiv(const T &divisor)
	{
		this->divisor = divisor;
	}
	bool operator()(T &t)
	{
		return (t%divisor == 0);
	}

	T divisor;
};
void main03()
{
	vector<int> v2;
	for (int i = 10; i < 33; i++)
	{
		v2.push_back(i);
	}
	vector<int>::iterator it = find_if(v2.begin(),v2.end(),IsDiv<int>(4));
	if (it == v2.end())
	{
		cout << "no value is fout" << endl;
	}
	else
	{
		cout << "first value is :" << *it << endl;
	}
}

template <typename T>
class SumAdd
{
public:
	T operator()(T t1,T t2)
	{
		return t1+t2;
	}
};
void main04()
{
	vector<int> v1 ,v2 ,v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(v2.size());
	transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),SumAdd<int>());
	
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << endl;
	}
}

bool MyCompare(const int &a,const int &b)
{
	return a<b;
}
void main05()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		int tmp = rand()%100;
		v[i] = tmp;
	}

	for (vector<int>::iterator it = v.begin();it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(),v.end(),MyCompare);
	for (vector<int>::iterator it = v.begin();it!=v.end(); it++)
	{
		cout << *it << " ";
	}
}

struct CompareNoCase
{
	bool operator()(const string &str1,const string &str2)
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(),str1.end(),str1_.begin(),::tolower);
		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(),str2.end(),str2_.begin(),::tolower);
		return str1_<str2_;
	}
};
void main06()
{
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");
	set<string>::iterator it = set1.find("aAa");
	if(it ==  set1.end())
	{
		cout << "NO FIND" << endl;
	}
	else
	{
		cout << "FIND" << endl;
		cout << *it << endl;
	}

	set<string,CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");
	set<string,CompareNoCase>::iterator it1 = set2.find("aAa");
	if(it1 ==  set2.end())
	{
		cout << "NO FIND" << endl;
	}
	else
	{
		cout << "FIND: " ;
		cout << *it1 << endl;
	}
}
int main()
{
//	main01();
//	main02();
//	main03();
//	main04();
//	main05();
	main06();
}

