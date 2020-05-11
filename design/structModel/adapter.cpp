/********************************************************************
    > File Name: adapter.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 15时23分59秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Current18v
{
public:
	virtual void useCurrent18v() = 0;
};

class Current220v
{
public:
	virtual void useCurrent18v()
	{
		cout << "220v" << endl;
	}
};

class Adapter : public Current18v
{
public:
	Adapter(Current220v *current)
	{
		m_current = current;
	}
	virtual void useCurrent18v()
	{
		m_current->useCurrent18v();
	}

private:
	Current220v *m_current;
};

int main()
{
	Current220v *current220v = new Current220v;
	Current18v *adapter = new Adapter(current220v);
	adapter->useCurrent18v();
	return 0;
}
