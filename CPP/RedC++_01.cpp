/*
С����C++����1
С�������ƥ��
С������µ�iƪ��һ��������ai��С����Ϊ�����ƪ��ͬ�����µĵ�����ͨ��λ�������Ľ��Ϊk����ô����ƪ���������Ƶģ���ai xor aj == k��
����С���ռ�����nƪ���£�����֪���ж��ٶԲ�ͬ�����������Ƶģ�����������
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	// �����ⷨ
	//int getSimilarity(vector<int>& a, int k) {
	//	int ans = 0;
	//	for (int i = 0; i < a.size(); i++) {
	//		for (int j = i + 1; j < a.size(); j++) {
	//			if ((a[i] ^ a[j]) == k) {
	//				ans++;
	//			}
	//		}
	//	}
	//	return ans;
	//}
	// ��ϣ�� 91% WA
	int getSimilarity(vector<int>& a, int k) {
		int ans = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < a.size(); i++) {
			int like = a[i];
			int xorRes = like ^ k;
			if (m.count(xorRes)) {
				ans += m[xorRes];
			}
			m[like]++;
		}
		return ans;
	}
};

//int main() {
//	//int n, k;
//	//cin >> n >> k;
//	//vector<int> a(n);
//	//for (int i = 0; i < n; i++) {
//	//	cin >> a[i];
//	//}
//	vector<int> a = { 1, 1, 2, 3, 4, 5 };
//	int k = 5;
//	Solution s;
//	cout << s.getSimilarity(a, k) << endl;
//	return 0;
//}