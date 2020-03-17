/********************************************************************
    > File Name: builder.cpp
    > Author: zzp
    > Created Time: 2020年03月16日 星期一 23时47分31秒
 *******************************************************************/

#include<iostream>
using namespace std;

class House
{
public:
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setDoor(string door)
	{
		this->m_door = door;
	}
	void setWindow(string window)
	{
		this->m_window = window;
	}

	string getWall()
	{
		return m_wall;
	}
	string getDoor()
	{
		return m_door;
	}
	string getWindow()
	{
		return m_window;
	}

private:
	string m_wall;
	string m_door;
	string m_window;
};

class Builder
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
};

class FlatBuilder : public Builder
{
public:
	FlatBuilder()
	{
		m_house = new House;
	}
	virtual void buildWall()
	{
		m_house->setWall("flat wall");
	}
	virtual void buildDoor()
	{
		m_house->setDoor("flat door");
	}
	virtual void buildWindow()
	{
		m_house->setWindow("flat window");
	}
	virtual House* getHouse()
	{
		return m_house;
	}

private:
	House *m_house;
};

class VillaBuilder : public Builder
{
public:
	VillaBuilder()
	{
		m_house = new House;
	}
	virtual void buildWall()
	{
		m_house->setWall("villa wall");
	}
	virtual void buildDoor()
	{
		m_house->setDoor("villa door");
	}
	virtual void buildWindow()
	{
		m_house->setWindow("villa window");
	}
	virtual House* getHouse()
	{
		return m_house;
	}

private:
	House *m_house;
};

class Director
{
public:
	Director(Builder *build)
	{
		m_build = build;
	}

	void Construct()
	{
		m_build->buildWall();
		m_build->buildDoor();
		m_build->buildWindow();
	}

private:
	Builder* m_build;
};

int main()
{
	Builder* builder = new VillaBuilder;
	Director* director = new Director(builder);
	director->Construct();
	House* house = builder->getHouse();
	cout << house->getWall() << endl;
	cout << house->getDoor() << endl;
	cout << house->getWindow() << endl;
	delete builder;
	delete director;
	return 0;
}
