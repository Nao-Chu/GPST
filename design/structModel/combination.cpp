/********************************************************************
    > File Name: combination.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 17时48分27秒
 *******************************************************************/

#include<iostream>
#include<list>
using namespace std;

class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *> *getChild() = 0;
};

class File : public IFile
{
public:
	File(string name)
	{
		m_name = name;
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		return -1;
	}
	virtual int remove(IFile *ifile)
	{
		return 0;
	}
	virtual list<IFile *> *getChild()
	{
		return NULL;
	}

private:
	string m_name;
};

class Dir : public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile *> *getChild()
	{
		return m_list;
	}

private:
	string m_name;
	list<IFile *> *m_list;
};

void imshow(IFile *file,int level)
{
	if (file == NULL)	
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		cout << "\t";
	}
	file->display();
	list<IFile *> *mylist = file->getChild();
	if (mylist == NULL)
	{
		return;
	}
	for(list<IFile*> ::iterator it = mylist->begin(); it != mylist->end(); it++)
	{
		imshow((*it),level+1);
	}
}

int main()
{
	Dir *root = new Dir("C");
	Dir  *dir1 = new Dir("git");
	Dir  *dir2 = new Dir("qt");
	File *file = new File("readme.md");
	File *file1 = new File("my.cpp");
	list<IFile *> *mylist = root->getChild();
	root->add(dir1);
	root->add(dir2);
	dir1->add(file);
	dir1->add(file1);

	imshow(root,0);
}
