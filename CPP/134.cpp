/*
134. Gas Station [Medium - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// �ⷨһ Greedy
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
};