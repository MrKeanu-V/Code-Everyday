/*
134. Gas Station [Medium - 6]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution134 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("134")

	// 解法一 Greedy
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// gas = [1,2,3,4,5], cost = [3,4,5,1,2]
		int n = gas.size();
		vector<int> diff(n);
		for (int i = 0; i < n; i++) diff[i] = gas[i] - cost[i];
		if (accumulate(diff.begin(), diff.end(), 0) < 0) return -1;
		int start = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			sum += diff[i];
			if (sum < 0) start = i + 1, sum = 0;
		}
		return start;
	}

	void test() override {
		vector<int> gas = { 1,2,3,4,5 };
		vector<int> cost = { 3,4,5,1,2 };
		cout << canCompleteCircuit(gas, cost) << endl;    // 3
		gas = { 2,3,4 };
		cost = { 3,4,3 };
		cout << canCompleteCircuit(gas, cost) << endl;    // -1
	}
};

FNT_REGISTER(Solution134);