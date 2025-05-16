/*
	��̬�滮�� 
	��̬�滮�ı����ǽ�һ������ֽ�Ϊ��������⣬ͨ���������������Ž����õ�ԭ��������Ž⡣

	����˼·��
	1. �ж��Ƿ����DP����������޺�Ч�ԣ�����ǰ״ֻ̬����һ��״̬�йأ���֮ǰ��״̬�޹ء� ��Ч�ԣ���ǰĳ��״̬ȷ����֮���״̬ת����֮ǰ�ľ����޹�
	2. ����״̬��������DP���飬��ȷ��DP����ĺ��塣
	3. ȷ��״̬ת�Ʒ��̣���ȷ����δ�һ��״̬ת�Ƶ���һ��״̬��
	4. ȷ��״̬ת�Ƶ�Ҫ�󣺼�DP�ĳ�ʼ״̬���Լ�״̬ת����Ҫ�Ƿ�����ĳ���������粻©�����غϲ�©�ȡ���һ������ֵ��©���󷽰������ز�©��
	5. ȷ��DP��ʱ�ո��Ӷȣ�һ��������ж��ٿ���״̬�йء�

	�������ͣ�
	1. ����DP
    	1) ����������� Longest Increasing Subsequence
	2. ����DP
		1) ����������� Longest Common Subsequence
		2) ������Ӵ� Longest Common Substring
		3) ����������� Longest Increasing Subsequence
		4) 
		5) ��С·���� Minimum Path Sum
		6) ����Ӷκ� Maximum Subarray
	3. ����DP
    	1) ����DP Tree DP
    4. ״̬ѹ��DP
    	1) ״̬ѹ��DP State Compression DP
	5. ����DP
    	1) ����DP Circular DP
	6. ����DP
    	1) 0/1�������� 0/1 Knapsack Problem
		2) ��ȫ�������� Unbounded Knapsack Problem
  		3) ���ر������� Multiple Knapsack Problem
		4) ���鱳������ Group Knapsack Problem
	7. ����DP
    	1) ���·������ Shortest Path Problem
    8. ��λDP
    	1) ��λDP Digit DP
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>	// priority_queue
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility> // pair
using namespace std;

// 0/1����ģ�� ���ģ�DP����+״̬ת�Ʒ���
// ����������ѵ����ڽ��������ΪDP���⣬���ҵ�״̬ת�Ʒ��̡��Ա���������ԣ��ص����ҵ���Ʒ��ѡ��ɱ��ͼ�ֵ��
int zeroOnePack(vector<int>& weight, vector<int>& value, int capacity) {
	int n = weight.size();
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= capacity; ++j)
			dp[i][j] = j >= weight[i] ? max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]]) : dp[i - 1][j];
	return dp[n][capacity];
}
// ��ά01����ģ�� ʾ��474. һ����
int multiDimensionalZeroOnePack(vector<string>& strs, int m, int n) {
	// DP����
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	// value���� first:'0' second:'1'
	vector<pair<int, int>> values(strs.size() + 1);
	for (int i = 0; i < strs.size(); ++i) {
		pair<int, int> p(count_if(strs[i].begin(), strs[i].end(), [](char c) { return c == '0'; }), 0);
		p.first = strs[i].size() - p.first;
		values[i + 1] = p;
	}
	// ��άDP
	for (int i = 1; i < strs.size() + 1; ++i) {
		for (int j = m; j >= values[i].first; --j) {
			for (int k = n; k >= values[i].second; --k) {
				dp[j][k] = max(dp[j][k], dp[j - values[i].first][k - values[i].second] + 1);
			}
		}
	}
	return dp[m][n];
}
