/*
小红书C++笔试1
小红的文章匹配
小红的文章第i篇有一个点赞数ai。小红认为如果两篇不同的文章的点赞数通过位异或运算的结果为k，那么这两篇文章是相似的，即ai xor aj == k。
现在小红收集了了n篇文章，她想知道有多少对不同的文章是相似的，请你帮帮她。
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	// 暴力解法
	//int getSimilarity(vector<int>& a, int k) {
	//	int ans = 0;
	//	for (int i = 0; i < a.size(); i++) {
	//		for (int j = i + 1; j < a.size(); j++) {
	//			if ((a[i] ^ a[j]) == k) {
	//				ans++;
	//			}
	//		}
	//	}
	//	return ans;
	//}
	// 哈希表 91% WA
	int getSimilarity(vector<int>& a, int k) {
		int ans = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < a.size(); i++) {
			int like = a[i];
			int xorRes = like ^ k;
			if (m.count(xorRes)) {
				ans += m[xorRes];
			}
			m[like]++;
		}
		return ans;
	}
};

//int main() {
//	//int n, k;
//	//cin >> n >> k;
//	//vector<int> a(n);
//	//for (int i = 0; i < n; i++) {
//	//	cin >> a[i];
//	//}
//	vector<int> a = { 1, 1, 2, 3, 4, 5 };
//	int k = 5;
//	Solution s;
//	cout << s.getSimilarity(a, k) << endl;
//	return 0;
//}