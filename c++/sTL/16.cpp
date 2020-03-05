/********************************************************************
    > File Name: 16.cpp
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 01时51分26秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

bool great_equal_5(int &n)
{
	return n>5;
}

int main()
{
	vector<int> v1 = vector<int>({5,2,3,1});
	vector<int> v2; 
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());

	// 3 change 8
	replace(v1.begin(),v1.end(),3,8);

	// >5 change 1
	replace_if(v1.begin(),v1.end(),great_equal_5,1);

	swap(v1,v2);
	return 0;
}
