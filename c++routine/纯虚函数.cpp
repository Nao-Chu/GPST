//28. ���麯����pure virtual function ���ͳ�����(abstract base class)
//������=0���麯����Ϊ�����麯�������������麯�������Ϊ�������ࡱ
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
	Animal a; //�������಻��ʵ����(���ܶ��������Ķ���(����))
}
//�ӳ������������������û�м̳�ʵ�����еĴ��麯��������Ȼ�ǡ������ࡱ
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
	Cow cow("Betsy"); //��Ȼ����ΪCow��Ȼ�ǳ�����
	std::cout << cow.getName() << " says " << cow.speak() << '\n';
}
����������ʵ�����д��麯����û�����ˣ�Cow����һ��������
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
