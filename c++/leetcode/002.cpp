/*
* 给定一个排序数组，你需要在原地删除重复出现的元素
* 使得每个元素只出现一次
* 返回移除后数组的新长度
*/
#include <tr1/unordered_map>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std::tr1;
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums){
		unordered_map<int,int> hash;
		for (size_t i = 0; i < nums.size(); i++){
			if (hash.count(nums[i])){
				nums.erase(nums.begin() + i);
				i--;
			}
			else
				hash[nums[i]] = i;
		}
		return nums.size();
	}
};

int main()
{
	Solution s;
	vector<int> nums = vector<int>({1,1,1,2,2,3});
	for (size_t i = 0; i < nums.size(); i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
	cout << s.removeDuplicates(nums) << endl;
	for (size_t i = 0; i < nums.size(); i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
