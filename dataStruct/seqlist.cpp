/********************************************************************
    > File Name: seqlist.cpp
    > Author: zzp
    > Created Time: 2020年03月14日 星期六 16时43分03秒
 *******************************************************************/

#include<iostream>
using namespace std;

template <typename T>
class SeqList
{
public:
	SeqList(int capacity);
	~SeqList();

	int getLen();
	int getCapacity();

	int insert(T &t,int pos);
	int get(T &t,int pos);
	int del(T &t,int pos);
	void clear();

private:
	T *pArray;
	int len;
	int capacity;
};

template <typename T>
SeqList<T>::SeqList(int capacity)
{
	pArray = new T[capacity];	
	this->len = 0;
	this->capacity = capacity;
}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] pArray;
	pArray = NULL;
	len = 0;
	this->capacity = 0;
}

template <typename T>
int SeqList<T>::getLen()
{
	return this->len;
}

template <typename T>
int SeqList<T>::getCapacity()
{
	return this->capacity;
}

template <typename T>
int SeqList<T>::insert(T &t,int pos)
{
	int ret = 0;

	if (this->len > this->capacity)
	{
		ret = -1;
		return ret;
	}

	if (pos >= this->capacity || pos < 0)
	{
		ret = -2;
		return ret;
	}

	for (int i = this->len; i > pos; i--)
	{
		this->pArray[i] = this->pArray[i-1];
	}

	this->len++;
	this->pArray[pos] = t; 
	return ret;
}

template <typename T>
int SeqList<T>::get(T &t,int pos)
{
	int ret = 0;

	if (this->len <= pos)
	{
		ret = -2;
		return ret;
	}

	t = this->pArray[pos]; 
	return ret;
}

template <typename T>
int SeqList<T>::del(T &t,int pos)
{
	int ret = 0;
	if (this->len <= pos)
	{
		ret = -2;
		return ret;
	}
	t = this->pArray[pos]; 
	for (int i = pos; i < this->len; i++)
	{
		this->pArray[i] = this->pArray[i+1];
	}
	this->len--;
	return ret;
}

template <typename T>
void SeqList<T>::clear()
{
	delete[] pArray;
	pArray = NULL;
	pArray = new T[capacity];	
	this->len = 0;
	this->capacity = capacity;
}

class Teacher
{
public:
	int age;
};

int main()
{
	Teacher t1,t2,temp;
	SeqList<Teacher> list(10);	
	t1.age = 12;
	t2.age = 14;
	list.insert(t1,0);
	list.insert(t2,0);

	for (int i = 0; i < list.getLen(); i++)
	{
		list.get(temp,i);
		cout << temp.age << " ";
	}
	cout << endl;

	Teacher t3,t4;
	list.clear();
	t3.age = 2;
	t4.age = 4;
	list.insert(t3,0);
	list.insert(t4,0);

	while(list.getLen() > 0)
	{
		list.del(temp,0);
		cout << temp.age << " ";
	}
	cout << endl;
	return 0;
}
