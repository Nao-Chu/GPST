#include <iostream>
#include <stdlib.h>

using namespace std;

class A
{
	public:
		A(int len)
		{
			this->len = len;
			myarray = (int*)malloc(len*sizeof(int));
		}
		friend ostream& operator<<(ostream &out,A& myarray);
		friend istream& operator>>(istream &in,A& myarray);
	private:
		int *myarray;
		int len;

};

ostream& operator<<(ostream &out,A& myarray)
{
	for (int i =0; i < myarray.len;i++)
		out << i << ":" << myarray.myarray[i] << endl;  
	return out;
}

istream& operator>>(istream &in,A& myarray)
{
	cout << "Please " << myarray.len << " num"<<endl;
	for (int i =0; i < myarray.len;i++)
		in >> myarray.myarray[i];  
	return in;
}

int main()
{
	A a(10);
	cin >> a;
	cout << a;
	return 0;
}
