/********************************************************************
    > File Name: 03.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 02时23分45秒
 *******************************************************************/

#include<iostream>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print(int v){
	cout << v << ",";
}

void foreach(){
	deque<int> v = deque<int>({10,20,30,40});
	deque<int>::iterator pEnd = v.end();
	for_each(v.begin(),pEnd,print);
}

// 容器也可以存放自定义数据类型
class Person{
public:
	Person(int age,int id):age(age),id(id){}
	int age;
	int id;
};

void push_pop(){
	//创建容器，并且指定容器的元素类型是Person
	deque<Person> v;
	Person p1(10,20), p2(30,40), p3(50,60);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (deque<Person>::iterator it = v.begin();it != v.end(); it++){
		cout << (*it).age << " " << (*it).id << endl;
	}
	v.pop_back();
	cout << endl << "v.pop_back():" << endl;
	for (deque<Person>::iterator it = v.begin();it != v.end(); it++){
		cout << (*it).age << " " << (*it).id << endl;
	}

	cout << endl << "v.push_front():" << endl;
	v.push_front(Person(1,1));
	for (deque<Person>::iterator it = v.begin();it != v.end(); it++){
		cout << (*it).age << " " << (*it).id << endl;
	}
	cout << endl << "v.pop_front():" << endl;
	v.pop_front();
	for (deque<Person>::iterator it = v.begin();it != v.end(); it++){
		cout << (*it).age << " " << (*it).id << endl;
	}
}

void myerase()
{
	deque<int> v = deque<int>({10,20,30,40});
	deque<int> v1 = v;
	cout << "v:" << endl;
	for_each(v.begin(),v.end(),print);
	cout << endl << "v1:" << endl;
	v1.erase(v1.begin(),v1.begin()+3);
	for_each(v1.begin(),v1.end(),print);

	for (deque<int>::iterator it = v.begin();it != v.end(); it++){
		if (*it == 10)
		{
			it = v.erase(it);
			//v.insert(it,11);
			//*it = 11;
		}
	}
	cout << endl << "if(*it==10) erase :" << endl;
	for_each(v.begin(),v.end(),print);
}

void myinsert()
{
	deque<int> v = deque<int>({10,20,30,40});
	v.insert(v.begin(),100);
	v.insert(v.end(),200);
	for_each(v.begin(),v.end(),print);
}

void myfind()
{
	deque<int> v = deque<int>({10,20,30,40});
	deque<int>::iterator it = find(v.begin(),v.end(),20);
	if (it != v.end())
	{
		cout << "20 in " << distance(v.begin(),it) << endl;
	}
	else
	{
		cout << "No number 20" << endl;
	}
}

int main()
{
	//foreach();
	//push_pop();
	//myerase();
	//myinsert();
	myfind();
	return 0;
}
