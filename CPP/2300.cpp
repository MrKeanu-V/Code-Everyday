/*
2300. Successful Pairs of Spells and Potions [Medium - 1477]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ranges> // c++20
#include <queue>
#include <stack> 
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	// 解法一 排序+二分
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		sort(potions.begin(), potions.end());
		vector<int> res(spells.size());
		for (auto& i : spells) {
			int count = potions.end() - lower_bound(potions.begin(), potions.end(), (success + i - 1) / i);
			res.push_back(count);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<int> spells = { 3, 1, 2 };
	vector<int> potions = { 8,5,8 };
	long long success = 8;
	vector<int> res = sln.successfulPairs(spells, potions, success);
	for (auto& i : res) cout << i << " ";
	return 0;
}