/********************************************************************
    > File Name: template.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 22时13分43秒
 *******************************************************************/

#include<iostream>
using namespace std;

class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;
	void Make()
	{
		MakeHead();
		MakeTail();
		MakeBody();
	}
};

class Jeep : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "Jeep Head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "Jeep Body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "Jeep Tail" << endl;
	}
};

class BWM : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "BWM Head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "BWM Body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "BWM Tail" << endl;
	}
};

class Design 
{
public:
	Design(MakeCar* car)
	{
		car->Make();
	}
};

int main()
{
	MakeCar *car = new BWM;
//	Design *design = new Design(car);
	car->Make();	
	return 0;
}
