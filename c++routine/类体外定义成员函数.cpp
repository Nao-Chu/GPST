//21. 类体外定义方法（成员函数），必须在类定义中声明，类体外要有类作用域，否则就是全局
//外部函数了！
#include <iostream>
using namespace std;
class Date {
	int d, m, y;
public:
	void print();
	Date(int dd = 1, int mm = 1, int yy = 1999) {
		d = dd; m = mm; y = yy;
		cout << "构造函数" << endl;
	}
	virtual ~Date() {//析构函数名是~和类名，且不带参数，没有返回类型
	//目前不需要做任何释放工作，因为构造函数没申请资源
		cout << "析构函数" << endl;
	}
};
void Date::print() {
	cout << y << "-" << m << "-" << d << endl;
}
int main() {
	Date day;
	day.print();
}
