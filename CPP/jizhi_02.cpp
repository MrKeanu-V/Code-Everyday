/*
������Ϸ ����2
��һ��һ��ƽ���ַ���������һ������������ַ�����value��
()=1,(A)=2*A,AB=A+B�������A��B����ƽ���ַ�����
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
//                // �������'('������ǰ��valueѹջ
//                stk.push(value);
//                value = 0; // ����value��Ϊ�µ����ַ�����׼��
//            }
//            else if (ch == ')') {
//                // �������')'���������ַ�����ֵ
//                int temp = value * 2; // ���ݹ���2������2
//                value = stk.top() + temp; // ���ݹ���3������ջ����ֵ
//                stk.pop(); // ����ջ��Ԫ��
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
