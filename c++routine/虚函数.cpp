/*27. �麯��Virtual Functions
�������ָ������Զ�ת��Ϊ����ָ��, ��һ��ָ������ָ��ֱ�ָ����������������
�󣬲�2�ε���print()��������������Σ�
int main() {
	Employee *p;
	Manager m("Zhang", 1);
	Employee e("Li");
	p = &e;
	p->print();
	p = &m;
	p->print();
}*/
//���Խ�print����Ϊ�麯��Virtual Functions
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

//��һ����˾�Ĺ�Ա(��������)Ҫ������һ��������vector�У���ô�죿
//�ѵ���2�����飺
//Manager managers[100]; int m_num=0;
//Employee employees[100]; int e_num=0;
//������Ҳ�ǹ�Ա����
//ʵ���ϣ��������ָ������Զ�ת��Ϊ����ָ�롣���Խ����й�Ա������һ��
//Employee* employees[100]; int e_num=0; 
int main() {
	Employee* employees[100]; int e_num = 0;
	Employee* p;
	string name; 
	int level;
	char cmd;
	while (cin >> cmd) {
		if (cmd == 'M' || cmd == 'm') {
			cout << "�����������ͼ���" << endl;
			cin >> name >> level;
			p = new Manager(name, level);
			employees[e_num] = p; e_num++;
		}
		else if (cmd == 'e' || cmd == 'E') {
			cout << "����������" << endl;
			cin >> name;
			p = new Employee(name);
			employees[e_num] = p; e_num++;
		}
		else break;
		cout << "����������" << endl;
	}
	for (int i = 0; i < e_num; i++) {
		employees[i]->print();
	}
}
//��Ȼ�����ǿ��Դ�һ���������������ͬ���࣬�磺
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
//����Ҳ���ԴӶ����ͬ����������һ����������������(Multiple inheritance)
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
