/*
���룺
��һ������������n��q
�ڶ���n������������i����ʾ��i��ƻ��������
������q������������i����ʾ��i��ѯ��
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <utility> // pair
#include <string>
using namespace std;

class Solution {
public:
	// �ⷨһ ǰ׺��+����
	string buyApples(vector<int>& preSum, int w) {
		int low = 0, high = preSum.size() - 1;
		
		for (int i = 0; i < preSum.size(); i++) {
			for (int j = i + 1; j < preSum.size(); j++) {
				if (preSum[j] - preSum[i] == w) {
					return "Yes";
				}
			}
		}

		return "No";
	}
};

//int main() {
//	Solution sln;
//
//	int n, q;
//	cin >> n >> q;
//
//	vector<int> preSum(n+1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> preSum[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		preSum[i] += preSum[i - 1];
//	}
//	for (int i = 0; i < q; i++) {
//		int w;
//		cin >> w;
//		cout << sln.buyApples(preSum, w) << " " << endl;
//	}
//
//	return 0;
//}