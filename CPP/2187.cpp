/*
2187. Minimum Time to Complete Trips [Medium - 1641]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <ranges>
using namespace std;

class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		function<bool(long long)> cmp = [&](long long x)->bool {
			long long sum = 0;
			for (int t : time) {
				sum += x / t;
				if (sum >= totalTrips) return true;
			}
			return false;
		};
		int minTime = *min_element(time.begin(), time.end()), maxTime = *max_element(time.begin(), time.end()), avg = (totalTrips - 1) / time.size() + 1;
		long long left = (long long)minTime * avg - 1, right = min((long long)maxTime * avg, (long long)minTime * totalTrips);
		while (left + 1 < right) {
			long long mid = (right + left) / 2;
			(cmp(mid) ? right : left) = mid;
		}
		return right;
	}
};

int main() {
	Solution sln;
	vector<int> time = { 2, 3 };
	int totalTrips = 3;
	cout << sln.minimumTime(time, totalTrips) << endl;
	return 0;
}