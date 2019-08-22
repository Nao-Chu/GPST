//26. Inheritance继承(Derivation派生)： 一个派生类(derived class)
//从1个或多个父类(parent class) / 基类(base class)继承，即继承父类的属性和行为，
//但也有自己的特有属性和行为。如：
#include <iostream>
#include <string>
using namespace std;

class Employee
{
	string name;
public:
	Employee(string n);
	void print();
};
/*
class Manager: public Employee
{
	int level;
public:
	Manager(string n, int l = 1);
	//void print();
};
*/
Employee::Employee(string n) : name(n)//初始化成员列表 
{
// 相当于 name = n;
}

void Employee::print() 
{
	cout << name << endl;
}
/*
Manager::Manager(string n, int l) :Employee(n), level(l) {
}

//派生类的构造函数只能描述它自己的成员和其直接基类的初始式，不能去初始化基类的成员。
//Manager::Manager(string n, int l) :name(n), level(l) {}

int main() {
	Manager m("Zhang",2);
	Employee e("Li");
	m.print();
	e.print();
	return 0;  
}
*/

class Manager : public Employee
{
	int level;
public:
	Manager(string n, int l = 1);
	void print();
};
Manager::Manager(string n, int l) :Employee(n), level(l) {
}
void Manager::print() {
	cout << level << "\t";
	Employee::print();
}
int main() {
	Manager m("Zhang",2);
	Employee e("Li");
	m.print();
	e.print();
}

