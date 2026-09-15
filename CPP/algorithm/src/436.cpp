/*
436. Find Right Interval [Medium - 6]
*/
#include "fnt/fnt_utils.h"
#include "fnt/fnt_solution.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <functional>
using namespace std;
using namespace fnt;

class Solution436 : public BaseSolution {
public:
	FNT_SOLUTION_KEY("436")

	// 解法一 排序+二分
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int n = intervals.size();
		vector<pair<int, int>> startIndex;
		vector<int> result(n, -1);
		for (int i = 0; i < n; i++) {
			startIndex.push_back(make_pair(intervals[i][0], i));
		}
		sort(startIndex.begin(), startIndex.end());
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(startIndex.begin(), startIndex.end(), make_pair(intervals[i][1], 0));
			if (it != startIndex.end()) {
				result[i] = it->second;
			}
		}
		return result;
	}
	void printList(vector<int> list) {
		for (auto i : list) cout << i << " ";
		cout << endl;
	}
	void test() override {
		cout << "436. Find Right Interval [Medium - 6]" << endl;

		vector<vector<int>> intervals = { {1, 2} };
		vector<int> result = findRightInterval(intervals);
		printList(result);
		intervals = { {1, 4}, {2, 3}, {3, 4} };
		result = findRightInterval(intervals);
		printList(result);
		intervals = { {3, 4}, {2, 3}, {1, 2} };
		result = findRightInterval(intervals);
		printList(result);

		cout << "436. Find Right Interval [Medium - 6]" << endl;
	}
};

FNT_REGISTER(Solution436);