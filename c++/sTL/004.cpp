#include <iostream>
#include <set>
using namespace std;

void test01(){
	set <int> myset;
	set <int>::iterator iter;

	// 插入数据,
	for (size_t i = 10; i < 20; i++){
		myset.insert(i);
	}

	// 遍历输出
	cout << "遍历输出： " << endl;
	for (iter = myset.begin(); iter != myset.end(); ++iter){
		cout << *iter << " " ;
	}
	cout << endl << endl;

	// 删除元素
	// 01
	cout << "删除元素：" << endl; 
	cout << "---01:" << endl;
	myset.erase(myset.begin());
	for (iter = myset.begin(); iter != myset.end(); ++iter){
		cout << *iter << " " ;
	}
	cout << endl;
	
	// 02 
	cout << "---02:" << endl;
	set<int>::iterator second;
	second = myset.begin();
	second++;
	second++;
	myset.erase(myset.begin(),second);
	for (iter = myset.begin(); iter != myset.end(); ++iter){
		cout << *iter << " " ;
	}
	cout << endl;

	//03
	cout << "---03:" << endl;
	myset.erase(19);
	for (iter = myset.begin(); iter != myset.end(); ++iter){
		cout << *iter << " " ;
	}
	cout << endl << endl;

	// count
	cout << "count：" << endl;
	if (myset.count(18)){
		cout << "have 18 " << endl;
	}
	else{
		cout << " no 18 " << endl;
	}

	// find
	cout << "find：" << endl;
	if ((iter = myset.find(18)) != myset.end()){
		cout << *iter << endl;
	}

}

void test02(){
}

int main(int argc,char** argv)
{
	test01();
//	test02();
	return 0;
}
