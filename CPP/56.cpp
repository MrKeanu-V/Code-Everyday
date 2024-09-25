/*
56. Merge Intervals medium 合并区间 中等
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
using namespace std;

class Solution {
public:
	// 解法一 差分+暴力 数据边界
	vector<vector<int>> merge1(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
		int n = intervals.size(), len = intervals[n - 1][1];
		vector<int> diff(len + 2, 0), temp;
		for (auto& i : intervals) {
			diff[i[0]]++, diff[i[1]]--;
		}
		vector<vector<int>> res;
		int sum = 0;
		for (int i = 0; i <= len; i++) {
			if (diff[i] > 0) {
                if (temp.empty())
                    temp.push_back(i);
				
			}
		}
		return res;
	}
	// 解法一 差分
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
		vector<vector<int>> res;
		for (auto& i : intervals) {
			if (!res.empty() && i[0] <= res.back()[1]) {
				res.back()[1] = max(res.back()[1], i[1]);
			}
			else
				res.push_back(i);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> intervals = { {1,3},{4,6},{7,10},{11,18} };
    vector<vector<int>> res = sln.merge(intervals);
	for (auto& i : res) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}