/*
//24. string 
//string����ĳ�ʼ��
#include <iostream>
#include <string> //typedef std::basic_string<char> string;
using namespace std;
typedef string String;
int main() {
	// with no arguments
	string s1; //Ĭ�Ϲ��캯����û�в����������Ĭ��ֵ
	String s2("hello"); //��ͨ���캯�� String����string
	s1 = "Anatoliy"; //��ֵ����� 
	String s3(s1); //�������캯�� string s3 =s1;    1
	cout << "s1 is: " << s1 << endl;
	cout << "s2 is: " << s2 << endl;
	cout << "s3 is: " << s3 << endl;
	// first argumen C string
	// second number of characters
	//��ֵ10�� 
	string s4("this is a C_sting", 10);            //2
	cout << "s4 is: " << s4 << endl;
	// 1 - C++ string
	// 2 - start position
	// 3 - number of characters\
	//��ֵ��4������6�� 
	string s5(s4, 6, 4); // copy word from s3      //3
	cout << "s5 is: " << s5 << endl;
	// 1 - number characters
	// 2 - character itself
	string s6(2, '*');                             //4
	cout << "s6 is: " << s6 << endl;
	// 1 - start iterator
	// 2 - end iterator
	string s7(s4.begin(), s4.end() - 5);           //5
	cout << "s7 is: " << s7 << endl;
	// you can instantiate string with assignment
	string s8 = "Anatoliy";
	cout << "s8 is: " << s8 << endl;
	string s9 = s1 + "hello"+ s2; //s1 + "hello"+ s2�Ľ����string���͵Ķ���(����)
	cout << "s9 is: " << s9 << endl;
	return 0;
}
*/
/*
//��������Ԫ�ء�����
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s = "hell";
	string w = "worl!";
	s = s + w; //s +=w; 
	for (int ii = 0; ii != s.size(); ii++)
		cout << ii << " " << s[ii] << endl;
	cout << endl;
	string::const_iterator cii;             //???????????????????????????????????????????????????????????????????????????????????
	int ii = 0;
	for (cii = s.begin(); cii != s.end(); cii++)
		cout << ii++ << " " << *cii << endl;
}
*/

//25. vector ���� 
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main() {
	vector<double> student_marks;
	int num_students;
	cout << "Number of students: " << endl;
	cin >> num_students;
	student_marks.resize(num_students);
	for (vector<double>::size_type i = 0; i < num_students; i++) {
		cout << "Enter marks for student #" << i + 1<< ": " << endl;
		cin >> student_marks[i];
	}
	cout << endl;
	for (vector<double>::iterator it = student_marks.begin();it != student_marks.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
