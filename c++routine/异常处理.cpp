/*10.���ڲ�����ѭ���ļ򵥺�����������inline�ؼ������� Ϊ"inline��������"��
���������������������������չ������Ϊ������չ���������⺯�����ÿ�����
��߳���ִ��Ч��*/
/*
#include <iostream>
#include <cmath>
using namespace std;
inline double distance(double a, double b) {
	return sqrt(a * a + b * b);
}
int main() {
	double k = 3, m = 4;
	// ����2�н�����ͬ���Ĵ���:
	cout << distance(k, m) << endl;
	cout << sqrt(k * k + m * m) << endl;
	return 0;
}*/

//11. ͨ�� try-catch�����쳣���,�����������try�飬catch�в���try���׳����쳣

#include <iostream>
#include <cmath>
using namespace std;
int main (){
	 int a, b;
	 cout << "Type a number: ";
	 cin >> a;
	 cout << endl;
	 /*
	 //10 < a < 100; three  =>> else 5
	 try {
		 if (a > 100) throw 100;
		 if (a < 10) throw 10;
		 throw '!';
	 }
	 catch (int result) {
		 cout << "Result is: " << result << endl;
		 b = result + 1;
	 }
	 catch (char s) {
		 cout << "haha" << s << endl;
		 b = s + 1;
		 }
	 
	 cout << "b contains: " << b << endl;
	 cout << endl;
	 */
	 // another example of exception use:
	 
	 char zero[] = "zero";
	 char pair[] = "pair";
	 char notprime[] = "not prime";
	 char prime[] = "prime";
	 try {
		 if (a == 0) throw zero;
		 if ((a / 2) * 2 == a) throw pair;
		 for (int i = 3; i <= sqrt (a); i++){
			 if ((a / i) * i == a) throw notprime;
		 }
		 throw prime;
	 }
	 catch (char *conclusion) {
	 	cout << "�쳣����ǣ� " << conclusion << endl;
	 }
	 catch (...) {
	 	cout << "�����쳣����������ﲶ�� " << endl;
	 }
	 cout << endl;
	 return 0; 
 }

