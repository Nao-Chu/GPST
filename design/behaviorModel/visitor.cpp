/********************************************************************
    > File Name: visitor.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 18时17分47秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Visitor;
class ParkElement
{
public:
	virtual void accept(Visitor *visit) = 0;
	virtual void getName() = 0;
}; 

class Visitor
{
public:
	virtual void visit(ParkElement *parkelement) = 0;
};

class ParkA : public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);
	}
	virtual void getName()
	{
		cout << ": ParkA" << endl;
	}
};

class ParkB : public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);
	}
	virtual void getName()
	{
		cout << ": ParkB" << endl;
	}
};

class VisitorA : public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "VisitorA ";
		parkelement->getName();
	}
};

class VisitorB : public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "VisitorB ";
		parkelement->getName();
	}
};

int main()
{
	Visitor *A = new VisitorA;
	Visitor *B = new VisitorB;

	ParkElement *parkA = new ParkA;
	ParkElement *parkB = new ParkB;

	parkA->accept(A);
	parkA->accept(B);
	parkB->accept(B);
	parkB->accept(A);

	delete parkB;
	delete parkA;
	delete B;
	delete A;
	return 0;
}
