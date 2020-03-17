/********************************************************************
    > File Name: 01.cpp
    > Author: zzp
    > Created Time: 2020年03月14日 星期六 23时28分06秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Singleton
{
private:
	Singleton()
	{
		;
	}
public:
	/*
	static Singleton *GetSingleton()
	{
		if (single == NULL)
		{
			single = new Singleton;
		}
		return single;
	}
	*/

	static Singleton *GetSingleton()
	{
		return single;
	}
private:
	static Singleton *single;
};

//Singleton* Singleton::single = NULL;
Singleton* Singleton::single = new Singleton;
int main()
{
	Singleton *s1 = Singleton::GetSingleton();
	Singleton *s2 = Singleton::GetSingleton();
	if (s1 == s2)
	{
		cout << "s1 == s2" << endl;
	}
	return 0;
}
