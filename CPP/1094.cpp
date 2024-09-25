/*
1094. Car Pooling Medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
* 差分数组性质
* 差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减。
* 1、 差分数组的前缀和数组即为原数组
* 2、 差分数组可以快速进行区间增减的操作，原数组i~j区间增加val，差分数组diff[i]增加val，diff[j+1]减少val
*/

class Solution {
public:
	// 解法一 差分
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