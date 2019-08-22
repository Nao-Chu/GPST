//22. ��ģ�壺���ǿ��Խ�һ�����ɡ���ģ�塱��ģ���ࡱ������һ��ģ�庯��һ����
//��ԭ��������double����ģ������T��������ģ��ͷ template<class T>
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
