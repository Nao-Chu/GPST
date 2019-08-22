//28. 纯虚函数（pure virtual function ）和抽象类(abstract base class)
//函数体=0的虚函数称为“纯虚函数”。包含纯虚函数的类称为“抽象类”
#include <string>
class Animal // This Animal is an abstract base class
{
protected:
	std::string m_name;
public:
	Animal(std::string name)
	: m_name(name)
	{ }
	std::string getName() { return m_name; }
	virtual const char* speak() = 0; // note that speak is now a pure virtual 
	function
};
int main() {
	Animal a; //错：抽象类不能实例化(不能定义抽象类的对象(变量))
}
//从抽象类派生的类型如果没有继承实现所有的纯虚函数，则仍然是“抽象类”
#include <iostream>
class Cow : public Animal
{
	public:
	Cow(std::string name): Animal(name)
	{
	}
// We forgot to redefine speak
};
int main(){
	Cow cow("Betsy"); //仍然错：因为Cow仍然是抽象类
	std::cout << cow.getName() << " says " << cow.speak() << '\n';
}
像下面这样实现所有纯虚函数就没问题了，Cow不是一个抽象类
#include <iostream>
class Cow : public Animal
{
public:
Cow(std::string name)
: Animal(name)
{
}
virtual const char* speak() { return "Moo"; }
};
int main()
{
Cow cow("Betsy");
std::cout << cow.getName() << " says " << cow.speak() << '\n';
}
