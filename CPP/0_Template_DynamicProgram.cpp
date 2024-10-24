/*
	��̬�滮�� 
	��̬�滮�ı����ǽ�һ������ֽ�Ϊ��������⣬ͨ���������������Ž����õ�ԭ��������Ž⡣

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
int zeroOnePack(vector<int>& weight, vector<int>& value, int capacity) {
	int n = weight.size();
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= capacity; ++j)
			dp[i][j] = j >= weight[i] ? max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]]) : dp[i - 1][j];
	return dp[n][capacity];
}
