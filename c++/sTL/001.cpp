#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int v){
	cout << v << ",";
}

void test01(){
	vector<int> v = vector<int>({10,20,30,40});

	vector<int>::iterator pBegin = v.begin(); 
	vector<int>::iterator pEnd = v.end();
	for_each(pBegin,pEnd,print);
}

// 容器也可以存放自定义数据类型
class Person{
public:
	Person(int age,int id):age(age),id(id){}
	int age;
	int id;
};

void test02(){
	//创建容器，并且指定容器的元素类型是Person
	vector<Person> v;
	Person p1(10,20), p2(30,40), p3(50,60);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it = v.begin();it != v.end(); it++){
		cout << (*it).age << " " << (*it).id << endl;
	}
}
int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}
