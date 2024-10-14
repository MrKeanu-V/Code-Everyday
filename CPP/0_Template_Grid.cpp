/*
	网格图：
	1. 网格图是一种数据结构，用于表示二维空间中的点或区域，可用于表示地图、棋盘、图像等。
	2. 网格图由行和列组成，每个行和列的交点称为一个网格点，每个网格点可以存储一个值。
	3. 网格图题型常见涉及遍历、搜索、路径规划等算法问题，如迷宫问题、八皇后问题、骑士周游问题等，常用做法为DFS、BFS、动态规划等。

	二叉树 vs 网格图 vs 一般图
			  重复访问	  邻居个数			DFS				BFS
	二叉树	|	否		|	≤3		|	前中后序		|	层序
	网格图	|	是		|	≤8		|	连通块			|	最短路
	一般图	|	是		|	任意	|	连通块、判环等	|	最短路等

	网格图遍历：
    	1. DFS：深度优先搜索，从某个点开始，沿着一个方向一直走到底，然后回溯，再沿着另一个方向走到底
    	2. BFS：广度优先搜索，从某个点开始，先访问所有相邻的点，再访问这些点的相邻点，依次类推
    	3. 双向BFS：从起点和终点同时进行BFS，直到两者相遇
    	4. A*：A*算法是一种启发式搜索算法，用于求解最短路径问题，它结合了DFS和BFS的优点，可以快速找到最优解
		无论是哪种搜索方法，核心都在于Base Case和Next Case，即如何判断是否到达终点，以及如何找到下一个要访问的点
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
		
		// 8 directions
		//for (int dx = i-1; dx <= i+1; dx++) 
		//	for (int dy = j-1; dy <= j+1; dy++)
		//		dfs(dx, dy);
	}
};