/*27. 虚函数Virtual Functions
派生类的指针可以自动转化为基类指针, 用一个指向基类的指针分别指向基类对象和派生类对
象，并2次调用print()函数输出，结果如何？
int main() {
	Employee *p;
	Manager m("Zhang", 1);
	Employee e("Li");
	p = &e;
	p->print();
	p = &m;
	p->print();
}*/
//可以将print声明为虚函数Virtual Functions
#include <iostream>
#include <string>
using namespace std;
class Employee
{
	string name;
public:
	Employee(string n);
	virtual void print();
};
class Manager : public Employee
{
	int level;
public:
	Manager(string n, int l = 1);
	void print();
};
Employee::Employee(string n) :name(n) {
}
void Employee::print() {
	cout << name << endl;
}
Manager::Manager(string n, int l) :Employee(n), level(l) {
}
void Manager::print() {
	cout << level << "\t";
	Employee::print();
}
int main() {
	Employee *p;
	Manager m("Zhang", 1);
	Employee e("Li");
	p = &e;
	p->print();
	p = &m;
	p->print();
}

//如一个公司的雇员(包括经理)要保存在一个数组如vector中，怎么办？
//难道用2个数组：
//Manager managers[100]; int m_num=0;
//Employee employees[100]; int e_num=0;
//但经理也是雇员啊？
//实际上：派生类的指针可以自动转化为基类指针。可以将所有雇员保存在一个
//Employee* employees[100]; int e_num=0; 
int main() {
	Employee* employees[100]; int e_num = 0;
	Employee* p;
	string name; 
	int level;
	char cmd;
	while (cin >> cmd) {
		if (cmd == 'M' || cmd == 'm') {
			cout << "请输入姓名和级别" << endl;
			cin >> name >> level;
			p = new Manager(name, level);
			employees[e_num] = p; e_num++;
		}
		else if (cmd == 'e' || cmd == 'E') {
			cout << "请输入姓名" << endl;
			cin >> name;
			p = new Employee(name);
			employees[e_num] = p; e_num++;
		}
		else break;
		cout << "请输入命令" << endl;
	}
	for (int i = 0; i < e_num; i++) {
		employees[i]->print();
	}
}
//当然，我们可以从一个类派生出多个不同的类，如：
class Employee{
//...
public:
virtual void print();
};
class Manager : public Employee{
// ...
public:
void print();
};
class Secretary : public Employee{
// ...
public:
void print();
};
//我们也可以从多个不同的类派生出一个类来：多重派生(Multiple inheritance)
class One{
// class internals
};
class Two{
// class internals
};
class MultipleInheritance : public One, public Two
{
// class internals
};
*/
