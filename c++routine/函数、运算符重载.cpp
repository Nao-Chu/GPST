/*13. �������أ�C++������ͬ����ֻҪ���ǵ��ββ�һ��(�������Ӧ��������)��
���ú���ʱ������ʵ�κ��βε�ƥ��ѡ����Ѻ�����
����ж���������ֵ���Ѻ�������仯һ�𱨴�
ע�⣺���ܸ��ݷ�����������ͬ������*/
/*
#include <iostream>
using namespace std;
double add(double a, double b) {
	return a + b;
}
int add(int a, int b) {
	return a + b;
}
//���������޷�����int add (int a, int b),void add (int a, int b )
// �Ӹ�int c ��ok 
void add(int a, int b,int c) {
	c = a - b;
}
int main() {
	double m = 7.1, n = 4.1;
	int k = 5, p = 3;
	cout << add(m, n) << " , " << add(k, p) << endl;
	return 0;
}
*/

//14.���������
/*
#include <iostream>
using namespace std;
struct Vector2{
	 double x;
	 double y;
};
Vector2 operator * (double a, Vector2 b){
	Vector2 r;
	 r.x = a * b.x;
	 r.y = a * b.y;
	 return r;
}
Vector2 operator+ (Vector2 a, Vector2 b) {
	Vector2 r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	return r;
}
int main (){
	 Vector2 k, m; // C++�����struct����ǰ����Ҫ�ټӹؼ���struct: "struct vector"
	 k.x = 2; //�ó�Ա���������.���ʳ�Ա
	 k.y = -1; 
	 m = 3.1415927 * k; // Magic!
	 cout << "(" << m.x << ", " << m.y << ")" << endl;
	 Vector2 n = m + k;
	 cout << "(" << n.x << ", " << n.y << ")" << endl;
	 return 0;
}
*/

#include <iostream>
using namespace std;
struct Vector2 {
	 double x;
	 double y;
};

ostream& operator << (ostream& o, Vector2 a){
	 o << "(" << a.x << ", " << a.y << ")";
	 return o;
}
int main (){
	 Vector2 a;
	 a.x = 35;
	 a.y = 23;
	 cout << a << endl; // operator <<(cout,a);
	 return 0;
}

