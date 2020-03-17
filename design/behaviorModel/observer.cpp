/********************************************************************
    > File Name: observer.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 01时13分00秒
 *******************************************************************/

#include<iostream>
#include<list>
using namespace std;

class Secretary;
class PlayserObserver
{
public:
	PlayserObserver(Secretary * secretary)
	{
		m_secretary = secretary;
	}
	void update(string action)
	{
		cout << "message:" << action << endl;
	}

private:
	Secretary *m_secretary;
};

class Secretary
{
public:
	Secretary()
	{
		m_list.clear();
	}
	void Notify(string info)
	{
		list<PlayserObserver *> ::iterator it;
		for (it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->update(info);
		}
	}
	void setPlayserObserver(PlayserObserver *o)
	{
		m_list.push_back(o);
	}

private:
	list<PlayserObserver *> m_list;
};

int main()
{
	Secretary *secretary = new Secretary;
	PlayserObserver *po1 = new PlayserObserver(secretary);
	PlayserObserver *po2 = new PlayserObserver(secretary);
	secretary->setPlayserObserver(po1);
	secretary->setPlayserObserver(po2);
	secretary->Notify("boos come in");
	secretary->Notify("boos leave");
	return 0;
}
