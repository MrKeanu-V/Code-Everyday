/*
875. Koko Eating Bananas [Medium - 1766]
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <ranges>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

/*
����ж�һ�����Ƿ����ʹ�ö��ֲ��ң�
1. ���ֲ���ͨ�����������������в���һ������Χ
2. ���ֲ���ͨ����Ҫ��������������1. Ŀ�꺯�������ԣ�2. �������½磻3. �ܹ�ͨ����������
*/

class Solution {
public:
	// �ⷨһ ���ֲ��� // ������ĿΪ��ģ�⣬��Ҫ������ת��Ϊ���ֲ�������
	int minEatingSpeed1(vector<int>& piles, int h) {
		function<long long(long long)> timeCost = [&](long long speed) {
			long long time = 0;
			for (long long pile : piles) time += pile / speed + (pile % speed != 0);	//����ȡ����(a-1)/b+1
			return time;
		};
		long long left = 1, right = *max_element(piles.begin(), piles.end());
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			if (timeCost(mid) > h) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
	// �ⷨһ ���ֲ����޸�
	int minEatingSpeed(vector<int>& piles, int h) {
		function<bool(long long)> isUnSatisfied = [&](long long speed)->bool {
			long long time = 0;
			for (long long pile : piles) time += (pile - 1) / speed + 1;
			return time > h;
		};
		long long left = 1, right = *max_element(piles.begin(), piles.end());
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			isUnSatisfied(mid) ? left = mid + 1 : right = mid - 1;
		}
		return left;
	}
};

int main() {
	Solution sln;
	vector<int> piles = { 3,6,7,11 };
	int h = 8;
	cout << sln.minEatingSpeed(piles, h) << endl;
	return 0;
}