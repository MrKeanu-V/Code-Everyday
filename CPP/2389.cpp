/*
2389. Longest Subsequence With Limited Sum [Medium - 2]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 二分+前缀和
	vector<int> answerQueries_1(vector<int>& nums, vector<int>& queries) {
		int n = nums.size(), m = queries.size();
		sort(nums.begin(), nums.end());
		vector<int> ans(m, 0), pre(n + 1, 0);
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
		for (int i = 0; i < m; i++) {
			int l = 0, r = n - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (queries[i] >= pre[mid + 1]) l = mid + 1;
				else r = mid - 1;
			}
			ans[i] = l;
		}
		return ans;
	}
	// 解法一 二分+前缀和 空间优化
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		int n = nums.size(), m = queries.size();
		sort(nums.begin(), nums.end());
		for (int i = 1; i < n; i++) nums[i] += nums[i - 1];
		for (int i = 0; i < m; i++) {
			int l = 0, r = n - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (queries[i] >= nums[mid]) l = mid + 1;
				else r = mid - 1;
			}
			queries[i] = l;
		}
		return queries;
	}
	// 解法一 二分+前缀和 纯STL
	vector<int> answerQueries_3(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());
		partial_sum(nums.begin(), nums.end(), nums.begin());	// pre_sum
		for (int& q : queries) q = ranges::upper_bound(nums, q) - nums.begin();
		return queries;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 4,5,2,1 }, queries = { 3,10,21 };
	vector<int> ans = sln.answerQueries(nums, queries);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}