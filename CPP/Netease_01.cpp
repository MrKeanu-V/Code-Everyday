/*
������10����ϷID1-10��n����Ҳ���ͶƱ
ͶƱ����
	�����Ҫ����3����Ϸ����ͶƱ
	ֻ�ܸ����������ϷͶƱ
	����ͶƱ����=������Ϸ����-2������5Ʊ
	�����������Ϸ<3 || ͶƱ����>5(>t-2) ͶƱ��Ч
���룺
	��һ��n
	����n��Ϊ10�����֣�0δ���� 1����� 2���鲢ͶƱ
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
//	// ���ͣ���ѯ  �ⷨ��ģ��
//	vector<int> getPopularGame(int n) {
//		vector<int> vote(10, 0);
//		vector<int> res;
//		for (int i = 0; i < n; i++) {
//			int tcount=0, vcount=0;	// ����������ͶƱ����
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
//			// ��Ч�ж�
//			tcount += vcount;
//			if (tcount < 3 || vcount>5 || vcount > tcount - 2) {
//				continue;
//			}
//			// ����
//			for (int j = 0; j < 10; j++)
//				vote[j] += onceVote[j];
//		}
//		// ���Ʊ��
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