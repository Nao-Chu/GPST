//9.C++引入了“引用类型”，即一个变量是另一个变量的别名
/*
#include <iostream>
using namespace std;
int main ()
{
 double a = 3.1415927;
 double &b = a; // b 是 a的别名，b就是a
 b = 89; //也就是a的内存块值为89
 cout << "a contains: " << a << endl; // Displays 89.
 a = 80;
 cout << "b contains: " << b << endl; // a and b is same
 return 0;
}
*//*
//引用经常用作函数的形参，表示形参和实参实际上是同一个对象，在函数中对形参的修改也就是对实参的修改
#include <iostream>
using namespace std;
void swap(int x, int y) {
cout << "swap函数内交换前：" << x << " " << y << endl;
int t = x; x = y; y = t;
cout << "swap函数内交换后：" << x << " " << y << endl;
}
int main(){
int a = 3, b = 4;
swap(a, b);
cout << a << ", " << b << endl; // Displays 100, 4.
return 0;
}
*/
//x,y得到2个int型变量的指针,x,y本身没有修改,修改的是x,y 指向的那2个int型变量的内容
 /*
void swap(int *x, int *y) {
cout << "swap函数内交换前：" << *x << " " << *y << endl;
int t = *x; *x = *y; *y = t;
cout << "swap函数内交换后：" << *x << " " << *y << endl;
}
int main() {
int a = 3, b = 4;
swap(&a, &b); // &a赋值给x,&b赋值给y,
 //x,y分别是int*指针，指向a,b
 //*x, *y就是a和b
cout << a << ", " << b << endl; // Displays 100, 4.
return 0;
}*/
//x,y是实参的引用
/*
#include <iostream>
using namespace std;
void swap(int &x, int &y) {
cout << "swap函数内交换前：" << x << " " << y << endl;
int t = x; x = y; y = t;
cout << "swap函数内交换后：" << x << " " << y << endl;
}
int main(){
int a = 3, b = 4;
swap(a, b); //x,y将分别是a,b的引用，即x就是a,y就是b
cout << a << ", " << b << endl; // Displays 100, 4.
return 0;
}*/
//当实参占据内存大时，用引用代替传值（需要复制）可提高效率，
//如果不希望因此无意中修改实参，可以用const修改符。如

#include <iostream>
using namespace std;
void change (double &x, const double &y,double z){
 x = 100;
 //y = 200; //错！ y不可修改，是const double &
 z = 300;
}
int main (){
 double a=0.0,b=0.0,c=0.0;//内在类型变量未提供初始化式，默认初始化为0
 change(a, b, c);
 cout << a << ", " << b << ", " << c << endl; // Displays 100, 4.
 return 0;
}

