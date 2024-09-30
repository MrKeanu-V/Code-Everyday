/*
773. Sliding Puzzle [Hard - 1815]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/*
* ��������Ŀ��·��BFS + Hash Set �ȹ�������ͼ��Ȼ�����BFS����
* BFS�����Ǳ�������������ʱ�临�ӶȺܸߣ����ǿռ临�ӶȺܵ�
* �������ƶ���Ŀ���������Կ�ȱ��Ϊ����㣬����BFS����
*/
class Solution {
private:
	vector<vector<int>> neighbors = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
public:
	// BFS + Hash Set 
	int slidingPuzzle(vector<vector<int>>& board) {
		// ����һ�β�������״̬
		auto get = [&](string& status)->vector<string> {	// ��������
			vector<string> ret;
			int x = status.find('0');
			for (int y : neighbors[x]) {
				swap(status[x], status[y]);
				ret.push_back(status);
				swap(status[x], status[y]);
			}
			return ret;
		};

		// ��ʼ״̬
		string init;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				init += char(board[i][j] + '0');
			}
		}
		// �߽紦��
		if (init == "123450")	return 0;

		// �����������
		queue<pair<string, int>> q;	// key: ״̬ value: ����
		q.emplace(init, 0);
		unordered_set<string> visited = { init };	// ��¼���ʹ���״̬

		// BFS
		while (!q.empty()) {
			auto [status, step] = q.front();
			q.pop();
			for (auto&& nextStatus : get(status)) {
				if (!visited.count(nextStatus)) {
					if (nextStatus == "123450") {
						return step + 1;
					}
					q.emplace(nextStatus, step + 1);
					visited.insert(nextStatus);
				}
			}
		}

		return -1;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> board = { { 1, 2, 3 }, { 4, 0, 5 } };
	cout << sln.slidingPuzzle(board) << endl;
	return 0;
}