#include <iostream>
using namespace std;

static int objectCount = 0;

class HowMany{
public:
	HowMany(){ objectCount++; print("HowMany()"); }
	HowMany(int i) { objectCount++;print("HowMany(int)"); }
	HowMany(const HowMany& o){ objectCount++;print("HowMany(HowMany)"); }
	void print(const string& msg = ""){
		if(msg.size() != 0) cout << msg << ": ";
		cout << "objectCount = " << objectCount << endl;
	}
	~HowMany() {
		objectCount--;
		print("~HowMany()");
	}
};

HowMany f(HowMany x) {
	cout << "begin of f " << endl;
	x.print("x argument inside f()");
	cout << "end of f" << endl;
	return x;
}

int main()
{
	HowMany h;
	h.print("after construction of h");
	HowMany h2 = f(h);
	h.print("after call to f()");
	return 0;	
}
