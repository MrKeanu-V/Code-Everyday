/*
	动态规划： 
	动态规划的本质是将一个问题分解为多个子问题，通过求解子问题的最优解来得到原问题的最优解。

	常用思路：
	1. 判断是否可用DP解决：即有无后效性，即当前状态只与上一个状态有关，与之前的状态无关。 后效性：当前某个状态确定后，之后的状态转移与之前的决策无关
	2. 定义状态：即定义DP数组，并确定DP数组的含义。
	3. 确定状态转移方程：即确定如何从一个状态转移到另一个状态。
	4. 确定状态转移的要求：即DP的初始状态，以及状态转移需要是否满足某种条件，如不漏、不重合不漏等。（一般求最值不漏，求方案数不重不漏）
	5. 确定DP的时空复杂度：一般和问题有多少可能状态有关。

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
//#include <bits/stdc++.h>
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
// 背包问题的难点在于将问题抽象为DP问题，并找到状态转移方程。以背包问题而言，重点是找到物品的选择成本和价值。
int zeroOnePack(vector<int>& weight, vector<int>& value, int capacity) {
	int n = weight.size();
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= capacity; ++j)
			dp[i][j] = j >= weight[i] ? max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]]) : dp[i - 1][j];
	return dp[n][capacity];
}
// 多维01背包模板 示例474. 一和零
int multiDimensionalZeroOnePack(vector<string>& strs, int m, int n) {
	// DP数组
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	// value数组 first:'0' second:'1'
	vector<pair<int, int>> values(strs.size() + 1);
	for (int i = 0; i < strs.size(); ++i) {
		pair<int, int> p(count_if(strs[i].begin(), strs[i].end(), [](char c) { return c == '0'; }), 0);
		p.first = strs[i].size() - p.first;
		values[i + 1] = p;
	}
	// 多维DP
	for (int i = 1; i < strs.size() + 1; ++i) {
		for (int j = m; j >= values[i].first; --j) {
			for (int k = n; k >= values[i].second; --k) {
				dp[j][k] = max(dp[j][k], dp[j - values[i].first][k - values[i].second] + 1);
			}
		}
	}
	return dp[m][n];
}
