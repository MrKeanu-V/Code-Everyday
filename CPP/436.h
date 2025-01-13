#pragma once
//#ifndef _436_H
//#define _436_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <functional>
using namespace std;

/*
436. Find Right Interval [Medium - 6]
*/

class Solution {
public:
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
	void test() {
		cout<<"436. Find Right Interval [Medium - 6]"<<endl;

		vector<vector<int>> intervals = { {1, 2} };
		vector<int> result = findRightInterval(intervals);
		printList(result);
		intervals = { {1, 4}, {2, 3}, {3, 4} }; 
		result = findRightInterval(intervals);
		printList(result);
		intervals = { {3, 4}, {2, 3}, {1, 2} };
		result = findRightInterval(intervals);
		printList(result);

		cout<<"436. Find Right Interval [Medium - 6]"<<endl;
	}
};

//#endif // _436_H