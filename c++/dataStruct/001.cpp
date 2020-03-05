/*************************************************************************
    > File Name: 001.cpp
    > Author: zzp
    > Created Time: 2020年03月04日 星期三 23时41分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

// big data swap  V 
void search(int a[],int len)
{
	int sp[10000] = {0};
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		int index = a[i] - 1;
		sp[index]++;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (max < sp[i])
		{
			max = sp[i];
		}
	}

	for (int i = 0; i < 10000; i++)
	{
		if (max == sp[i])
		{
			cout << "max = " << i+1 << endl;
		}
	}
}
int main()
{
	int array[] = {1,1,3,3,4,5,4,4,8,3,46};
	search(array,sizeof(array)/sizeof(*array));
}
