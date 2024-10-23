/*
2144. Minimum Cost of Buying Candies with Discount [Easy = 1261]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	// 解法一 暴力
	int minimumCost1(vector<int>& cost) {
		int res = 0;
        //priority_queue<int, vector<int>, greater<int>> pq;
		sort(cost.begin(), cost.end(), less<int>()); // 升序排列
		while (cost.size() >= 3) {
			res += cost.back();
			cost.pop_back();
			res += cost.back();
			cost.pop_back();
			cost.pop_back();
		}
		while (cost.size() > 0) res += cost.back(), cost.pop_back();
		return res;
	}
	// 解法二 优先队列+贪心
	int minimumCost(vector<int>& cost) {
		int res = 0;
		priority_queue<int, vector<int>, less<int>> pq;
		for (int i = 0; i < cost.size(); i++) {
			pq.push(cost[i]);
		}
		while (pq.size() >= 3) {
			res += pq.top();
			pq.pop();
			res += pq.top();
			pq.pop();
			pq.pop();
		}
		while (pq.size() > 0) res += pq.top(), pq.pop();
		return res;
	}
};

int main() {
	Solution sln;
    vector<int> cost = { 6, 5, 7, 9, 2, 2 };
	cout << sln.minimumCost(cost) << endl;
	return 0;
}