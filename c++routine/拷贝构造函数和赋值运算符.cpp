/*20. ������ �������캯������ֵ�����
 ���и�ֵΪʲô�����
 ��student m(s);
 s = k;��
 �������캯��������һ�������ʱ��ͬ���͵���������ʼ��
 ��ֵ�������һ������ֵ������һ������
 */
/*
#define _CRT_SECURE_NO_WARNINGS //windowsϵͳ
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct student {
	char *name;
	int age;
	student(char *n = "no name", int a = 0) {
		name = new char[100]; // ��malloc��!
		strcpy(name, n);
		age = a;
		cout << "���캯����������100��charԪ�صĶ�̬�ռ�" << endl;
	}
	virtual ~student() { // ��������
		delete[] name; // ������free!
		cout << "�����������ͷ���100��charԪ�صĶ�̬�ռ�" << endl;
	}
};
int main() {
	student s;
	student k("John", 56);
	cout << k.name << ", age " << k.age << endl;
	student m(s); //�������캯�� 
	s = k; //��ֵ�����
	cout << s.name << ", age " << s.age << endl;
	return 0;
}
*/
/*
Ĭ�ϵġ��������캯�����ǡ�Ӳ�����������Ա��������nameָ��ͬһ�鶯̬�ַ����飬����
���ͷ�ͬһ���ڴ�Ͳ����ˣ�
ָӦ�����ӡ��������캯��������֤�����е����Ķ�̬����ռ䡣
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
		name = new char[100]; // ��malloc��!
		strcpy(name, n);
		age = a;
		cout << "���캯����������100��charԪ�صĶ�̬�ռ�" << endl;
	}
	
	student(const student &s) { // �������캯�� Copy constructor
		name = new char[100];
		strcpy(name, s.name);
		age = s.age;
		cout << "�������캯������֤nameָ������Լ��������ڴ��" << endl;
	}
	student & operator=(const student &s) { // �������캯�� Copy constructor
		strcpy(name, s.name);
		age = s.age;
		cout << "�������캯������֤nameָ������Լ��������ڴ��" << endl;
		return *this; //���� �������á�
	}
	virtual ~student(){ // ��������
		delete[] name; // ������free!
		cout << "�����������ͷ���100��charԪ�صĶ�̬�ռ�" << endl;
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

