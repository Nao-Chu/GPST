/********************************************************************
    > File Name: responsibility.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 00时03分19秒
 *******************************************************************/

#include<iostream>
using namespace std;

class CarHandle
{
public:
	virtual void HandleCar() = 0;
	void setNextHandle(CarHandle *handle)
	{
		m_handle = handle;
	}

protected:
	CarHandle *m_handle;
};

class HeadCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "Head handleCar" << endl;
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};

class BodyCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "Body handleCar" << endl;
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};

class TailCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "Tail handleCar" << endl;
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};

int main()
{
	CarHandle *headHandle = new HeadCarHandle;
	CarHandle *bodyHandle = new BodyCarHandle;
	CarHandle *tailHandle = new TailCarHandle;

	headHandle->setNextHandle(bodyHandle);	
	bodyHandle->setNextHandle(tailHandle);	
	tailHandle->setNextHandle(NULL);	
	headHandle->HandleCar();

	delete headHandle;
    delete bodyHandle;
	delete tailHandle;
	return 0;
}
