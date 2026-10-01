/*
LeetCode 32. Longest Valid Parentheses [Hard]
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <fnt/fnt_solution.h>
#include <fnt/fnt_utils.h>
using namespace fnt;
using namespace std;

class Solution32 : public BaseSolution
{
public:
	FNT_SOLUTION_KEY("32")
	// 解法一：栈（核心以最后需要维护的右括号作为边界处理）
	int longestValidParentheses1(string s)
	{
		stack<int> stk;
		int maxLen = 0;
		stk.push(-1);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stk.push(i);
			}
			else
			{
				stk.pop();
				if (stk.empty())
				{
					stk.push(i);
				}
				else
				{
					maxLen = max(maxLen, i - stk.top());
				}
			}
		}

		return maxLen;
	}

	// 解法二：动态规划（核心找状态转移方程）
	int longestValidParentheses(string s)
	{
		int maxLen = 0, n = s.size();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				}
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
				{
					dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
				}
			}
			maxLen = max(maxLen, dp[i]);
		}
		return maxLen;
	}

	// 解法三：双指针

	void test() override
	{
		string s;
		cin >> s;
		cout << longestValidParentheses(s);
	}
};

FNT_REGISTER(Solution32);
