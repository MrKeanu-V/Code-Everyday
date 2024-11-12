/*
���룺
1��n ��ʾ�������
2n������ ��ʾ������������
4������  ��ʾ���������յ�����
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <utility> // pair
using namespace std;

struct Point {
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
	// �ⷨһ ��ѧģ��
	int getMaxKilledMonsters(int n, vector<int>& monsters, vector<int>& laser) {
		// б��
		auto getSlope = [&](int x1, int y1, int x2, int y2)->double {
			if (x1 == x2) return y2 - y1 > 0 ? INT_MAX : INT_MIN;
			return (double)(y2 - y1) / (x2 - x1);
		};
		double slope = getSlope(laser[0], laser[1], laser[2], laser[3]);
		int res = 0;
		for (int i = 0; i < n; i++) {
			double temp = getSlope(laser[0], laser[1], monsters[i * 2], monsters[i * 2 + 1]);
			// б�����||������||б�ʲ�����
			if (monsters[i * 2] == laser[0] && monsters[i * 2 + 1] == laser[1]) {
				res++;
				continue;
			}
			if (slope == temp) {

			}
		}
		return res;
	}
};

int test() {
	/*
	example 1:
		3
		0 2 2 3 -1 4
		1 0 0 2
	*/
	Solution sln;
	int n = 3;
	vector<int> monsters = { 0, 2, 0, -3, 0, 4 };  //{ 0, 2, 2, 3, -1, 4 };
	vector<int> laser = { 0,-1,0,8 }; //{1, 0, 0, 2};
	cout << sln.getMaxKilledMonsters(n, monsters, laser) << endl;
	return 0;
}

int main() {
	//Solution sln;
	//int n;
	//cin >> n;
	//vector<int> monsters(n * 2);
	//for (int i = 0; i < n; i++) {
	//	cin >> monsters[i] >> monsters[i + 1];
	//}
	//vector<int> laser(4);
	//cin >> laser[0] >> laser[1] >> laser[2] >> laser[3];
	//cout << sln.getMaxKilledMonsters(n, monsters, laser) << endl;
	//return 0;
    test();
}