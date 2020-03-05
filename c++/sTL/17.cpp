/********************************************************************
    > File Name: 17.cpp
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 01时56分37秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1 = vector<int>({5,2,3,1});
	vector<int> v2 = vector<int>({5,2,3,1});
	int tmp = accumulate(v1.begin(),v1.end(),0);
	cout << tmp << endl;

	// all change 8
	fill(v1.begin(),v1.end(),8);
	return 0;
}
