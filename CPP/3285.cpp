/*
3285. Find Indices of Stable Mountains. [Medium - 1166]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
	// 解法一： 暴力法
	vector<int> stableMountains(vector<int>& height, int threshold) {
		vector<int> res;
		for (int i = 1; i < height.size(); i++) {
			if (height[i-1] > threshold) res.push_back(i);
		}
		return res;
	}
	
};

int main() {
	Solution sln;
	vector<int> height = { 1,2,3,4,5 };
	int threshold = 2;
	vector<int> ans = sln.stableMountains(height, threshold);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";	// 3, 4
	return 0;
}