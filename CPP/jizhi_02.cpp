/*
极致游戏 笔试2
给一定一个平衡字符串，按照一定规律求这个字符串的value。
()=1,(A)=2*A,AB=A+B，这里的A和B均是平衡字符串。
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
//	int getScorce(string str) {
//		stack<int> stk;
//		int value = 0;
//        for (char ch : str) {
//            if (ch == '(') {
//                // 如果遇到'('，将当前的value压栈
//                stk.push(value);
//                value = 0; // 重置value，为新的子字符串做准备
//            }
//            else if (ch == ')') {
//                // 如果遇到')'，计算子字符串的值
//                int temp = value * 2; // 根据规律2，乘以2
//                value = stk.top() + temp; // 根据规律3，加上栈顶的值
//                stk.pop(); // 弹出栈顶元素
//            }
//        }
//		return value;
//	}
//};
//
//int main() {
//	Solution sln;
//	string str = "()(()())";
//	cout << sln.getScorce(str) << endl;
//	return 0;
//}
