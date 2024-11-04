/*
1575. Count All Possible Routes [Hard - 2055]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Solution {
private:
	int mod = 1e9 + 7;
	vector<vector<int>> cache;	// 记忆化搜索
	int dfs1(vector<int>& locations, int cur, int end, int fuel) { 
		if (fuel < 0) return 0; // base case
		if (cache[cur][fuel] != -1) return cache[cur][fuel]; // 记忆化
		int res = cur == end ? 1 : 0;
		for (int i = 0; i < locations.size(); i++)
			if (i != cur)
				res = (res + dfs(locations, i, end, fuel - abs(locations[cur] - locations[i]))) % int(1e9 + 7);
		return cache[cur][fuel] = res;
	}
	// 优化DFS的时间复杂度
	int dfs(vector<int>& locations, int cur, int end, int fuel) {
		if (fuel < 0) return 0; // base case
		if (cache[cur][fuel] != -1) return cache[cur][fuel]; // read cache
		if (fuel < abs(locations[cur] - locations[end])) return cache[cur][fuel] = 0; // base case 2
		int res = cur == end ? 1 : 0;
		for (int i = 0; i < locations.size(); i++)
			if (i != cur)
				if(fuel >= abs(locations[cur] - locations[i]))
					res = (res + dfs(locations, i, end, fuel - abs(locations[cur] - locations[i]))) % mod;
		return cache[cur][fuel] = res;
	}

public:
	// 解法一 记忆化搜索
	int countRoutes1(vector<int>& locations, int start, int finish, int fuel) {
		cache.resize(locations.size(), vector<int>(fuel + 1, -1));
		return dfs(locations, start, finish, fuel);
	}
	// 解法二 动态规划 类背包问题
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		int n = locations.size();
		vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));

		// 初始化DP
		dp[finish] = vector<int>(fuel + 1, 1);
		for (int cur = 0; cur <= fuel; cur++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					int cost = abs(locations[i] - locations[j]);
					if (cur >= cost) dp[j][cur] = (dp[j][cur] + dp[i][cur - cost]) % mod;
				}
			}
		}
	
		return dp[start][fuel];
	}
};

int main() {
	Solution sln;
	vector<int> locations = { 2,3,6,8,4 };
	int start = 1, finish = 3, fuel = 5;
	cout << sln.countRoutes(locations, start, finish, fuel) << endl;	// 4
	return 0;
}