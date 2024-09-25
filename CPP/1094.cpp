/*
1094. Car Pooling Medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
* �����������
* ����������Ҫ���ó�����Ƶ����ԭʼ�����ĳ�������Ԫ�ؽ���������
* 1�� ��������ǰ׺�����鼴Ϊԭ����
* 2�� ���������Կ��ٽ������������Ĳ�����ԭ����i~j��������val���������diff[i]����val��diff[j+1]����val
*/

class Solution {
public:
	// �ⷨһ ���
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int diff[1001]{0}, curCapacity = capacity;
		for (auto& t : trips) {
			diff[t[1]] -= t[0];
			diff[t[2]] += t[0];
		}
		for (int value : diff) {
			curCapacity += value;
			if (curCapacity < 0) return false;
		}
		return true;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> trips = { {2,1,5},{3,3,7} };
	int capacity = 4;
	cout << sln.carPooling(trips, capacity) << endl;
	return 0;
}