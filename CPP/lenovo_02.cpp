/*
输入：
第一行两个正整数n和q
第二行n个正整数，第i个表示第i个苹果的重量
第三行q个正整数，第i个表示第i个询问
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <utility> // pair
#include <string>
using namespace std;

class Solution {
public:
	// 解法一 前缀和+暴力
	string buyApples(vector<int>& preSum, int w) {
		int low = 0, high = preSum.size() - 1;
		
		for (int i = 0; i < preSum.size(); i++) {
			for (int j = i + 1; j < preSum.size(); j++) {
				if (preSum[j] - preSum[i] == w) {
					return "Yes";
				}
			}
		}

		return "No";
	}
};

//int main() {
//	Solution sln;
//
//	int n, q;
//	cin >> n >> q;
//
//	vector<int> preSum(n+1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> preSum[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		preSum[i] += preSum[i - 1];
//	}
//	for (int i = 0; i < q; i++) {
//		int w;
//		cin >> w;
//		cout << sln.buyApples(preSum, w) << " " << endl;
//	}
//
//	return 0;
//}