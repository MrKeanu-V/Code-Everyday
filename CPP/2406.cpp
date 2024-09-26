/*
2406. Divide Intervals Into Minimum Number of Groups  [Mediun]
*/
#include <iostream>
#include <vector>
#include <map>	// 平衡树，有序，O(logn)
#include <numeric>
#include <algorithm>	//C++11，包含std::sort
#include <ranges>		//C++20，包含std::ranges::sort
using namespace std;

class Solution {
public:
	// 解法一 差分
	bool hasIntersection(const vector<int>& a, const vector<int>& b) {
		
		return a[1] >= b[0] || a[0] <= b[1];
	}
	int minGroups(vector<vector<int>>& intervals) {
		//ranges::sort(intervals, [](const auto& a, const auto& b) {return a[0] < b[0]; });	// C++20才添加的ranges::sort
		sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {return a[0] < b[0]; });
		map<int, int> diff;
		for (auto& i : intervals)
			diff[i[0]]++, diff[i[1] + 1]--;
		int res = 0, sum = 0;
		for (auto& d : diff) {
			sum += d.second;
			res = max(res, sum);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> intervals = { {1,3},{5,6},{8,10},{11,13}};//{ {5,10},{6,8},{1,5},{2,3},{1,10} };
	cout << sln.minGroups(intervals) << endl;
	return 0;
}