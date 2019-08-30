/*
 * 给定一个由整数组成的非空数组所
 * 表示的非负整数
 * 在该数基础加一 
*/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits){
		if (digits.size() == 0) return digits;
		vector<int>::iterator it = digits.end() - 1;
		*it += 1;
		while(*it == 10){
			if(it == digits.begin()){
				*it = 1;
				digits.push_back(0);
				break;
			}
			*it = 0;
			it--;
			*it += 1;
		}
		return digits; 
	}
};

int main()
{
	Solution s;
	vector<int> nums = vector<int>({9,9,9});
	for (size_t i = 0; i < nums.size(); i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
	vector<int> plus = s.plusOne(nums);
	for (size_t i = 0; i < plus.size(); i++){
		printf("%d ",plus[i]);
	}
	printf("\n");
	return 0;
}
