/********************************************************************
    > File Name: 14.cpp
    > Author: zzp
    > Created Time: 2020年03月06日 星期五 01时29分52秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
using namespace std;

bool GreatThree(int iNum)
{
	return iNum>3;
}
int main()
{
	vector<int> v1 = vector<int>({1,2,3,3,5});

	// 找重复的
	vector<int>::iterator it = adjacent_find(v1.begin(),v1.end());

	bool i = binary_search(v1.begin(),v1.end(),7);

	int num = count(v1.begin(),v1.end(),7);

	int num_if = count_if(v1.begin(),v1.end(),GreatThree);

	vector<int>::iterator it1 = find(v1.begin(),v1.end(),7);

	vector<int>::iterator it2 = find_if(v1.begin(),v1.end(),GreatThree);
	return 0;
}
