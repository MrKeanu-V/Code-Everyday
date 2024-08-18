/*
LeetCode 2858 困难 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/* DFS+树状DP */

void printResult(const vector<int>& edges){
	for(auto & edge:edges){
		cout<<" "<<edge<<" ";
	}
	cout<<endl;
}

class Solution {
public:
	// 递归DFS 
	vector<int> result;
	vector<vector<pair<int, int> > > graph;
	
	void dfs(int root, int parent){
		for(auto &child:graph[root]){
			if(child.first==parent)	continue;
			result[0]+=child.second;
			dfs(child.first, root);
		}
	}
	
	void reroot(int root, int parent){
		for(auto &child:graph[root]){
			if(child.first==parent)	continue;
			if(child.second)	
				result[child.first] += result[root] - 1;
			else result[child.first] += result[root] + 1;
			reroot(child.first, root);
		}
	}
	
	vector<int> minEdgeReversals(int n, vector<vector<int> >& edges){
		// 初始化
		result.resize(n);
		graph.resize(n);
		
		for(auto &e : edges){
			graph[e[0]].emplace_back(make_pair(e[1], 0));	// 与push_back的区别是，就地声明，不会复制 
			graph[e[1]].emplace_back(make_pair(e[0], 1));
		}
		
		dfs(0, -1);
		reroot(0, -1);
		
		return result;
	}
	
	// 递推BFS 
	vector<int> minEdgeReversalsSolution2(int n, vector<vector<int> >& edges){
		vector<int> result(n);
		vector<vector<pair<int, int> > > graph(n);
		
		for(auto &e : edges){
			graph[e[0]].emplace_back(e[1], 1);
			graph[e[1]].emplace_back(e[0], -1);
		}
		
		queue<int> bfs;
		bfs.push(0);
		vector<int> visied(n, 0);
		visied[0]=1;
		while(!bfs.empty()){
			int root=bfs.front();
			bfs.pop();
			for(auto &node : graph[root]){
				if(visied[node.first])	continue;
				result[0]+=node.second<0;
				bfs.push(node.first);
				visied[node.first]=1;	
			}
		}
		
		visied.clear();
		visied.resize(n);
		bfs.push(0);
		visied[0]=1;
		
		while(!bfs.empty()){
			
			int root=bfs.front();
			bfs.pop();
			for(auto &node : graph[root]){
				if(visied[node.first]) continue;
				result[node.first]+=result[root]+node.second;
				bfs.push(node.first);
				visied[node.first]=1;
			}
		}
		
		return result;
	}
	
//	vector<int> result;
//	vector<vector<pair<int, int> > > graph;
//	
//	void dfs(int root,  int parent){
//		for(auto &node : graph[root]){
//			if(node.first!=parent){
//				result[0] += node.second;
//				dfs(node.first, root);
//			}
//		}
//	}
//	
//	void reroot(int root, int parent){
//		for(auto &node : graph[root]){
//			if(node.first!=parent){
//				if(node.second)	// 变化量 
//					result[node.first]+=result[root]-1;
//				else
//					result[node.first]+=result[root]+1;
//				
//				reroot(node.first, root);
//			}
//		}
//	}
	
//	// 换根DP reroot 树形DP 
//	vector<int> minEdgeReversals(int n, vector<vector<int> >& edges){
//		graph.resize(n);
//		result.resize(n);
//		
//		for(auto &e : edges){
//			graph[e[0]].emplace_back(e[1], 0);
//			graph[e[1]].emplace_back(e[0], 1);
//		}
//
//		dfs(0,-1);
//		reroot(0, -1);
//		
//		return result;
//	}
	
	// 暴力BFS 超时 
	vector<int> minEdgeReversalsOri(int n, vector<vector<int> >& edges){
		vector<int> result(n, 0);
		
		unordered_map<int, vector<pair<int, int> > > graph;
		for(auto &edge:edges){
			graph[edge[0]].push_back(make_pair(edge[1], 0));
			graph[edge[1]].push_back(make_pair(edge[0], 1));
		}
		
		// 指数级 
		for(int i=0;i<n;i++){
			unordered_set<int> visied;
			queue<int> bfs;
			int ans=0;
			
			bfs.push(i);
			visied.insert(i);
			
			while(!bfs.empty()){
				int source=bfs.front();
				bfs.pop();
				for(auto& node:graph[source]){
					if(visied.count(node.first)){
						continue;
					}
					bfs.push(node.first);
					visied.insert(node.first);
					ans += node.second;
				}
				
			}
			
			result[i]=ans;
		}
		
		return result;
	} 
};

int main(){
	int n=4;
	vector<vector<int>> edges = {
		{2,0},{2,1},{1,3}
//		{2,1},{1,3},{2,3},{4,0},{4,5}
    };
	
	Solution solution;
	printResult(solution.minEdgeReversals(n, edges));
	
	return 0;
}

