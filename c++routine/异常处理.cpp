/*10.对于不包含循环的简单函数，建议用inline关键字声明 为"inline内联函数"，
编译器将内联函数调用用其代码展开，称为“内联展开”，避免函数调用开销，
提高程序执行效率*/
/*
#include <iostream>
#include <cmath>
using namespace std;
inline double distance(double a, double b) {
	return sqrt(a * a + b * b);
}
int main() {
	double k = 3, m = 4;
	// 下面2行将产生同样的代码:
	cout << distance(k, m) << endl;
	cout << sqrt(k * k + m * m) << endl;
	return 0;
}*/

//11. 通过 try-catch处理异常情况,正常代码放在try块，catch中捕获try块抛出的异常

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
	 	cout << "异常结果是： " << conclusion << endl;
	 }
	 catch (...) {
	 	cout << "其他异常情况都在这里捕获 " << endl;
	 }
	 cout << endl;
	 return 0; 
 }

