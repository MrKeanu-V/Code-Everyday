/*
1833. Maximum Ice Cream Bars - [Medium - 1253]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>	// std::accumulate
#include <string>
#include <array>
#include <ranges>
using namespace std;

class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		int i = 0, m = costs.size();
		sort(costs.begin(), costs.end(),less<int>());
		while (i < m && coins >= costs[i]) coins -= costs[i++];
		return i;
	}
};

int main() {
	Solution sln;
	vector<int> costs = { 1,3,2,4,1 };
	int coins = 7;
	cout<<sln.maxIceCream(costs, coins)<<endl;
	return 0;
}