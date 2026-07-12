/*
2279 Maximum Bags With Full Capacity of Rocks [Medium - 1249]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <functional>
#include <numeric>
#include <queue>
using namespace std;

class Solution {
public:
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		for(int i = 0; i < capacity.size(); i++) capacity[i] -= rocks[i];
		sort(capacity.begin(), capacity.end(), less<int>());
		int count=0;
		while (count < capacity.size() && additionalRocks >= capacity[count]) additionalRocks -= capacity[count++];
		return count;
	}
};

int main() {
	Solution sln;
	vector<int> capacity = { 1 };
	vector<int> rocks = { 0 };
	int additionalRocks = 1;
	cout << sln.maximumBags(capacity, rocks, additionalRocks) << endl;
	return 0;
}