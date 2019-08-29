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
int main(int argc,char** argv)
{
	test01();
	return 0;
}
