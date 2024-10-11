/*
	����ͼ��
	1. ����ͼ��һ�����ݽṹ�����ڱ�ʾ��ά�ռ��еĵ�����򣬿����ڱ�ʾ��ͼ�����̡�ͼ��ȡ�
	2. ����ͼ���к�����ɣ�ÿ���к��еĽ����Ϊһ������㣬ÿ���������Դ洢һ��ֵ��
	3. ����ͼ���ͳ����漰������������·���滮���㷨���⣬���Թ����⡢�˻ʺ����⡢��ʿ��������ȣ���������ΪDFS��BFS����̬�滮�ȡ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Grid {
private:
	int rows, cols;
	vector<vector<int>> grid;
	vector<vector<int>> dirs = { {0,1},{0,-1},{1,0},{-1,0} };
public:
	Grid(int rows, int cols) :rows(rows), cols(cols) { grid.resize(rows, vector<int>(cols, 0)); }
	Grid(const vector<vector<int>>& grid) :grid(grid) { rows = grid.size(); cols = grid[0].size(); }
	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	void bfs() {
		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (!grid[i][j]) continue;
				q.push({ i,j });
				grid[i][j] = 0;
				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					cout << grid[x][y] << " ";	// do something
					if (x - 1 >= 0 && grid[x - 1][y]) q.push({ x - 1,y }), grid[x - 1][y] = 0;
					if (x + 1 < rows && grid[x + 1][y]) q.push({ x + 1,y }), grid[x + 1][y] = 0;
					if (y - 1 >= 0 && grid[x][y - 1]) q.push({ x,y - 1 }), grid[x][y - 1] = 0;
					if (y + 1 < cols && grid[x][y + 1]) q.push({ x,y + 1 }), grid[x][y + 1] = 0;
				}
			}
		}
	}
	void dfs(int i, int j) {
		if (i < 0 || j < 0 || i >= rows || j >= cols || !grid[i][j]) return;
		cout << grid[i][j] << " ";	// do something
		grid[i][j] = 0;	// or visited[i][j]=true;
		for (auto& dir : dirs)
			dfs(i + dir[0], j + dir[1]);
	}
};