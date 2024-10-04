/*
1926. Nearest Exit from Entrance in Maze [Medium - 1638]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <tuple> 
using namespace std;

/*
  迷宫类题目求最短路径，一般使用BFS。关键在于如何构建BFS的初始状态和临界条件
*/
class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int m = maze.size(), n = maze[0].size();
		// 状态转移
		auto move = [&](int x, int y)->bool {
			if (maze[x][y] == '.') {
				maze[x][y] = '+';
				return true;
			}
			return false;
		};
		queue<tuple<int, int, int>> q;
		q.push({ entrance[0], entrance[1], 0});	// make_pair(TYPE1,TYPE2);
		maze[entrance[0]][entrance[1]] = '+';
		while (!q.empty()) {
			auto [x, y, step] = q.front();
			q.pop();
			// 临界条件
			if ((x == 0 || y == 0 || x == m - 1 || y == n - 1) && !(x == entrance[0] && y == entrance[1]))
				return step;
			if (x + 1 < m && move(x + 1, y)) q.push({ x + 1,y,step+1 });	// 可以改用映射实现
			if (x - 1 >= 0 && move(x - 1, y)) q.push({ x - 1,y,step+1 });
			if (y + 1 < n && move(x, y + 1)) q.push({ x,y + 1,step+1 });
			if (y - 1 >= 0 && move(x, y - 1)) q.push({ x,y - 1,step+1 });
		}

		return -1;
	}
};

int main() {
	Solution sln;
	vector<vector<char>> maze = {
		{'+', '.', '+', '+', '+', '+', '+'},
		{'+', '.', '+', '.', '.', '.', '+'},
		{'+', '.', '+', '.', '+', '.', '+'},
		{'+', '.', '.', '.', '.', '.', '+'},
		{'+', '+', '+', '+', '.', '+','.'}};//{ {".","+"} };//{ {'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'} };
    vector<int> entrance = { 0,1 };
	cout << sln.nearestExit(maze, entrance) << endl;
	return 0;
}