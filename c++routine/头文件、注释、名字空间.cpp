/*1. C++ͷ�ļ�������.h��β��C�����еı�׼��ͷ�ļ���math.h,stdio.h��C++������Ϊcmath,cstdio.
#include <cmath>
#include <cstdio>
int main(){
 double a = 1.2;
 a = sin (a);
 printf("%lf\n",a);
}*/
/*
 CC�Ķ���ע��`
 ����ע��һ�����

#include <cmath>
#include <cstdio>
int main(){ //����ִ�е���ڣ�main������
 double a = 1.2; //����һ������a
 a = sin (a);
 printf("%lf\n",a); //�ø�ʽ��%lf���a: lf��ʾ��double��
}
/*3. ���ֿռ�namespace.
Ϊ��ֹ���ֳ�ͻ(����ͬ��),C++���������ֿռ�( namespace)��
ͨ��::������޶�ĳ�����������ĸ����ֿռ�*/
//�� �������1702��::����ƽ��
//�� ���ż�1603��::����ƽ��*/
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
