/*
2536. Increment Submatrices by One [Medium - 1583]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/*
��ֺ�ǰ׺���Ǵ�����������ʱ���õ����ּ��ɡ�
������ó�����
	1 �����ѯ������Ҫ���ټ�������������������ۻ�ֵ��������ͣ�ʱ����ֿ��Ը�Ч��ʵ����һ�㡣
	2 ������£���������漰���������ĳ��������
	���и��£������ӻ����ĳ��ֵ������ֿ��Կ��ٵؽ����ָ��·�ӳ�����������ϡ�
	3 �������νṹ���ڴ������νṹʱ����ֿ����������ټ���Ӹ��ڵ㵽Ҷ�ڵ��·���ϵ��ۻ�ֵ��
	��̬����ԣ��ڶ�̬�仯�������м�������Ե�����ʱ����ֿ��������Ż�������̡�
	4 �������������䣺����Ҫ���������������������ʱ����ֿ�����Ч�ؽ���Щ���ºϲ���
ǰ׺�����ó�����
	1 ������ͣ�ǰ׺�Ϳ��Կ��ټ�����������������ĺͣ�ֻ������������˵�ǰ׺��������ɡ�
	2 �����������⣺�ڴ�����Ҫ�������ڵ�����ʱ��ǰ׺�Ϳ��Կ��ټ��㴰����Ԫ�صĺ͡�
	3 �������/��Сֵ��ͨ��ǰ׺�ͣ����Կ����ҵ��������ֵ����Сֵ��
	4 ���������ۻ�����������ͣ�ǰ׺��Ҳ�������ڼ����������͵��ۻ�������˻���
	5 �������⣺�������������ģ�ǰ׺�Ϳ����������ٽ��һЩ����������ص����⡣
	6 �Ż���������ĳЩ���������У�ǰ׺�Ϳ��԰������������ռ䡣
*/
class Solution {
private:
	void addOnece(vector<vector<int>>& res, int x, int y, int val) {

	}
public:
	// �ⷨһ�� ��ά���+��άǰ׺��
	vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
		vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0));

		for (auto& q : queries) {	// 0 0 1 1
			diff[q[0]+1][q[1]+1]++;
			diff[q[0]+1][q[3]+2]--;
			diff[q[2]+2][q[1]+1]--;
			diff[q[2]+2][q[3]+2]++;
		}
		// ԭ��ǰ׺��
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];

		// ȥ���߽�
		diff.erase(diff.begin());
		diff.erase(diff.end() - 1);	// diff.pop_back();
		for (auto& row : diff) {
			row.erase(row.begin());
			row.pop_back();
		}
		return diff;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> queries = { {1, 1, 2, 2}, {0, 0, 1, 1} };
    vector<vector<int>> ans = sln.rangeAddQueries(3, queries);
	for (auto& row : ans) {
		for (auto& elem : row) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}