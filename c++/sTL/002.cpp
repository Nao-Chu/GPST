#include <iostream>
#include <map>
using namespace std;

void test01(){
	map <int,int> mymap;

	// 插入数据,pair,first 
	// one 
	mymap.insert(pair<int,int>(10,10));

	// two
	mymap.insert(make_pair(20,20));

	//three
	mymap.insert(map<int,int>::value_type(30,30));

	//four
	mymap[40] = 40;

	//print
	for (map<int,int>::iterator it = mymap.begin(); it != mymap.end(); it++){
		cout << (*it).first << "," << it->second << endl;
	}

}

void test02(){
	map<int,int> map_02;
	map_02[10] = 1;
	map_02[20] = 2;
	map_02[30] = 3;
	if (map_02.count(30)){
		cout << "have count" << endl;
	}
	else
		cout << "No count" << endl;

	if (map_02.count(3)){
		cout << "have count" << endl;
	}
	else
		cout << "No count" << endl;
}

int main(int argc,char** argv)
{
	//test01();
	test02();
	return 0;
}
