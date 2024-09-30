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
* 益智类题目套路：BFS + Hash Set 先构建网边图，然后进行BFS搜索
* BFS本质是暴力搜索，所以时间复杂度很高，但是空间复杂度很低
* 将此类移动题目进行逆向，以空缺格为其起点，进行BFS搜索
*/
class Solution {
private:
	vector<vector<int>> neighbors = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
public:
	// BFS + Hash Set 
	int slidingPuzzle(vector<vector<int>>& board) {
		// 所有一次操作可能状态
		auto get = [&](string& status)->vector<string> {	// 匿名函数
			vector<string> ret;
			int x = status.find('0');
			for (int y : neighbors[x]) {
				swap(status[x], status[y]);
				ret.push_back(status);
				swap(status[x], status[y]);
			}
			return ret;
		};

		// 初始状态
		string init;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				init += char(board[i][j] + '0');
			}
		}
		// 边界处理
		if (init == "123450")	return 0;

		// 深度优先搜索
		queue<pair<string, int>> q;	// key: 状态 value: 步数
		q.emplace(init, 0);
		unordered_set<string> visited = { init };	// 记录访问过的状态

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