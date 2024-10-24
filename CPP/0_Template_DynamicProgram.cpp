/*
	动态规划： 
	动态规划的本质是将一个问题分解为多个子问题，通过求解子问题的最优解来得到原问题的最优解。

	常见类型：
	1. 线性DP
    	1) 最长递增子序列 Longest Increasing Subsequence
	2. 区间DP
		1) 最长公共子序列 Longest Common Subsequence
		2) 最长公共子串 Longest Common Substring
		3) 最长递增子序列 Longest Increasing Subsequence
		4) 
		5) 最小路径和 Minimum Path Sum
		6) 最大子段和 Maximum Subarray
	3. 树形DP
    	1) 树形DP Tree DP
    4. 状态压缩DP
    	1) 状态压缩DP State Compression DP
	5. 环形DP
    	1) 环形DP Circular DP
	6. 背包DP
    	1) 0/1背包问题 0/1 Knapsack Problem
		2) 完全背包问题 Unbounded Knapsack Problem
  		3) 多重背包问题 Multiple Knapsack Problem
		4) 分组背包问题 Group Knapsack Problem
	7. 矩阵DP
    	1) 最短路径问题 Shortest Path Problem
    8. 数位DP
    	1) 数位DP Digit DP
*/
#include <iostream>
#include <vector>
#include <queue>	// priority_queue
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility> // pair
using namespace std;

// 0/1背包模板 核心：DP矩阵+状态转移方程
int zeroOnePack(vector<int>& weight, vector<int>& value, int capacity) {
	int n = weight.size();
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= capacity; ++j)
			dp[i][j] = j >= weight[i] ? max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]]) : dp[i - 1][j];
	return dp[n][capacity];
}
