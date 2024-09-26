/*
57. Insert Interval medium
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ranges>
using namespace std;

class Solution {
public:
	// 解法一 模拟 类双指针
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.emplace_back(newInterval);	// emplace_back性能比push_back好
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0];
			});
		vector<vector<int>> res;
		for (auto& i : intervals) {
			if (res.empty() || res.back()[1] < i[0])
				res.emplace_back(i);
			else
				res.back()[1] = max(i[1], res.back()[1]);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> intervals = { {1,3},{6,9} };
	vector<int> newInterval = { 2,5 };
    vector<vector<int>> result = sln.insert(intervals, newInterval);
	for (auto& interval : result) {
		for (auto& num : interval)
			cout << num << " ";
        cout << endl;
	}
		
	return 0;
}