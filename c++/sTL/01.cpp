/********************************************************************
    > File Name: 01.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 01时14分24秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int print()
{
	string s1 = "sdaaa"; 

	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (string::iterator it = s1.begin();it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << s1.c_str() << endl;
	char buf1[128] = {0};
	s1.copy(buf1,3,2);
	cout << buf1;
}

void add()
{
	string a = "asd";
	string b = "ghh";
	a = a+b;
	cout << a.c_str() << endl;
}

void myfind()
{
	string s1 = "1  aaa sdds asfss aaa dfs aaa";
	int index = -1;
	int count = -1;
	do
	{
		index += 1;
		index = s1.find("aaa",index);
		count++;
	}while(index != string::npos);

	cout << "count = " << count << endl;

	// aaa -> AAA
	cout << "------------" << endl;
	cout << s1.c_str() << endl;
	index = s1.find("aaa",0);
	while(index != string::npos)
	{
		s1.replace(index,3,"AAA");
		index += 1;
		index = s1.find("aaa",index);
	}	
	cout << s1.c_str() << endl;
	cout << "------------" << endl;

}

void myerase()
{
	string s1 = "hello world hello2";
	string::iterator it = find(s1.begin(),s1.end(),'e');
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << "erase after: " << s1 << endl;
	s1.erase(s1.begin(),s1.end());
	cout << "erase all: " << s1 <<endl;
	cout << "s1.len = " << s1.length() << endl;

	string s2 = "bbb";
	s2.insert(0,"AAA");
	cout << "s2 = " << s2 << endl;
}

void trans()
{
	string s1 = "AAAbbb";
	cout << "s1 : " << s1 << endl;
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	cout << "s1 ::toupper : " << s1 << endl;
	transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	cout << "s1 ::tolower : " << s1 << endl;
}

int main()
{
	//print();
	//add();
	//myfind();
	//myerase();
	trans();
	return 0;
}
