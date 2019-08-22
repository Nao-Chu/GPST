//22. 类模板：我们可以将一个类变成“类模板”或“模板类”，正如一个模板函数一样。
//将原来的所有double换成模板类型T，并加上模板头 template<class T>
#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
class Array {
	T size;
	T *data;
public:
	Array(int s) {
		size = s;
		data = new T[s];
	}
	virtual ~Array() {
		delete[] data;
	}
	T &operator [] (int i) {
		if (i < 0 || i >= size) {
			cerr << endl << "Out of bounds" << endl;
			throw "index out of range";
		}
		else return data[i];
	}
};
int main() {
	Array<int> t(5);
	t[0] = 45; // OK
	t[4] = t[0] + 6; // OK
	cout << t[4] << endl; // OK
//	t[10] = 7; // error!
	Array<double> a(5);
	a[0] = 45.5; // OK
	a[4] = a[0] + 6.5; // OK
	cout << a[4] << endl; // OK
//	a[10] = 7.5; // error!
	return 0;
}
