/*
739. Daily Temperatures [Medium - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 暴力+逆向遍历 Time: O(n^2), Space: O(1)
	vector<int> dailyTemperatures_1(vector<int>& T) {
		int n = T.size();
		vector<int> res(n, 0), next(101, INT_MAX);
		for (int i = n - 1; i >= 0; --i) {
			int warmerIndex = INT_MAX;
			for(int t = T[i] + 1; t < 101; ++t) warmerIndex = min(warmerIndex, next[t]);
			if (warmerIndex != INT_MAX) res[i] = warmerIndex - i;
			next[T[i]] = i;
		}
		return res;
	}

	// 解法二 单调栈+正向遍历 Time: O(n), Space: O(n)
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> res(n, 0);
		stack<int> stk;

		for (int i = 0; i < n; i++) {
			while (!stk.empty() && T[i] > T[stk.top()]) {
				int pre = stk.top();
				res[pre] = i - pre;
				stk.pop();
			}
			stk.push(i);
		}

		return res;
	}

	void test() {
		vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
		printVector1D(dailyTemperatures(T));
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}