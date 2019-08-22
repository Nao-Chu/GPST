/*17. 类：是在C的struct类型上，增加了“成员函数”。
C的strcut可将一个概念或实体的所有属性组合在一起，描述同一类对象的共同属性，
C++使得struct不但包含数据，还包含函数(方法)用于访问或修改类变量(对象)的这些属性。*/
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
	day.print(); //通过类Date对象day调用类Date的print方法
	day.init(4, 6, 1999); //通过类Date对象day调用类Date的init方法
	day.print(); //通过类Date对象day调用类Date的print方法
	return 0;
}
*/
// 成员函数 返回 “自引用” （*this）
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
	// 有多少个对象。*this指针就返回多少个对象 
	//this是指向调用这个函数的类型对象指针，
 	// *this就是调用这个函数的那个对象
	//这个成员函数返回的是“自引用”，即调用这个函数的对象本身
	//通过返回自引用，可以连续调用这个函数
 	// day.add(3);
 	// day.add(3).add(7);}
	
int main() {
	Date day;
	day.print(); //通过类Date对象day调用类Date的print方法
	day.init(4, 6, 1999); //通过类Date对象day调用类Date的init方法
	day.print(); //通过类Date对象day调用类Date的print方法
	day.init(4, 6, 2000);
	day.print();
	day.add(3);
	day.add(5).add(7);
	day.print();
	return 0;
}
*/
//成员函数重载“运算符函数” 
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
	day.print(); //通过类Date对象day调用类Date的print方法
	day.init(4, 6, 1999); //通过类Date对象day调用类Date的init方法
	day.print(); //通过类Date对象day调用类Date的print方法
	day += 3; // day.add(3);
	(day += 5) += 7; //day.add(5).add(7);
	day.print();
	return 0;
}

