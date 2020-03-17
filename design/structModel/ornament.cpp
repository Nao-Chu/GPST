/********************************************************************
    > File Name: ornament.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 15时00分05秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};

class RunCar : public Car
{
public:
	RunCar(Car *car)
	{
		m_car = (car != NULL) ? car : NULL;
	}
	virtual void show()
	{
		if (m_car != NULL)
		{
			m_car->show();
		}
		cout << "can run" << endl;
	}

private:
	Car *m_car;
};

class SwimCar : public Car
{
public:
	SwimCar(Car *car)
	{
		m_car = (car != NULL) ? car : NULL;
	}
	virtual void show()
	{
		if (m_car != NULL)
		{
			m_car->show();
		}
		cout << "can swim" << endl;
	}

private:
	Car *m_car;
};

class FlyCar : public Car
{
public:
	FlyCar(Car *car)
	{
		m_car = (car != NULL) ? car : NULL;
	}
	virtual void show()
	{
		if (m_car != NULL)
		{
			m_car->show();
		}
		cout << "can fly" << endl;
	}

private:
	Car *m_car;
};

class CarCar : public Car
{
public:
	CarCar(Car *car)
	{
		m_car = (car != NULL) ? car : NULL;
	}
	virtual void show()
	{
		if (m_car != NULL)
		{
			m_car->show();
		}
	}

private:
	Car *m_car;
};

int main()
{
	Car *mycar = NULL; 
	RunCar *runcar = new RunCar(mycar);
	FlyCar *flycar = new FlyCar(runcar);
	SwimCar *swimcar = new SwimCar(flycar);
	CarCar *carcar = new CarCar(swimcar);
	carcar->show();
	return 0;
}
