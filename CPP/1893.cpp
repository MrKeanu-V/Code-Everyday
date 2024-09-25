/*
1893. Check if All the Integers in a Range Are Covered medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	bool isCovered(vector<vector<int>>& ranges, int left, int right) {
		vector<int> diff(55, 0);
		for (auto& r : ranges) {
			diff[r[0]]++;
			diff[r[1] + 1]--;
		}
		int value = 0;
		for (int i = 1; i < 51; i++) {
			value += diff[i];
			if (i >= left && i <= right && value <= 0)
				return false;
		}
		return true;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> ranges = { {1,50} };//{ {1,2},{3,4},{5,6} };
	int left = 2, right = 5;
	cout << sln.isCovered(ranges, left, right) << endl;
	return 0;
}