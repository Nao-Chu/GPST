//15. ģ��template����������˶�ÿ����������Сֵ
/*
#include <iostream>
using namespace std;
int minValue(int a, int b) {//return a<b?a:b
	if (a < b) return a;
	else return b;
}
double minValue(double a, double b) {//return a<b?a:b
	if (a < b) return a;
	else return b;
}
int main() {
	int i = 3, j = 4;
	cout << "min of " << i << " and " << j << " is " << minValue(i, j) << endl;
	double x = 3.5, y = 10;
	cout << "min of " << x << " and " << y << " is " << minValue(x, y) << endl;
}
*/

//����ת���ɣ� ģ�庯��
/*
#include <iostream>
using namespace std;
//���Զ��κ��ܱȽϴ�С(<)������ʹ�ø�ģ���ñ�����
//�Զ�����һ����Ը��������͵ľ��庯��
template<class TT>
TT minValue(TT a, TT b) {//return a<b?a:b
	if (a < b) return a;
	else return b;
}
int main() {
	int i = 3, j = 4;
	cout << "min of " << i << " and " << j << " is " << minValue(i, j) << endl;
	double x = 3.5, y = 10;
	cout << "min of " << x << " and " << y << " is " << minValue(x, y) << endl;
	//����,��ͬ���͵���ô�죿 // ������ 
//	cout << "min of " << i << " and " << y << " is " << minValue(i, y) << endl;
}
//���Զ��κ��ܱȽϴ�С(<)������ʹ�ø�ģ���ñ�����
//�Զ�����һ����Ը��������͵ľ��庯��
/*
*/
#include <iostream>
using namespace std;
template<class T1, class T2>
T1 minValue(T1 a, T2 b) {//return a<b?a:b
	if (a < b) return a;
	else return (T2)b; //ǿ��ת��ΪT1����
}
int main() {
	int i = 3, j = 4;
	cout << "min of " << i << " and " << j << " is " << minValue(i, j) << endl;
	double x = 3.5, y = 10;
	cout << "min of " << x << " and " << y << " is " << minValue(x, y) << endl;
	//����,��ͬ���͵���ô�죿
	cout << "min of " << i << " and " << y << " is " << minValue(i, y) << endl;
}

