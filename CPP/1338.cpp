/*
1338. Reduce Array Size to The Half [Medium - 1303]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <ranges>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 排序 + 哈希 时间复杂度:O(nlogn), 空间复杂度:O(n)
	int minSetSize_1(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		unordered_map<int, int> cnt;
		for (const auto& e : arr) cnt[e]++;
		vector<int> vec;
		for (const auto& [k,v] : cnt) vec.push_back(v);
		sort(vec.begin(), vec.end(), greater());
		int res = 0, i = 0, cur = arr.size(), target = arr.size() / 2;
		while (cur > target) {
			cur -= vec[i];
			res++;
			i++;
		}
		return res;
	}
	// 解法一优化
	int minSetSize(vector<int>& arr) {
		unordered_map<int, int> cnt;
		for (const auto& e : arr) cnt[e]++;
		vector<int> vec;
		for (const auto& [_, v] : cnt) vec.push_back(v);
		sort(vec.begin(), vec.end(), greater());
		int sum = 0;
		for (int i = 0;; i++) {
			sum += vec[i];
			if (sum >= arr.size() / 2) return i + 1;
		}
	}
};

int main() {
	Solution sln;
	vector<int> arr = { 7,7,77,7, 7 };
	cout << sln.minSetSize(arr) << endl;
	return 0;
}