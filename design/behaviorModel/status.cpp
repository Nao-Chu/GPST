/********************************************************************
    > File Name: status.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 18时34分11秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Worker;

class State
{
public:
	virtual void doSomeThing(Worker *w) = 0;
};

class Worker
{
public:
	int getHour()
	{
		return m_hour;
	}
	void setHour(int hour)
	{
		m_hour = hour;
	}
	State* getCurrentState()
	{
		if (m_currstate == NULL)
		{
			return NULL;
		}
		return m_currstate;
	}
	void setCurrentState(State* state)
	{
		m_currstate = state;
	}
	void doSomeThing()
	{
		if (m_currstate != NULL)
		{
			m_currstate->doSomeThing(this);
		}
	}

private:
	int m_hour;
	State *m_currstate;
};

class State2 : public State
{
public:
	virtual void doSomeThing(Worker *w);
};
class State1 : public State
{
public:
	virtual void doSomeThing(Worker *w)
	{
		if(w->getHour() == 7 || w->getHour() == 8)
		{
			cout << "breakfast" << endl;
		}
		else
		{
			delete w->getCurrentState();
			w->setCurrentState(new State2);
			w->getCurrentState()->doSomeThing(w);
		}
	}
};

void State2::doSomeThing(Worker *w)
{
	if(w->getHour() == 7 || w->getHour() == 8)
	{
		delete w->getCurrentState();
		w->setCurrentState(new State1);
		w->getCurrentState()->doSomeThing(w);
	}
	else
	{
		cout << "play game" << endl;
	}
}

int main()
{
	Worker *w1 = new Worker;
	State  *s  = new State1;
	w1->setHour(7);
	w1->setCurrentState(s);
	w1->doSomeThing();

	w1->setHour(9);
	w1->doSomeThing();

	delete w1;

	return 0;
}
