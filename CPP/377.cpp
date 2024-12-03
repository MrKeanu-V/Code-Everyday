/*
377. Combination Sum IV [Medium - 5]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <numeric>
using namespace std;

class Solution {
private:
	// 解法二 DFS
	int dfs(int i, vector<int>& nums, vector<int>& memo) {
		if (i == 0) return 1;
		int &res = memo[i];
		if (res != -1) return memo[i];
		res = 0;
		for (int x : nums) 
			res += (i >= x) ? dfs(i - x, nums, memo) : 0;

		return res;
	}
public:
	// 解法一 DP
	int combinationSum4_1(vector<int>& nums, int target) {
		vector<unsigned int> dp(target + 1, 0);
		dp[0] = 1;
		// Init DP array
		for (int i = 1; i <= target; i++)
			for (int x : nums)
				(i - x >= 0) ? dp[i] += dp[i - x] : 0;

		return dp[target];
	}

	// 解法二 DFS+Cache
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> memo(target + 1, -1);
		return dfs(target, nums, memo);
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111 };
	int target = 999;
	cout << sln.combinationSum4(nums, target) << endl;
	return 0;
}
