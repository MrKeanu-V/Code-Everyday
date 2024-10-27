/*
极致游戏 笔试3
对于输入的字符串按照nstring的方式进行编码。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
using namespace std;

//class Solution {
//public:
//	string encodeString(string ori) {
//		string out;
//		vector<int> n;
//		bool flag = false;
//		for (int i = 0; i < ori.size();++i) {
//			char c = ori[i];
//			if (c >= '0' && c <= '9') {
//				n.push_back(c - '0');
//			}
//			else {
//				flag = true;
//				while (flag) {
//					
//				}
//				n.clear();
//			}
//		}
//		return out;
//	}
//};
//
//int main() {
//	Solution sln;
//	string str = "2a3b4c";
//	cout << sln.encodeString(str) << endl;
//	return 0;
//}