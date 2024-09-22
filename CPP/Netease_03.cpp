/*
天赋树
激活天赋点需要  中级+高级  材料，其中中级需要 X 钻石购买，高级需要 Y 钻石购买。
高级材料也可用 天赋自选包 激活。
问有A钻石和B天赋自选包，求最大增加能力值？

输入：
n		天赋节点数
X Y		分别为购买中级、高级材料的钻石数
A B		分别为初始钻石数、天赋自选包数
n-1个Pi 代表天赋节点i必须激活的的节点，树，P2开始
n行 ti ai bi 其中ti表示该天赋点需要的材料类型，a为需要材料数，b为增加能力值
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	// 题型：树、背包 解法：BFS 贪心 DP
//	int getMaxGiftPoint() {
//		
//	}
//};
//
//int main() {
//	Solution sln;
//	int n, X, Y, A, B;
//	cin >> n >> X >> Y >> A >> B;
//	vector<int> P(n, 0);
//	for (int i = 1; i < n; i++) {
//		cin >> P[i];
//	}
//	vector<vector<int>> t(n, { 0,0,0 });
//	for (int i = 1; i < n; i++) {
//		cin >> t[i][0] >> t[i][1] >> t[i][2];
//	}
//
//	return 0;
//}