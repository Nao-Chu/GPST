/*18. ���캯������������
���캯���Ǻ�����ͬ����û�з������͵ĺ������ڶ������ʱ���Զ������ã�������Ҫ�ڵ�����
��ר�ŵĳ�ʼ��������init��
���캯�����ڳ�ʼ��������Ա����������һЩ��Դ��������ڴ桢��ĳ�ļ���
���������������������ʱ���Զ����ã������ͷŸö���ռ�õ���Դ�����ͷ�ռ�õ��ڴ桢�ر�
�򿪵��ļ�*/
/*
#include <iostream>
using namespace std;
struct Date {
		int d, m, y;
		Date(int dd, int mm, int yy) {
			d = dd; m = mm; y = yy;
			cout << "���캯��" << endl;}
		void print() {
			cout << y << "-" << m << "-" << d << endl;}
		~Date() {//������������~���������Ҳ���������û�з�������
			//Ŀǰ����Ҫ���κ��ͷŹ�������Ϊ���캯��û������Դ
			cout << "��������" << endl;	}
};
int main(){
	Date day(1,2,3); //�����Զ����ù��캯������û�ṩ3������
	Date(4, 6, 1999); //���Զ����ù��캯��Date(int dd, int mm, int yy)
	// day.init(4, 6, 1999); //ͨ����Date����day������Date��init����
	day.print(); //ͨ����Date����day������Date��print����
	return 0;
}
*/

//ִ���������룬�������캯������������ִ������
//���������µ��ù��캯����������ǲ���Ҫ������ͬ���Ĺ��캯���������ع��캯����?
/*
Date day;
Date day1(2);
Date day2(23, 10);
Date day3(2,3,1999);
//��Ȼ���Ե�
struct Date {
	int d, m, y;
	Date() {
	d = m = 1; y = 2000;
	cout << "���캯��" << endl;}
	Date(int dd) {
		d = dd; m = 1; y = 2000;
		cout << "���캯��" << endl;
	}
	Date(int dd, int mm) {
		d = dd; m = mm; y = 2000;
		cout << "���캯��" << endl;
	}
	Date(int dd, int mm, int yy) {
		d = dd; m = mm; y = yy;
		cout << "���캯��" << endl;
	}
	void print() {
		cout << y << "-" << m << "-" << d << endl;
	}
	~Date() {//������������~���������Ҳ���������û�з�������
	//Ŀǰ����Ҫ���κ��ͷŹ�������Ϊ���캯��û������Դ
		cout << "��������" << endl;}
};
*/
//Ϊʲô����Ĭ�ϲ����أ�
/*
#include <iostream>
using namespace std;
struct Date {
	int d, m, y;
		Date(int dd = 1, int mm = 1, int yy = 1999) {
		d = dd; m = mm; y = yy;
		cout << "���캯��" << endl;
	}
	void print() {
		cout << y << "-" << m << "-" << d << endl;
	}
	~Date() {//������������~���������Ҳ���������û�з�������
	//Ŀǰ����Ҫ���κ��ͷŹ�������Ϊ���캯��û������Դ
		cout << "��������" << endl;
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

//��������ʾ��
#define _CRT_SECURE_NO_WARNINGS //windowsϵͳ
#include <iostream>
#include <cstring>
using namespace std;
struct student {
	char *name;
	int age;
	student(char *n = "no name", int a = 0) {
	name = new char[100]; // ��malloc��!
	strcpy(name, n);
	age = a;
	cout << "���캯����������100��charԪ�صĶ�̬�ռ�" << endl;}
	virtual ~student(){ // ��������
	delete name; // ������free!
	cout << "�����������ͷ���100��charԪ�صĶ�̬�ռ�" << endl;}
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
