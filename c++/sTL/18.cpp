/********************************************************************
    > File Name: 18.cpp
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 01时59分34秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1 = vector<int>({5,2,3,1});
	vector<int> v2 = vector<int>({10,3,4,2});
	vector<int> v3; 

	// 合并(merga) and change set
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	return 0;
}
