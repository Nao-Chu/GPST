#include <iostream>

using namespace std;

class A{
public:
	A() : i(10) {}
	virtual void f() { cout << "A::f() " << i << endl; }

	int i;
};

class B : public A{
public:
	B() : j(10) {}
	virtual void f() { cout << "B::f() " << j << endl; }

	int j;
};

int main()
{
	A a;
	B b;

	A* p = &b;
	p->f();

	a = b;

	p = &a;
	p->f();
	
	return 0;
}
