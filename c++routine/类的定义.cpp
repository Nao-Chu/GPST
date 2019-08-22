/*17. �ࣺ����C��struct�����ϣ������ˡ���Ա��������
C��strcut�ɽ�һ�������ʵ����������������һ������ͬһ�����Ĺ�ͬ���ԣ�
C++ʹ��struct�����������ݣ�����������(����)���ڷ��ʻ��޸������(����)����Щ���ԡ�*/
/*
#include <iostream>
using namespace std;
struct Date {
	int d, m, y;
	void init(int dd, int mm, int yy) {
	d = dd; m = mm; y = yy;}
	void print() {
		cout << y << "-" << m << "-" << d << endl;}
};
int main (){
	Date day;
	day.print(); //ͨ����Date����day������Date��print����
	day.init(4, 6, 1999); //ͨ����Date����day������Date��init����
	day.print(); //ͨ����Date����day������Date��print����
	return 0;
}
*/
// ��Ա���� ���� �������á� ��*this��
/*
#include <iostream>
using namespace std;
struct Date {
	int d, m, y;
	void init(int dd, int mm, int yy) {
	d = dd; m = mm; y = yy;}
	void print() {
		cout << y << "-" << m << "-" << d << endl;}
	Date& add(int dd) {
		d = d + dd;
		y = d + dd;
		return *this; }
	};
	// �ж��ٸ�����*thisָ��ͷ��ض��ٸ����� 
	//this��ָ�����������������Ͷ���ָ�룬
 	// *this���ǵ�������������Ǹ�����
	//�����Ա�������ص��ǡ������á�����������������Ķ�����
	//ͨ�����������ã��������������������
 	// day.add(3);
 	// day.add(3).add(7);}
	
int main() {
	Date day;
	day.print(); //ͨ����Date����day������Date��print����
	day.init(4, 6, 1999); //ͨ����Date����day������Date��init����
	day.print(); //ͨ����Date����day������Date��print����
	day.init(4, 6, 2000);
	day.print();
	day.add(3);
	day.add(5).add(7);
	day.print();
	return 0;
}
*/
//��Ա�������ء������������ 
#include <iostream>
using namespace std;
struct Date {
	int d, m, y;
	void init(int dd, int mm, int yy) {
		d = dd; m = mm; y = yy;
	}
	void print() {
		cout << y << "-" << m << "-" << d << endl;
	}
	Date& operator+=(int dd) {
		d = d + dd;
		return *this;
	} 
};

int main() {
	Date day;
	day.print(); //ͨ����Date����day������Date��print����
	day.init(4, 6, 1999); //ͨ����Date����day������Date��init����
	day.print(); //ͨ����Date����day������Date��print����
	day += 3; // day.add(3);
	(day += 5) += 7; //day.add(5).add(7);
	day.print();
	return 0;
}

