/*
描述：10款游戏ID1-10，n名玩家参与投票
投票规则：
	玩家需要体验3款游戏才能投票
	只能给体验过的游戏投票
	最大可投票数量=体验游戏数量-2，上限5票
	若玩家体验游戏<3 || 投票数量>5(>t-2) 投票无效
输入：
	第一行n
	后面n行为10个数字，0未体验 1体验过 2体验并投票
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//void printVector(const vector<int>& ans) {
//	for (auto& e : ans) {
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//class Solution {
//public:
//	// 题型：查询  解法：模拟
//	vector<int> getPopularGame(int n) {
//		vector<int> vote(10, 0);
//		vector<int> res;
//		for (int i = 0; i < n; i++) {
//			int tcount=0, vcount=0;	// 体验数量、投票数量
//			vector<int> onceVote(10, 0);
//			for (int j = 0; j < 10; j++) {
//				int temp;
//				cin >> temp;
//				if (temp == 2) {
//					vcount++;
//					onceVote[j] = 1;
//				}
//				else if (temp == 1) {
//					tcount++;
//				}
//			}
//			// 有效判断
//			tcount += vcount;
//			if (tcount < 3 || vcount>5 || vcount > tcount - 2) {
//				continue;
//			}
//			// 更新
//			for (int j = 0; j < 10; j++)
//				vote[j] += onceVote[j];
//		}
//		// 最高票数
//		int maxcnt = 0;
//		for (int e : vote)
//			maxcnt = max(maxcnt, e);
//		for (int i = 0; i < 10; i++) {
//			if (vote[i] == maxcnt)
//				res.push_back(i+1);
//		}
//
//		return res;
//	}
//};
//
//int main() {
//	Solution sln;
//	int n;
//	cin >> n;
//	vector<int> ans = sln.getPopularGame(n);
//	printVector(ans);
//	return 0;
//}