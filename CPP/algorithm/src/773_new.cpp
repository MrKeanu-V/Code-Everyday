/*
773. Sliding Puzzle [Hard - 1815]
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
	vector<vector<int>> neibors_map = {	// 映射表
		{1,3},
		{0,2,4},
		{1,5},
		{0,4},
		{1,3,5},
		{2,4}
	};
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		// 状态转移
		auto getNextState = [&](string state)->vector<string> {
			int zero_pos = state.find('0');
			vector<string> next_states;
			for (auto next_pos : neibors_map[zero_pos]) {
				swap(state[zero_pos], state[next_pos]);
				next_states.push_back(state);
				swap(state[zero_pos], state[next_pos]);
			}
			return next_states;
		};
		// 初始状态
		string init_state = "";
		for (auto& row : board) {
			for (auto& num : row) {
				init_state += char(num + '0');
			}
		}
		unordered_map<string, int> visited = { {init_state,0} };
		queue<string> bfs_queue;
		bfs_queue.push(init_state);
		// 深度优先搜索
		while (!bfs_queue.empty()) {
			string cur = bfs_queue.front();
			bfs_queue.pop();
			if (cur == "123450") {
				return visited[cur];
			}
			for (auto next : getNextState(cur)) {
				if (visited.find(next) == visited.end()) {
					bfs_queue.push(next);
					visited[next] = visited[cur] + 1;
				}
			}
		}

		return -1;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> board = { {1,2,3},{5,0,4} };
	cout << sln.slidingPuzzle(board) << endl;
	return 0;
}