/*1. C++头文件不必是.h结尾，C语言中的标准库头文件如math.h,stdio.h在C++被命名为cmath,cstdio.
#include <cmath>
#include <cstdio>
int main(){
 double a = 1.2;
 a = sin (a);
 printf("%lf\n",a);
}*/
/*
 CC的多行注释`
 用于注释一块代码

#include <cmath>
#include <cstdio>
int main(){ //程序执行的入口，main主函数
 double a = 1.2; //定义一个变量a
 a = sin (a);
 printf("%lf\n",a); //用格式符%lf输出a: lf表示是double型
}
/*3. 名字空间namespace.
为防止名字冲突(出现同名),C++引入了名字空间( namespace)，
通过::运算符限定某个名字属于哪个名字空间*/
//如 “计算机1702”::“李平”
//如 “信计1603”::“李平”*/
#include <cstdio>
namespace first
{
	 int a;
	 void f(){/*...*/}
	 int g(){/*...*/}
}
namespace second
{
	 double a;
	 double f(){/*...*/}
	 char g;
}
int main ()
{
	 first::a = 2;
	 second::a = 6.453;
	 first::a = first::g()+second::f();
	 second::a = first::g()+6.453;
	 printf("%d\n",first::a);
	 printf("%lf\n",second::a);
	 return 0;
}
