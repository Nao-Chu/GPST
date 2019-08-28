/*
*给定一个整数数组 nums 和一个目标值 target，
*请你在该数组中找出和为目标值的那两个整数，
*并返回他们的数组下标。
*/
#include <tr1/unordered_map>
#include <vector>
#include <stdio.h>
using namespace std::tr1;
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums,int target){
		vector<int> down;
		unordered_map<int,int> hash;
		for (int i = 0; i < nums.size(); i++){
			int another = target - nums[i];
			printf("i =%d\n",i);
			if (hash.count(another)){
				down = vector<int>({hash[another],i});
				return down;
			}
			hash[nums[i]] = i;
		}
		return down;
	}
};

int main()
{
	int target = 9;
	Solution s;
	vector<int> acquire_down;
	vector<int> nums = vector<int>({2,7,11,15});
	for (int i = 0; i < nums.size(); i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
	acquire_down = s.twoSum(nums,target);
	for (int i = 0; i < acquire_down.size(); i++){
		printf("%d ",acquire_down[i]);
	}
	printf("\n");
	return 0;
}
