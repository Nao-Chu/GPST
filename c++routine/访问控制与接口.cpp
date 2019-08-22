//19. 访问控制、类接口 
//将关键字struct换成class
/*
#include <iostream>
#include <cstring>
using namespace std;
class student {
	char *name;
	int age;
	student(char *n = "no name", int a = 0) {
		name = new char[100]; // 比malloc好!
		strcpy(name, n);
		age = a;
		cout << "构造函数，申请了100个char元素的动态空间" << endl;}
	virtual ~student() { // 析构函数
		delete name; // 不能用free!
		cout << "析构函数，释放了100个char元素的动态空间" << endl;
	}
};
int main() {
	cout << "Hello!" << endl << endl;
	student a; //编译出错:无法访问 private 成员(在“student”类中声明)
	cout << a.name << ", age " << a.age << endl << endl; //编译出错
	student b("John"); //编译出错
	cout << b.name << ", age " << b.age << endl << endl;//编译出错
	b.age = 21; //编译出错
	cout << b.name << ", age " << b.age << endl << endl;//编译出错
	return 0;
}
*/
//class定义的类的成员默认都是私有的private，外部函数无法通过类对象成员或类成员函数
/*
#include <iostream>
#include <cstring>
using namespace std;
class student {
	//默认私有的，等价于 private:
	 char *name;
	 int age;
	 public: //公开的
		student(char *n = "no name", int a = 0) {
			name = new char[100]; // 比malloc好!
			strcpy(name, n);
			age = a;
			cout << "构造函数，申请了100个char元素的动态空间" << endl;
		}
		virtual ~student() { // 析构函数
			delete name; // 不能用free!
			cout << "析构函数，释放了100个char元素的动态空间" << endl;
		}
 };
int main() {
	cout << "Hello!" << endl << endl;
	student a; //OK
	cout << a.name << ", age " << a.age << endl ; //编译出错: 无法访问 private 成员(在“student”类中声明)
	student b("John");
	cout << b.name << ", age " << b.age << endl ;//编译出错
	b.age = 21; 
	cout << b.name << ", age " << b.age << endl l;//编译出错
	return 0;
 }
 */
//a.name，a.age仍然不能访问， 如何进一步修改呢？
/*
#include <iostream>
#include <cstring>
using namespace std;
class student {
	//默认私有的，等价于 private:
	 char *name;
	 int age;
	 public: //公开的
		 char *get_name() { return name; }
		 int get_age() { return age; }
		 void set_age(int ag) { age = ag; }
		 student(char *n = "no name", int a = 0) {
			name = new char[100]; // 比malloc好!
			strcpy(name, n);
			age = a;
			cout << "构造函数，申请了100个char元素的动态空间" << endl;
		 }
		 virtual ~student() { // 析构函数
		 	delete name; // 不能用free!
			cout << "析构函数，释放了100个char元素的动态空间" << endl;
		 }
 };
 int main() {
	cout << "Hello!" << endl << endl;
	student a;
	cout << a.get_name() << ", age " << a.get_age() << endl ; //编译出错
	student b("John");
	cout << b.get_name() << ", age " << b.get_age() << endl ;//编译出错
	b.set_age(21);
	cout << b.get_name() << ", age " << b.get_age() << endl ;//编译出错
 	return 0;
 }
 */
//接口：public的公开成员（一般是成员函数）称为这个类的对外接口，外部函数只能通过这些接
//口访问类对象，
//private等非public的包含内部内部细节，不对外公开，从而可以封装保护类对象！
//定义一个数组类array

#include <iostream>
#include <cstdlib>
using namespace std;
class Array {
private:
	 int size;
	 double *data;
public:
	 Array(int s) {
		 size = s;
		 data = new double[s];
	 }
	 virtual ~Array() {
	 	delete[] data;
	 }
	 double &operator [] (int i) {
		 if (i < 0 || i >= size) {
			 cerr << endl << "Out of bounds" << endl;
			 throw "Out of bounds";
		 }
		 else return data[i];
		 }
 };
 int main() {
	 Array t(5);
	 t[0] = 45; // OK
	 t[4] = t[0] + 6; // OK
	 cout << t[4] << endl; // OK
	 t[10] = 7; // error!
	 return 0;
 }
 
