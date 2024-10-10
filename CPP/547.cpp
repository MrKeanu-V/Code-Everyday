/*
547. Number of Provinces [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
	// �ؼ����ڣ�next��Base Case������һ�������ͱ߽�����
	void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
		//if (visited[i]) return;
		//visited[i] = true;
		for (int j = 0; j < isConnected.size(); j++) {
			if (isConnected[i][j] && !visited[j]) {
				visited[i] = true;
				dfs(isConnected, visited, j);
			}
		}
	}
public:
	// �ⷨһ BFS
	int findCircleNum1(vector<vector<int>>& isConnected) {
		int n = isConnected.size(), cnt = 0;
		vector<bool> visited(n, false);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				q.push(i);
				while (!q.empty()) {
					int j = q.front();
					q.pop();
					for (int k = 0; k < n; k++) {
						if (isConnected[j][k] && !visited[k]) {
							visited[k] = true;
							q.push(k);
						}
					}
				}
				cnt++;
			}
		}
		return cnt;
	}

	// �ⷨ�� DFS
	int findCircleNum2(vector<vector<int>>& isConnected) {
		int n = isConnected.size(), cnt = 0;
		vector<bool> visited(n, false);
		
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(isConnected, visited, i);
				cnt++;
			}
		}

		return cnt;
	}
	/*
	���鼯��
	1. ���鼯��һ�����ε����ݽṹ�����ڴ���һЩ���ཻ���ϵĺϲ�����ѯ���⡣
	2. ���鼯ͨ����������������1��find��ȷ��Ԫ�������ĸ����ϣ�2��union�����������Ϻϲ�Ϊһ�����ϡ�
	3. ���鼯ͨ��������ʵ�֣�������ÿ��Ԫ�ش���һ�������е�һ��Ԫ�أ�ÿ��Ԫ�ض���һ��ָ��Ԫ�ص�ָ�룬��Ԫ�صĸ�Ԫ��ָ���Լ���
	*/
	int find(vector<int>& parent, int x) {	// һ����findʱ�������·��ѹ��
		if (parent[x] != x) parent[x] = find(parent, parent[x]);	// �ݹ�·��ѹ��
		return parent[x];
	}
	void unite(vector<int>& parent, int x, int y) {
		parent[find(parent, x)] = find(parent, y);
	}
	// �ⷨ�� ���鼯
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size(), cnt = 0;
		// ��ʼ�����鼯
		vector<int> parent(n);
		for(int i=0;i<n;i++) parent[i] = i;

		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
				if (isConnected[i][j]) unite(parent, i, j);
		// ͳ�Ƽ��ϸ���
		for (int i = 0; i < n; i++)
			if (parent[i] == i) cnt++;
		return cnt;
	}
};

int main() {
	Solution sln;
    vector<vector<int>> isConnected = { {1,1,0},{1,1,0},{0,0,1} };
	cout << sln.findCircleNum(isConnected) << endl;
	return 0;
}