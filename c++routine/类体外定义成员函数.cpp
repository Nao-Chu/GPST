//21. �����ⶨ�巽������Ա���������������ඨ����������������Ҫ���������򣬷������ȫ��
//�ⲿ�����ˣ�
#include <iostream>
using namespace std;
class Date {
	int d, m, y;
public:
	void print();
	Date(int dd = 1, int mm = 1, int yy = 1999) {
		d = dd; m = mm; y = yy;
		cout << "���캯��" << endl;
	}
	virtual ~Date() {//������������~���������Ҳ���������û�з�������
	//Ŀǰ����Ҫ���κ��ͷŹ�������Ϊ���캯��û������Դ
		cout << "��������" << endl;
	}
};
void Date::print() {
	cout << y << "-" << m << "-" << d << endl;
}
int main() {
	Date day;
	day.print();
}
