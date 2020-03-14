/********************************************************************
    > File Name: linklist.cpp
    > Author: zzp
    > Created Time: 2020年03月14日 星期六 19时54分04秒
 *******************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

template <typename T>
struct Node
{
	T t;
	Node<T> *next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();

	int getLen();

	int insert(T &t,int pos);
	int get(T &t,int pos);
	int del(T &t,int pos);
	void clear();

private:
	Node<T> *head;
	int len;
};

template <typename T>
LinkList<T>::LinkList()
{
	head = new Node<T>;
	head->next = NULL;
	this->len = 0;
}

template <typename T>
LinkList<T>::~LinkList()
{
	Node<T> *tmp = NULL;

	while(head != NULL)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	this->len = 0;
	head = NULL;
}

template <typename T>
int LinkList<T>::getLen()
{
	return this->len;
}

template <typename T>
int LinkList<T>::insert(T &t,int pos)
{
	int ret = 0;
	if (pos < 0)
	{
		ret = -1;
		return ret;
	}

	Node<T> *current = NULL;
	current = head;
	for (int i = 0; i <pos && current->next != NULL; i++)
	{
		current = current->next;
	}

	Node<T> *node = new Node<T>;
	node->t = t;
	node->next = NULL;

	node->next = current->next;
	current->next = node;

	this->len++;

	return ret;
}

template <typename T>
int LinkList<T>::get(T &t,int pos)
{
	int ret = 0;

	if (this->len <= pos)
	{
		ret = -2;
		return ret;
	}

	Node<T> *current = NULL;
	current = head;
	for (int i = 0; i <=pos && current->next != NULL; i++)
	{
		current = current->next;
	}
	t = current->t; 
	return ret;
}

template <typename T>
int LinkList<T>::del(T &t,int pos)
{
	int ret = 0;
	if (this->len <= pos)
	{
		ret = -2;
		return ret;
	}

	Node<T> *current = NULL;
	current = head;
	for (int i = 0; i <pos && current->next != NULL; i++)
	{
		current = current->next;
	}
	Node<T> *next = NULL;
	next = current->next;
	t = next->t;

	current->next = next->next; 

	this->len--;
	delete next;

	return ret;
}

template <typename T>
void LinkList<T>::clear()
{
	Node<T> *tmp = NULL;
	while(head != NULL)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	head = new Node<T>;
	head->next = NULL;
	this->len = 0;
}

class Teacher
{
public:
	int age;
	char name[64];
	char *pdes;
	Teacher()
	{
		pdes = new char(100);
		memset(name,0,sizeof(char));
		age = 0;
	}

	Teacher(Teacher &t2)
	{
		pdes = new char(100);
		strcpy(this->pdes,t2.pdes);
		strcpy(this->name,t2.name);
		age = t2.age;
	}

	~Teacher()
	{
		if (pdes != NULL)
		{
			delete pdes;
			pdes = NULL;
		}
	}

	Teacher& operator=(const Teacher &t2)
	{
		if (pdes != NULL)
		{
			delete pdes;
			pdes = NULL;
		}
		
		pdes = new char(100);
		strcpy(this->pdes,t2.pdes);
		strcpy(this->name,t2.name);
		age = t2.age;
		return *this;
	}
};

int main()
{
	Teacher t1,t2,p1,temp;
	LinkList<Teacher> list;	
	t1.age = 12;
	strcpy(t1.pdes,"t1");
	t2.age = 14;
	strcpy(t2.pdes,"t2");
	p1.age = 19;
	strcpy(p1.pdes,"p1");
	list.insert(t1,0);
	list.insert(t2,0);
	list.insert(p1,0);
	for (int i = 0; i < list.getLen(); i++)
	{
		list.get(temp,i);
		cout << temp.age << " " << temp.pdes << endl;
	}

	list.clear();
	Teacher t3,t4;
	t3.age = 2;
	strcpy(t3.pdes,"t3");
	t4.age = 4;
	strcpy(t4.pdes,"t4");
	list.insert(t3,0);
	list.insert(t4,0);

	while(list.getLen() > 0)
	{
		list.del(temp,0);
		cout << temp.age << " " << temp.pdes << endl;
	}
	return 0;
}
