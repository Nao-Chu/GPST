#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
public:
	MyVector(int size);
	MyVector(const MyVector &obj);
	~MyVector();

public:
	T& operator[](int index);
	friend ostream & operator<< (ostream &out, const MyVector &obj)
	{
		for (int i = 0; i < obj.m_len; i++)
		{
			out << obj.m_space[i] << " ";
			if ((i+1) % 5 == 0)
				out << endl;
		}
		return out;
	}
	MyVector<T>& operator=(const MyVector &obj);
	int size();

private:
	int *m_space;
	int m_len;
};
