/********************************************************************
    > File Name: 12.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 22时54分54秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void plusclass()
{
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x,y);
	cout << "z = " << z << endl;
	plus<string> stringAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = stringAdd(s1,s2);

	vector<string> v1;
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("bbb");
	sort(v1.begin(),v1.end(),greater<string>());
	for(int i = 0; i<v1.size(); i++)
		cout << v1[i] << endl;
}

void count_if()
{
	vector<string> v1;
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("bbb");
	sort(v1.begin(),v1.end(),greater<string>());
	for(int i = 0; i<v1.size(); i++)
		cout << v1[i] << endl;

	string sc = "ccc";
	int num = count_if(v1.begin(),v1.end(),bind2nd(equal_to<string>(),sc));
	cout << num << endl;
}

class IsGreat
{
public:
	IsGreat(int i)
	{
		m_num = i;
	}
	bool operator()(int &num)
	{
		return num>=m_num;
	}
private:
	int m_num;
};
void mycount()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i+1);
	}
	for(int i = 0; i<v1.size(); i++)
		cout << v1[i] << endl;

	int num1 = count(v1.begin(),v1.end(),3);
	cout << "num1:" << num1 << endl;

	int num2 = count_if(v1.begin(),v1.end(),IsGreat(3));
	cout << "num2:" << num2 << endl;

	int num3 = count_if(v1.begin(),v1.end(),bind2nd(greater<int>(),2));
	cout << "num3:" << num3 << endl;

	int num4 = count_if(v1.begin(),v1.end(),bind2nd(modulus<int>(),2));
	cout << " %2 == 1 num4:" << num4 << endl;

	int num5 = count_if(v1.begin(),v1.end(),not1(bind2nd(modulus<int>(),2)));
	cout << " %2 == 0 num5:" << num5 << endl;
}
int main()
{
//	plusclass();	
//	count_if();
	mycount();
	return 0;
}
