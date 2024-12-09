/*
1481. Least Number of Unique Integers after K Removals [Medium - 1284]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <functional>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
	// 解法一 贪心 + 哈希 + 暴力模拟  TLE
	int findLeastNumOfUniqueInts_1(vector<int>& arr, int k) {
		unordered_map<int, int> m;
		for (int i : arr) m[i]++;
		vector<pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.second < b.second; });
		int cnt = v.size();
		for (auto& p : v) {
			if (k >= p.second) {
				cnt--; k -= p.second;
			}
			else break;
		}
		return cnt;
	}
	// 解法二 贪心 + 哈希 + 优先队列
	int findLeastNumOfUniqueInts_2(vector<int>& arr, int k) {
		int n = arr.size();
		unordered_map<int, int> m;
		for (auto& i : arr) m[i]++;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (auto& p : m) pq.push(make_pair(p.second, p.first));
		while (k) {
			auto& p = pq.top();
			if (k >= p.first)  k -= p.first;
			else break;
			pq.pop();
		}
		return pq.size();
	}
	// 解法三 优先队列 优先级构造器
	struct Cmp {
		bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
		}
	};
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		unordered_map<int, int> m;
		for (auto& i : arr) m[i]++;
		priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq(m.begin(), m.end());
		while (k) {
			auto& p = pq.top();
			if (k >= p.second) k -= p.second;
			else break;
			pq.pop();
		}
		return pq.size();
	}
};

int main() {
	Solution sln;
	vector<int> arr = { 4,3,1,1,3,3,2 };
	int k = 3;
	cout << sln.findLeastNumOfUniqueInts(arr, k) << endl;
	return 0;
}