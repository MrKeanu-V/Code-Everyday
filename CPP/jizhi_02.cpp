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

class Solution {
private:
	stack<char> stk;
	int getScorce(string str, int index) {
		if (index >= str.size()) return 0;
		cout << "index:" << index << " char" << str[index] <<" size:"<< str.size() << endl;
		if (str[index] == ')') {

		}
		else if (str[index] == '(') {
			stk.push('(');
			return 1 + getScorce(str, index + 1);
		}
		return getScorce(str, index + 1);
	}
public:
	int getScorce(string str) {
		return getScorce(str, 0);
	}
};

int main() {
	Solution sln;
	string str = "()(()())";
	cout << sln.getScorce(str) << endl;
	return 0;
}
