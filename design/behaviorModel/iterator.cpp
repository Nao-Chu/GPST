/********************************************************************
    > File Name: iterator.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 19时41分44秒
 *******************************************************************/

#include<iostream>
using namespace std;

#define SIZE 5
typedef int Object;

class MyIterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentIter() = 0;
};

class Aggregate
{
public:
	virtual MyIterator *CreateIterator() = 0;
	virtual Object getItem(int index) = 0;
	virtual Object getSize() = 0;

protected:
	Object object[SIZE];
};

class ConcreteIterator : public MyIterator
{
public:
	ConcreteIterator(Aggregate *ag)
	{
		_ag = ag;
		_current_index = 0;
	}
	virtual void First()
	{
		_current_index = 0;
	}
	virtual void Next()
	{
		if(_current_index < _ag->getSize())
		{
			_current_index++;
		}
	}
	virtual bool IsDone()
	{
		return (_current_index == _ag->getSize());
	}
	virtual Object CurrentIter()
	{
		return _ag->getItem(_current_index);
	}

private:
	int _current_index;
	Aggregate *_ag;
};

class ConcreateAggregate : public Aggregate
{
public:
	ConcreateAggregate() 
	{
		for (int i = 0; i < SIZE; i++)
		{
			object[i] = i+1;
		}
	}
	virtual MyIterator *CreateIterator()
	{
		return new ConcreteIterator(this); 
	}
	virtual Object getItem(int index)
	{
		return object[index];
	}
	virtual Object getSize()
	{
		return SIZE;
	}
};

int main()
{
	Aggregate  *ag = new ConcreateAggregate;
	MyIterator *it = ag->CreateIterator(); 
	for(;!it->IsDone();it->Next())
	{
		cout << it->CurrentIter() << " ";
	}
	return 0;
}
