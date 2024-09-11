/*
LeetCode 32 ���� ���Ч����
*/

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

// �ⷨһ��ջ�������������Ҫά������������Ϊ�߽紦��
int longestValidParentheses(string s) {
	stack<int> stk;
	int maxLen = 0;
	stk.push(-1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else {
			stk.pop();
			if (stk.empty()) {
				stk.push(i);
			}
			else {
				maxLen = max(maxLen, i - stk.top());
			}
		}
	}

    return maxLen;
}

// �ⷨ������̬�滮��������״̬ת�Ʒ��̣�
int longestValidParentheses(string s) {
	int maxLen = 0, n= s.size();
	vector<int> dp(n, 0);
	for (int i = 1; i < n; i++) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
			}
			else if (i - dp[i-1] > 0 && s[i - dp[i - 1] - 1] == '(') {
				dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
			}
		}
		maxLen = max(maxLen, dp[i]);
	}
	return maxLen;
}

//�ⷨ����˫ָ��

int main() {
	string s;
	cin >> s;
 	cout << longestValidParentheses(s);

	return 0;
}
