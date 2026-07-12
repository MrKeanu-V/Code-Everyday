/*
LCS 01. JuXwi Download Plugins [Esay]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 模拟
	int leastMinutes1(int n) {
		return ceil(log(n)/log(2)) + 1;
	}
	int leastMinutes2(int n) {
		return n <= 1 ? 1 : log(n - 1) / log(2) + 2;
	}
	// 解法二 DP
	int leastMinutes(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[(i + 1) / 2] + 1;
		}
		return dp[n];
	}
};

int main() {
	Solution sln;
	int n = 69;
	cout << sln.leastMinutes(n) << endl;
	return 0;
}        }
    }
};

int my_main() {
    // ���������
    // ���룺[5,7,9,8,3,2,4]  5 7 9 8 3 2 4
    // �����[5,9,7,4,2,3,8]
    int val;
    vector<TreeNode*> nodes;
    while (cin >> val) {
        TreeNode* node = new TreeNode(val);
        nodes.push_back(node);
        // �������з�����ֹѭ��
        if (getchar() == '\n') break;
        if (cin.get() == '\n') break;
    }
   // ���㹹��������
    for (int i = 0; i < nodes.size(); i++) {
        if (i * 2 + 1 < nodes.size()) {
            nodes[i]->left = nodes[i * 2 + 1];
        }
        if (i * 2 + 2 < nodes.size()) {
            nodes[i]->right = nodes[i * 2 + 2];
        }
    }
    Solution sln;
    // ��ӡ������
    //for (auto node : nodes) cout << node->val << " ";
    // ��ת
    sln.invertTree(nodes[0]);
    //cout<<endl;
    // �����ӡ������
    sln.printTree(nodes[0]);
    // �ͷ��ڴ�
    for (auto node : nodes) delete node;
    return 0;
}