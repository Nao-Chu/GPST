//9.C++�����ˡ��������͡�����һ����������һ�������ı���
/*
#include <iostream>
using namespace std;
int main ()
{
 double a = 3.1415927;
 double &b = a; // b �� a�ı�����b����a
 b = 89; //Ҳ����a���ڴ��ֵΪ89
 cout << "a contains: " << a << endl; // Displays 89.
 a = 80;
 cout << "b contains: " << b << endl; // a and b is same
 return 0;
}
*//*
//���þ��������������βΣ���ʾ�βκ�ʵ��ʵ������ͬһ�������ں����ж��βε��޸�Ҳ���Ƕ�ʵ�ε��޸�
#include <iostream>
using namespace std;
void swap(int x, int y) {
cout << "swap�����ڽ���ǰ��" << x << " " << y << endl;
int t = x; x = y; y = t;
cout << "swap�����ڽ�����" << x << " " << y << endl;
}
int main(){
int a = 3, b = 4;
swap(a, b);
cout << a << ", " << b << endl; // Displays 100, 4.
return 0;
}
*/
//x,y�õ�2��int�ͱ�����ָ��,x,y����û���޸�,�޸ĵ���x,y ָ�����2��int�ͱ���������
 /*
void swap(int *x, int *y) {
cout << "swap�����ڽ���ǰ��" << *x << " " << *y << endl;
int t = *x; *x = *y; *y = t;
cout << "swap�����ڽ�����" << *x << " " << *y << endl;
}
int main() {
int a = 3, b = 4;
swap(&a, &b); // &a��ֵ��x,&b��ֵ��y,
 //x,y�ֱ���int*ָ�룬ָ��a,b
 //*x, *y����a��b
cout << a << ", " << b << endl; // Displays 100, 4.
return 0;
}*/
//x,y��ʵ�ε�����
/*
#include <iostream>
using namespace std;
void swap(int &x, int &y) {
cout << "swap�����ڽ���ǰ��" << x << " " << y << endl;
int t = x; x = y; y = t;
cout << "swap�����ڽ�����" << x << " " << y << endl;
}
int main(){
int a = 3, b = 4;
swap(a, b); //x,y���ֱ���a,b�����ã���x����a,y����b
cout << a << ", " << b << endl; // Displays 100, 4.
return 0;
}*/
//��ʵ��ռ���ڴ��ʱ�������ô��洫ֵ����Ҫ���ƣ������Ч�ʣ�
//�����ϣ������������޸�ʵ�Σ�������const�޸ķ�����

#include <iostream>
using namespace std;
void change (double &x, const double &y,double z){
 x = 100;
 //y = 200; //�� y�����޸ģ���const double &
 z = 300;
}
int main (){
 double a=0.0,b=0.0,c=0.0;//�������ͱ���δ�ṩ��ʼ��ʽ��Ĭ�ϳ�ʼ��Ϊ0
 change(a, b, c);
 cout << a << ", " << b << ", " << c << endl; // Displays 100, 4.
 return 0;
}

