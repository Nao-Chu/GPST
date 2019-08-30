/*
 * 给定字符串J代表石头中宝石的类型
 * 和字符串S代表你拥有的石头
 * S中每个字符代表了一种你拥有的石头的类型
 × 你想知道你拥有的石头中有多少是宝石
*/
#include <tr1/unordered_set>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std::tr1;
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J,string S){
		int count = 0;
		unordered_set<char> jew;
		for (auto i : J) jew.insert(i);
		for (auto s : S) if (jew.count(s)) count++;
		return count;
	}
};

int main()
{
	Solution s;
	string J = "aA";
	string S = "aAAbbbb";
	cout << "J: " << J << endl;
	cout << "S: " << S << endl;
	printf("宝石个数为：%d\n",s.numJewelsInStones(J,S));
	return 0;
}
