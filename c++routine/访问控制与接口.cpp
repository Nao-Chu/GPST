//19. ���ʿ��ơ���ӿ� 
//���ؼ���struct����class
/*
#include <iostream>
#include <cstring>
using namespace std;
class student {
	char *name;
	int age;
	student(char *n = "no name", int a = 0) {
		name = new char[100]; // ��malloc��!
		strcpy(name, n);
		age = a;
		cout << "���캯����������100��charԪ�صĶ�̬�ռ�" << endl;}
	virtual ~student() { // ��������
		delete name; // ������free!
		cout << "�����������ͷ���100��charԪ�صĶ�̬�ռ�" << endl;
	}
};
int main() {
	cout << "Hello!" << endl << endl;
	student a; //�������:�޷����� private ��Ա(�ڡ�student����������)
	cout << a.name << ", age " << a.age << endl << endl; //�������
	student b("John"); //�������
	cout << b.name << ", age " << b.age << endl << endl;//�������
	b.age = 21; //�������
	cout << b.name << ", age " << b.age << endl << endl;//�������
	return 0;
}
*/
//class�������ĳ�ԱĬ�϶���˽�е�private���ⲿ�����޷�ͨ��������Ա�����Ա����
/*
#include <iostream>
#include <cstring>
using namespace std;
class student {
	//Ĭ��˽�еģ��ȼ��� private:
	 char *name;
	 int age;
	 public: //������
		student(char *n = "no name", int a = 0) {
			name = new char[100]; // ��malloc��!
			strcpy(name, n);
			age = a;
			cout << "���캯����������100��charԪ�صĶ�̬�ռ�" << endl;
		}
		virtual ~student() { // ��������
			delete name; // ������free!
			cout << "�����������ͷ���100��charԪ�صĶ�̬�ռ�" << endl;
		}
 };
int main() {
	cout << "Hello!" << endl << endl;
	student a; //OK
	cout << a.name << ", age " << a.age << endl ; //�������: �޷����� private ��Ա(�ڡ�student����������)
	student b("John");
	cout << b.name << ", age " << b.age << endl ;//�������
	b.age = 21; 
	cout << b.name << ", age " << b.age << endl l;//�������
	return 0;
 }
 */
//a.name��a.age��Ȼ���ܷ��ʣ� ��ν�һ���޸��أ�
/*
#include <iostream>
#include <cstring>
using namespace std;
class student {
	//Ĭ��˽�еģ��ȼ��� private:
	 char *name;
	 int age;
	 public: //������
		 char *get_name() { return name; }
		 int get_age() { return age; }
		 void set_age(int ag) { age = ag; }
		 student(char *n = "no name", int a = 0) {
			name = new char[100]; // ��malloc��!
			strcpy(name, n);
			age = a;
			cout << "���캯����������100��charԪ�صĶ�̬�ռ�" << endl;
		 }
		 virtual ~student() { // ��������
		 	delete name; // ������free!
			cout << "�����������ͷ���100��charԪ�صĶ�̬�ռ�" << endl;
		 }
 };
 int main() {
	cout << "Hello!" << endl << endl;
	student a;
	cout << a.get_name() << ", age " << a.get_age() << endl ; //�������
	student b("John");
	cout << b.get_name() << ", age " << b.get_age() << endl ;//�������
	b.set_age(21);
	cout << b.get_name() << ", age " << b.get_age() << endl ;//�������
 	return 0;
 }
 */
//�ӿڣ�public�Ĺ�����Ա��һ���ǳ�Ա��������Ϊ�����Ķ���ӿڣ��ⲿ����ֻ��ͨ����Щ��
//�ڷ��������
//private�ȷ�public�İ����ڲ��ڲ�ϸ�ڣ������⹫�����Ӷ����Է�װ���������
//����һ��������array

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
 
