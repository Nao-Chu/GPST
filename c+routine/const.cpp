#include <iostream>
using namespace std;

class A {
	int i;
public:
	A():i(0){}
	// f(A* this)
	void f() { cout << "f()" << endl; }
	// f(const A* this)
	void f() const { cout << "f() const " << endl; }
};

int main()
{
	// A类里面的东西必须要初始化
	const A a;
	A b;
	a.f();
	b.f();
	return 0;
}
