/*20. 拷贝： 拷贝构造函数、赋值运算符
 下列赋值为什么会出错？
 “student m(s);
 s = k;”
 拷贝构造函数：定义一个类对象时用同类型的另外对象初始化
 赋值运算符：一个对象赋值给另外一个对象
 */
/*
#define _CRT_SECURE_NO_WARNINGS //windows系统
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct student {
	char *name;
	int age;
	student(char *n = "no name", int a = 0) {
		name = new char[100]; // 比malloc好!
		strcpy(name, n);
		age = a;
		cout << "构造函数，申请了100个char元素的动态空间" << endl;
	}
	virtual ~student() { // 析构函数
		delete[] name; // 不能用free!
		cout << "析构函数，释放了100个char元素的动态空间" << endl;
	}
};
int main() {
	student s;
	student k("John", 56);
	cout << k.name << ", age " << k.age << endl;
	student m(s); //拷贝构造函数 
	s = k; //赋值运算符
	cout << s.name << ", age " << s.age << endl;
	return 0;
}
*/
/*
默认的“拷贝构造函数”是“硬拷贝”或“逐成员拷贝”，name指针同一块动态字符数组，当多
次释放同一块内存就不错了！
指应该增加“拷贝构造函数”，保证各自有单独的动态数组空间。
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct student {
	char *name;
	int age;
	
	student(char *n = "no name", int a = 0) {
		name = new char[100]; // 比malloc好!
		strcpy(name, n);
		age = a;
		cout << "构造函数，申请了100个char元素的动态空间" << endl;
	}
	
	student(const student &s) { // 拷贝构造函数 Copy constructor
		name = new char[100];
		strcpy(name, s.name);
		age = s.age;
		cout << "拷贝构造函数，保证name指向的是自己单独的内存块" << endl;
	}
	student & operator=(const student &s) { // 拷贝构造函数 Copy constructor
		strcpy(name, s.name);
		age = s.age;
		cout << "拷贝构造函数，保证name指向的是自己单独的内存块" << endl;
		return *this; //返回 “自引用”
	}
	virtual ~student(){ // 析构函数
		delete[] name; // 不能用free!
		cout << "析构函数，释放了100个char元素的动态空间" << endl;
	}
};
int main() {
	student s;
	student k("John", 56);
	cout << k.name << ", age " << k.age << endl ;
	student m(k);
	s = k; //s.operator(k)
	cout << s.name << ", age " << s.age << endl ;
	return 0;
}

