/*
200. Number of Islands [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
���鼯��
1. ���鼯��һ�����ε����ݽṹ�����ڴ���һЩ���ཻ���ϵĺϲ�����ѯ���⡣
2. ���鼯ͨ����������������1��find��ȷ��Ԫ�������ĸ����ϣ�2��union�����������Ϻϲ�Ϊһ�����ϡ�
3. ���鼯ͨ��������ʵ�֣�������ÿ��Ԫ�ش���һ�������е�һ��Ԫ�أ�ÿ��Ԫ�ض���һ��ָ��Ԫ�ص�ָ�룬��Ԫ�صĸ�Ԫ��ָ���Լ���
*/

// ���鼯ģ��
class UnionFind {
public:
	// ��ʼ�����鼯
	UnionFind(vector<vector<char>>& grid) {
		count = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
					count++;
				}
				else {
					parent.push_back(-1);
				}
				rank.push_back(0);
			}
		}
	}

	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);	// ·��ѹ��
		return parent[x];
	}

	void unite(int x, int y) {
		int rootx = find(x), rooty = find(y);
		if (rootx != rooty) {
			if(rank[rootx] < rank[rooty])
				swap(rootx, rooty);
			parent[rooty] = rootx;
			if (rank[rootx] == rank[rooty]) rank[rootx]++;
			count--;
		}	
	}

	int getCount() { return count; }
private:
	vector<int> parent; // ���鼯���飬�������飬���游�ڵ�
	vector<int> rank;	// ���ĸ߶�
	int count; // ����ͨ��������
};

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int mr = grid.size(), mc = grid[0].size();
		if (!mr || !mc) return 0;

		UnionFind uf(grid);
		for (int r = 0; r < mr; r++) {
			for (int c = 0; c < mc; c++) {
				if (grid[r][c] == '1') {
					grid[r][c] = '0';	// visited
					if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * mc + c, (r - 1) * mc + c);	// �ϲ�
					if (r + 1 < mr && grid[r + 1][c] == '1') uf.unite(r * mc + c, (r + 1) * mc + c);
					if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * mc + c, r * mc + c - 1);
					if (c + 1 < mc && grid[r][c + 1] == '1') uf.unite(r * mc + c, r * mc + c + 1);
				}
			}
		}
		return uf.getCount();
	}
};

int main() {
	Solution sln;
	vector<vector<char>> grid = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
	cout << sln.numIslands(grid) << endl;
	return 0;
}