//26. Inheritance�̳�(Derivation����)�� һ��������(derived class)
//��1����������(parent class) / ����(base class)�̳У����̳и�������Ժ���Ϊ��
//��Ҳ���Լ����������Ժ���Ϊ���磺
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
Employee::Employee(string n) : name(n)//��ʼ����Ա�б� 
{
// �൱�� name = n;
}

void Employee::print() 
{
	cout << name << endl;
}
/*
Manager::Manager(string n, int l) :Employee(n), level(l) {
}

//������Ĺ��캯��ֻ���������Լ��ĳ�Ա����ֱ�ӻ���ĳ�ʼʽ������ȥ��ʼ������ĳ�Ա��
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

