#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class A
{
	public:
		A()
		{
			this->len = len;
			mystring = (char*)malloc(10*sizeof(char));
		}
		friend ostream& operator<<(ostream &out,A& mystring);
		friend istream& operator>>(istream &in,A& mystring);
		bool operator>(A& mystring)
		{
			if (strcmp(this->mystring,mystring.mystring) > 0)
			return true;
			return false;
		}
		bool operator<(A& mystring)
		{
			if (strcmp(this->mystring,mystring.mystring) < 0)
			return true;
			return false;
		}
		bool operator==(A& mystring)
		{
			if (strcmp(this->mystring,mystring.mystring) == 0)
			return true;
			return false;
		}
		bool operator!=(A& mystring)
		{
			if (strcmp(this->mystring,mystring.mystring) != 0)
			return true;
			return false;
		}
	private:
		char *mystring;
		int len;

};

ostream& operator<<(ostream &out,A& mystring)
{
	out << mystring.mystring << endl;  
	return out;
}

istream& operator>>(istream &in,A& mystring)
{
	in >> mystring.mystring;  
	return in;
}

int main()
{
	A a;
	A b;
	cin >> a;
	cin >> b;
	if (a>b)
		cout << "a>b" << endl;
	else if (a<b)
		cout << "a<b" << endl;
	if (a==b)
		cout << "a=b" << endl;
	else if (a!=b)
		cout << "a!=b" << endl;
	return 0;
}
