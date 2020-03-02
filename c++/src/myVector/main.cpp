#include <iostream>
#include "MyVector.cpp"

using namespace std;

int main()
{
	MyVector<int> myv1(10);
	for (int i = 0; i < myv1.size();i++)
	{
		myv1[i] = i+1;
	}
	cout << myv1 << " ";
	
	MyVector<int> myv2 = myv1;
	for (int i = 0; i < myv2.size();i++)
	{
		myv2[i] = i+1;
	}
	cout << myv2 << " ";
	return 0;
}
