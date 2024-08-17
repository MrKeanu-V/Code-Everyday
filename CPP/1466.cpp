/*
LeetCode 1466 图 搜索 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

/* BFS+排序 */
void  printPoints(const std::vector<std::vector<int> >& points) {
    for (const auto& point : points) {
        for (int value : point) {
            std::cout << value << " ";
        }
        std::cout << std::endl; // 每行后换行
    }
    std::cout << std::endl; // 每行后换行
}

int cmp(const vector<int>& a, const vector<int>& b){
	return a[1]<b[1];
}

class Solution {
public:
	int minReorder(int n, vector<vector<int> >& connections){
		int result=0;
		unordered_map<int, vector<pair<int, int> > > graphs;
						
		for(auto & path:connections){
			graphs[path[0]].push_back(make_pair(path[1], 1));
			graphs[path[1]].push_back(make_pair(path[0], 0));
		}
		
		queue<int> q;
		unordered_set<int> visied;
		
		q.push(0);
		visied.insert(0);
		
		while(!q.empty()){
			int source=q.front();
			q.pop();
			for(auto & node:graphs[source]){
				if(visied.count(node.first)){
					continue;
				}
				q.push(node.first);
				visied.insert(node.first);
				result+=node.second;
			}
		}
		
		return result;
	} 
};

int main(){
	int n=6;
	vector<vector<int>> connections = {
//		{0,1},{1,3},{2,3},{4,0},{4,5}
        {3,9},{7,10},{3,8},{6,8},{9,12},{2,9},{0,9},{3,9},{0,6},{2,8}
    };
	
	Solution solution;
	printf("%d\n", solution.minReorder(n, connections));
	
	return 0;
}

