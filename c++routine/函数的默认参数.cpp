//12. Ĭ���βΣ� �������βοɴ���Ĭ��ֵ������һ�������ұ�
#include <iostream>
using namespace std;
double test(double a, double b = 7) {
	return a - b; 
}
// ��Ĭ��ֵ��һ������ 
double test1(double a, double b = 7, int c=100) {
	return a - b;
}
int main() {
	cout << test(14, 5) << endl;
	cout << test(14) << endl;
	cout << test1(14) << endl;
	return 0;
	}
	/*�� Ĭ�ϲ���һ�ɿ���*/
	

