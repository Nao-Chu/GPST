/********************************************************************
    > File Name: 09.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 14时36分15秒
 *******************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void mapbase()
{
	map<int,string> map1;
	// one
	map1.insert(pair<int,string>(1,"techer01"));
	map1.insert(pair<int,string>(2,"techer02"));

	// two
	map1.insert(make_pair(3,"techer03"));
	map1.insert(make_pair(4,"techer04"));

	// three
	map1.insert(map<int,string>::value_type(5,"techer05"));
	map1.insert(map<int,string>::value_type(5,"techer06"));

	// four
	map1[7] = "teacher07";
	map1[7] = "teacher08";

	// print one
	for (map<int,string>::iterator it = map1.begin(); it != map1.end(); it++){
		cout << (*it).first << "\t" << it->second << endl;
	}
	cout<<endl;

	// print two
	while(!map1.empty())
	{
		map<int,string>::iterator it = map1.begin();
		cout << (*it).first << "\t" << it->second << endl;
		map1.erase(it);
	}
}

void myinsert()
{
	map<int,string> map1;
	// three
	pair<map<int,string>::iterator,bool> mypair3 = map1.insert(map<int,string>::value_type(5,"techer05"));
	pair<map<int,string>::iterator,bool> mypair5 = map1.insert(map<int,string>::value_type(5,"techer56"));

	if (mypair3.second)
	{
		cout << "mypair3 insert success" << endl;
	}

	if (mypair5.second)
	{
		cout << "mypair5 insert success" << endl;
	}
}

void myfind()
{
	map<int,string> map1;
	// one
	map1.insert(pair<int,string>(10,"techer01"));
	map1.insert(pair<int,string>(20,"techer02"));

	map<int,string>::iterator it2 = map1.find(10);
	if(it2 == map1.end())
	{
		cout << "Not Key" << endl;
	} 
	else
	{
		cout << it2->first << "\t" << it2->second << endl;
	}

	pair<map<int,string>::iterator,map<int,string>::iterator > mypair = map1.equal_range(20);
	if (mypair.first != map1.end())
	{
		cout << "first true : ";
		cout << mypair.first->first << "\t";
		cout << mypair.first->second << endl;
	}
	else
	{
		cout << "first false" << endl;
	}

	if (mypair.second != map1.end())
	{
		cout << "second true" << endl;
	}
	else
	{
		cout << "second false" << endl;
	}

	int i = map1.count(10);
	cout << i << endl;
}


int main()
{
//	mapbase();
//	myinsert();
	myfind();
	return 0;
}
