/*
*在大小为 2N 的数组 A 中有 N+1 个不同的元素，
*其中有一个元素重复了 N 次。
*输出这个数
*参数：		偶数个数的正整数
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
		if (A.size() % 2 != 0){
			printf("A的不是2N个的数组\n");
			return 0;
		}
		sort(A.begin(),A.end());
		middle = 0.5 * A.size();
		if (A[0] == A[middle - 1])  return A[middle - 1];
		else if (A[middle] == A[A.size() - 1]) return A[middle];
		else return A[middle];
	}
													    
	int middle;
};

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("请输入参数\n");
		return 0;
	}
	int result;
	vector<int> A;
	for(int i = 0; i < argc - 1; i++)
	{
		A.push_back(atoi(argv[i+1]));
	}
	Solution s;
	result = s.repeatedNTimes(A);
	printf("%d\n",result);
	return 0;
}
