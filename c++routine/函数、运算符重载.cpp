/*13. 函数重载：C++允许函数同名，只要它们的形参不一样(个数或对应参数类型)，
调用函数时将根据实参和形参的匹配选择最佳函数，
如果有多个难以区分的最佳函数，则变化一起报错！
注意：不能根据返回类型区分同名函数*/
/*
#include <iostream>
using namespace std;
double add(double a, double b) {
	return a + b;
}
int add(int a, int b) {
	return a + b;
}
//错：编译器无法区分int add (int a, int b),void add (int a, int b )
// 加个int c 就ok 
void add(int a, int b,int c) {
	c = a - b;
}
int main() {
	double m = 7.1, n = 4.1;
	int k = 5, p = 3;
	cout << add(m, n) << " , " << add(k, p) << endl;
	return 0;
}
*/

//14.运算符重载
/*
#include <iostream>
using namespace std;
struct Vector2{
	 double x;
	 double y;
};
Vector2 operator * (double a, Vector2 b){
	Vector2 r;
	 r.x = a * b.x;
	 r.y = a * b.y;
	 return r;
}
Vector2 operator+ (Vector2 a, Vector2 b) {
	Vector2 r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	return r;
}
int main (){
	 Vector2 k, m; // C++定义的struct类型前不需要再加关键字struct: "struct vector"
	 k.x = 2; //用成员访问运算符.访问成员
	 k.y = -1; 
	 m = 3.1415927 * k; // Magic!
	 cout << "(" << m.x << ", " << m.y << ")" << endl;
	 Vector2 n = m + k;
	 cout << "(" << n.x << ", " << n.y << ")" << endl;
	 return 0;
}
*/

#include <iostream>
using namespace std;
struct Vector2 {
	 double x;
	 double y;
};

ostream& operator << (ostream& o, Vector2 a){
	 o << "(" << a.x << ", " << a.y << ")";
	 return o;
}
int main (){
	 Vector2 a;
	 a.x = 35;
	 a.y = 23;
	 cout << a << endl; // operator <<(cout,a);
	 return 0;
}

