#include <iostream>

using namespace std;

class A{
public:
	A():i(0){cout << "A::A()" << endl;}
	~A(){ cout << "A::~A()" << endl;}
	void print(){cout << "A::f()" << i << endl;}
protected:
	void set (int ii){ i = ii; }
private:
	int i;
};

// B is A 的子类
class B : public A{
public:
	void f(){
		set(20);
//		i = 30;
		print();
	}
};

int main()
{
	B b;
//	b.set(10);
	b.f();
//	b.print();
	return 0;
}
