/*
× 给定一个整数数组和一个整数k,
* 判断数组中是否存在两个不同索引i和j,
× 使得nums[i] = nums[j]
* 并且i和j的差的绝对值最大为k.
*/
#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;

class Solution{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k){
		unordered_map<int,int> map;
		for (size_t i = 0; i < nums.size(); i++){
			if (map.count(nums[i]) && i - map[nums[i] <= k]) 
				return true;
			map[nums[i]] = i;
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	vector<int> nums = vector<int>({3,4,5,6,1,2,3,1});
	int k = 3;
	Solution s;
	if (s.containsNearbyDuplicate(nums,k))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}
