#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
void myswap(T &a,T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename T>
void print(T a,T b)
{
	cout << "a : " << a << ".b : " << b <<endl;
}
int main(int argc,char **argv)
{
	if(argc != 3)
	{
		cout << "please input two argu " << endl;
		return -1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	print<int>(a,b);
	myswap<int>(a,b);
	print<int>(a,b);
	return 0;
}
