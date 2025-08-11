/*
207. Course Schedule [Medium - 4]
*/
#include "pub_template.h"

class Solution
{
private:
	vector<vector<int>> adjList;
	vector<int> visited;
	bool isValid = true;

	void dfs(int node) {
		visited[node] = 1;
		for (int v : adjList[node]) {
			if (visited[v] == 0) dfs(v);
			else if (visited[v] == 1) { isValid = false; return; }
		}
		visited[node] = 2;
	}
public:
	// Solution1: DFS Time: O(V+E) Space: O(V+E)
	// 本质上是判断有向图是否存在环，解决思路：1. 构建邻接表 2. DFS遍历图，判断是否存在环
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		adjList.clear(), visited.clear();	// local use need to clear, resize() do not reset value
		adjList.resize(numCourses);
		visited.resize(numCourses, 0);	// 0: unvisited, 1: visiting, 2: visited
		for (const auto& edge : prerequisites) adjList[edge[1]].push_back(edge[0]);
		for (int idx = 0; idx < numCourses && isValid; ++idx) {
			if (visited[idx] == 0) dfs(idx);
		}
		return isValid;
	}

	void test() {
		int numCourses = 2;
		vector<vector<int>> prerequisites = { {1,0} };
		if (canFinish(numCourses, prerequisites)) cout << "true" << endl;
		else cout << "false" << endl;

		numCourses = 2;
		prerequisites = { {1,0},{0,1} };
		if (canFinish(numCourses, prerequisites)) cout << "true" << endl;
		else cout << "false" << endl;
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}