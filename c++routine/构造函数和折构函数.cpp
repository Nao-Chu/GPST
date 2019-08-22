/*18. 构造函数和析构函数
构造函数是和类名同名且没有返回类型的函数，在定义对象时会自动被调用，而不需要在单独调
用专门的初始化函数如init，
构造函数用于初始化类对象成员，包括申请一些资源，如分配内存、打开某文件等
析构函数是在类对象销毁时被自动调用，用于释放该对象占用的资源，如释放占用的内存、关闭
打开的文件*/
/*
#include <iostream>
using namespace std;
struct Date {
		int d, m, y;
		Date(int dd, int mm, int yy) {
			d = dd; m = mm; y = yy;
			cout << "构造函数" << endl;}
		void print() {
			cout << y << "-" << m << "-" << d << endl;}
		~Date() {//析构函数名是~和类名，且不带参数，没有返回类型
			//目前不需要做任何释放工作，因为构造函数没申请资源
			cout << "析构函数" << endl;	}
};
int main(){
	Date day(1,2,3); //错：会自动调用构造函数，但没提供3个参数
	Date(4, 6, 1999); //会自动调用构造函数Date(int dd, int mm, int yy)
	// day.init(4, 6, 1999); //通过类Date对象day调用类Date的init方法
	day.print(); //通过类Date对象day调用类Date的print方法
	return 0;
}
*/

//执行上述代码，看看构造函数和析构函数执行了吗？
//假如想如下调用构造函数构造对象，是不是要定义多个同名的构造函数（即重载构造函数）?
/*
Date day;
Date day1(2);
Date day2(23, 10);
Date day3(2,3,1999);
//当然可以的
struct Date {
	int d, m, y;
	Date() {
	d = m = 1; y = 2000;
	cout << "构造函数" << endl;}
	Date(int dd) {
		d = dd; m = 1; y = 2000;
		cout << "构造函数" << endl;
	}
	Date(int dd, int mm) {
		d = dd; m = mm; y = 2000;
		cout << "构造函数" << endl;
	}
	Date(int dd, int mm, int yy) {
		d = dd; m = mm; y = yy;
		cout << "构造函数" << endl;
	}
	void print() {
		cout << y << "-" << m << "-" << d << endl;
	}
	~Date() {//析构函数名是~和类名，且不带参数，没有返回类型
	//目前不需要做任何释放工作，因为构造函数没申请资源
		cout << "析构函数" << endl;}
};
*/
//为什么不用默认参数呢？
/*
#include <iostream>
using namespace std;
struct Date {
	int d, m, y;
		Date(int dd = 1, int mm = 1, int yy = 1999) {
		d = dd; m = mm; y = yy;
		cout << "构造函数" << endl;
	}
	void print() {
		cout << y << "-" << m << "-" << d << endl;
	}
	~Date() {//析构函数名是~和类名，且不带参数，没有返回类型
	//目前不需要做任何释放工作，因为构造函数没申请资源
		cout << "析构函数" << endl;
		}
};
int main(){
	Date day;
	Date day1(2);
	Date day2(23, 10);
	Date day3(2, 3, 1999);
	day.print();
	day1.print();
	day2.print();
	day3.print();
	return 0;
}
*/

//析构函数示例
#define _CRT_SECURE_NO_WARNINGS //windows系统
#include <iostream>
#include <cstring>
using namespace std;
struct student {
	char *name;
	int age;
	student(char *n = "no name", int a = 0) {
	name = new char[100]; // 比malloc好!
	strcpy(name, n);
	age = a;
	cout << "构造函数，申请了100个char元素的动态空间" << endl;}
	virtual ~student(){ // 析构函数
	delete name; // 不能用free!
	cout << "析构函数，释放了100个char元素的动态空间" << endl;}
};
int main() {
	cout << "Hello!" << endl << endl;
	student a;
	cout << a.name << ", age " << a.age << endl << endl;
	student b("John");
	cout << b.name << ", age " << b.age << endl << endl;
	b.age = 21;
	cout << b.name << ", age " << b.age << endl << endl;
	student c("Miki", 45);
	cout << c.name << ", age " << c.age << endl << endl;
	cout << "Bye!" << endl << endl;
	return 0;
}
