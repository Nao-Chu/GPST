//15. 模板template函数：厌倦了对每种类型求最小值
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

//可以转化成： 模板函数
/*
#include <iostream>
using namespace std;
//可以对任何能比较大小(<)的类型使用该模板让编译器
//自动生成一个针对该数据类型的具体函数
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
	//但是,不同类型的怎么办？ // 报错呗 
//	cout << "min of " << i << " and " << y << " is " << minValue(i, y) << endl;
}
//可以对任何能比较大小(<)的类型使用该模板让编译器
//自动生成一个针对该数据类型的具体函数
/*
*/
#include <iostream>
using namespace std;
template<class T1, class T2>
T1 minValue(T1 a, T2 b) {//return a<b?a:b
	if (a < b) return a;
	else return (T2)b; //强制转化为T1类型
}
int main() {
	int i = 3, j = 4;
	cout << "min of " << i << " and " << j << " is " << minValue(i, j) << endl;
	double x = 3.5, y = 10;
	cout << "min of " << x << " and " << y << " is " << minValue(x, y) << endl;
	//但是,不同类型的怎么办？
	cout << "min of " << i << " and " << y << " is " << minValue(i, y) << endl;
}

