//12. 默认形参： 函数的形参可带有默认值。必须一律在最右边
#include <iostream>
using namespace std;
double test(double a, double b = 7) {
	return a - b; 
}
// 带默认值的一定靠右 
double test1(double a, double b = 7, int c=100) {
	return a - b;
}
int main() {
	cout << test(14, 5) << endl;
	cout << test(14) << endl;
	cout << test1(14) << endl;
	return 0;
	}
	/*错： 默认参数一律靠右*/
	

