//�Ѵ洢��
/*16. ��̬�ڴ���䣺 �ؼ��� new �� delete ��C���Ե�malloc/alloc/realloc��free���ã�
���Զ��������ó�ʼ�����캯����������������*/
#define _CRT_SECURE_NO_WARNINGS //windows
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	double d = 3.14; // ����d��һ����doubleֵ���ڴ��
	double *dp; // ָ�����dp������double���͵ĵ�ַ�ı���
	dp = &d; //ȡ��ַ�����&���ڻ��һ�������ĵ�ַ��
	*dp = 4.14; //�����������*���ڻ��ָ�����ָ����Ǹ�����(C++��Ҳ��Ϊ����)
 //*dp����dpָ����Ǹ�d
	cout << "*dp= " << *dp << " d=:" << d << endl;
	cout << "Type a number: ";
	cin >> *dp; //���dpָ���double�ڴ���ֵ
	cout << "*dp= " << *dp << " d=:" << d << endl;
	dp = new double; // new ������������doubleֵ���ڴ�飨��4��8���ֽڣ�
	 // ����������ڴ��ĵ�ַ�����ҵ�ַ��������double *
	 //�����ַ��������dp�У�dpָ��������ڴ�飬������ԭ��d�Ǹ��ڴ����
	 // ��Ŀǰ����ڴ���ֵ��δ֪��
	 // ע�⣺
	 // new ������ǶѴ洢�ռ䣬�����г���ͬӵ�е������ڴ�ռ�
	 //��d,dp�Ⱦֲ������������������ľ�̬�洢�ռ�
	 // new������doubleԪ�ص���double���͵Ĺ��캯������ʼ���������ʼ��Ϊ0
	*dp = 45.3; //*dpָ���double�ڴ���ֵ���45.3
	cout << "*dp= " << *dp << " d=:" << d << endl;
	cout << "Type a number: ";
	cin >> *dp; //���dpָ���double�ڴ���ֵ
	cout << "*dp= " << *dp << endl;
	*dp = *dp + 5; //�޸�dpָ���double�ڴ���ֵ45.3+5
	cout << "*dp= " << *dp << endl;
	delete dp; // delete �ͷ�dpָ��Ķ�̬�����double�ڴ��
	dp = new double[5]; //new �����˿��Դ��15��doubleֵ���ڴ��
	 //������������ڴ����ʼ��ַ������ָ��������
	 //double *�� ʵ���ǵ�һ��doubleԪ�صĵ�ַ
	 // new���ÿ��doubleԪ�ص���double���͵Ĺ��캯������ʼ���������ʼ��Ϊ0
	dp[0] = 4456; // dp[0]�ȼ��� *(dp+0)��*dp��Ҳ���ǵ�1��doubleԪ�ص��ڴ��
	dp[1] = dp[0] + 567; // dp[1]�ȼ��� *(dp+1)��Ҳ���ǵ�2��doubleԪ�ص��ڴ��
	cout << "d[0]=: " << dp[0] << " d[1]=: " << dp[1] << endl;
	delete[] dp; // �ͷ�dpָ��Ķ��doubleԪ��ռ�ݵ��ڴ�飬
 // ��ÿ��doubleԪ�ص��������������ͷ���Դ
 // ȱ��[]��ֻ�ͷŵ�һ��doubleԪ�ص��ڴ�飬��С��ڴ�й©��
	int n = 8;
	dp = new double[n]; // new ���Է��������С��doubleԪ�أ�
// ����̬����������Ǳ����ڹ̶���С������СΪ����
// �� double arr[20];
//ͨ���±����ÿ��Ԫ��
	for (int i = 0; i < n; i++) {
		dp[i] = i;
	} //ͨ��ָ�����ÿ��Ԫ��
	double *p = dp;
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << endl; //p[i]��dp[i]
	}
	cout <<endl;
	for (double *p = dp, *q = dp + n; p < q; p++) {
		cout << *p << endl;
	}
	cout << endl;
	delete[] dp;
	char *s;
	s = new char[100];
	strcpy(s, "Hello!"); //���ַ�������������sָ����ַ������ڴ����
	cout << s << endl;
	delete[] s; //�����Ժ󣬼ǵ��ͷ��ڴ�飬����ᡰ�ڴ�й©����
	return 0;
}
