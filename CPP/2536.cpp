/*
2536. Increment Submatrices by One [Medium - 1583]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/*
差分和前缀和是处理数组问题时常用的两种技巧。
差分适用场景：
	1 区间查询：当需要快速计算数组中任意区间的累积值（如区间和）时，差分可以高效地实现这一点。
	2 区间更新：如果问题涉及到在数组的某个区间内
	进行更新（如增加或减少某个值），差分可以快速地将这种更新反映到整个数组上。
	3 处理树形结构：在处理树形结构时，差分可以用来快速计算从根节点到叶节点的路径上的累积值。
	动态逆序对：在动态变化的数组中计算逆序对的数量时，差分可以用来优化计算过程。
	4 处理不连续的区间：当需要处理多个不连续的区间更新时，差分可以有效地将这些更新合并。
前缀和适用场景：
	1 区间求和：前缀和可以快速计算数组中任意区间的和，只需用区间的两端的前缀和相减即可。
	2 滑动窗口问题：在处理需要滑动窗口的问题时，前缀和可以快速计算窗口内元素的和。
	3 区间最大/最小值：通过前缀和，可以快速找到区间最大值或最小值。
	4 区间其他累积量：除了求和，前缀和也可以用于计算其他类型的累积量，如乘积。
	5 有序问题：如果数组是有序的，前缀和可以用来快速解决一些与有序性相关的问题。
	6 优化搜索：在某些搜索问题中，前缀和可以帮助减少搜索空间。
*/
class Solution {
private:
	void addOnece(vector<vector<int>>& res, int x, int y, int val) {

	}
public:
	// 解法一： 二维差分+二维前缀和
	vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
		vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0));

		for (auto& q : queries) {	// 0 0 1 1
			diff[q[0]+1][q[1]+1]++;
			diff[q[0]+1][q[3]+2]--;
			diff[q[2]+2][q[1]+1]--;
			diff[q[2]+2][q[3]+2]++;
		}
		// 原地前缀和
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];

		// 去除边界
		diff.erase(diff.begin());
		diff.erase(diff.end() - 1);	// diff.pop_back();
		for (auto& row : diff) {
			row.erase(row.begin());
			row.pop_back();
		}
		return diff;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> queries = { {1, 1, 2, 2}, {0, 0, 1, 1} };
    vector<vector<int>> ans = sln.rangeAddQueries(3, queries);
	for (auto& row : ans) {
		for (auto& elem : row) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}