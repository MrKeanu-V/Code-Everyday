/*
1170. Compare Strings by Frequency of the Smallest Character [Medium - 1432]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <functional>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	int getSmallestFreq(const string& s) {
		int cnt[26] = { 0 };
		for (auto c : s) cnt[c - 'a']++;
		for (auto i : cnt) if (i) return i;
		return -1;	// never reach here
	}

	// 解法一 二分查找
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		vector<int> q, w, res;
		function<int(string)> getFreq = [](const string& s)->int {
			int cnt[26] = { 0 };
			for (auto c : s) cnt[c - 'a']++;
			for (auto i : cnt) if (i) return i;
			return -1;	// never reach here
		};
		// Init
		for (auto& s : queries) q.push_back(getFreq(s));
		for (auto& s : words) w.push_back(getFreq(s));
		// Quick Sort
		sort(w.begin(), w.end(), [](int a, int b)->bool { return a > b; });	// descending order
		// Binary Search
		for (int i : q) {
			int l = 0, r = w.size() - 1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (w[mid] <= i) r = mid - 1;
				else l = mid + 1;
			}
        	res.push_back(l);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<string> queries =  { "bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb" }; //{ "cbd" };
	vector<string> words = { "aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab", "aa" };  // { "zaaaz" };
	vector<int> res = sln.numSmallerByFrequency(queries, words);	// [6,1,1,2,3,3,3,1,3,2]
	for (auto i : res) cout << i << " ";
	return 0;
}