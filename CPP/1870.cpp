/*
1870. Minimum Speed to Arrive on Time [Medium - 1676]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

class Solution {
public:
	// 解法一 暴力模拟 TLE
	int minSpeedOnTime1(vector<int>& dist, double hour) {
		int n = dist.size(), max_dist = *max_element(dist.begin(), dist.end());

		for (int speed = 1; speed <= max_dist; speed++) {
			double total_time = 0;
			for (int i = 0; i < n - 1; i++) {
				total_time += (dist[i] + speed - 1) / speed;
			}
			total_time += dist[n - 1] / double(speed);
			if (total_time <= hour) return speed;
		}

		return -1;
	}
    // 解法二 二分查找 注意浮点数精度丢失问题
	int minSpeedOnTime2(vector<int>& dist, double hour) {
		int n = dist.size(), left = 1, right = INT_MAX;

		function<bool(int)> check = [&](int speed)->bool {
			double time = 0;
			for (int i = 0; i < n - 1; i++) {
				// 向上取整优化：当a和b都为正整数时，有 (a + b - 1) / b = (a-1)/b + 1
				time += (dist[i] + (unsigned int)speed - 1) / speed; // int向上取整，此处必须使用无符号整形，因为初始speed会很大
				if (time > hour) return false;
			}
			time += dist[n - 1] / double(speed);
			return time <= hour;
		};

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (!check(mid)) left = mid + 1;
			else right = mid;
		}

		return check(left) ? left : -1;
	}
	// 解法三 二分查找 细节优化：https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/solutions/791209/bi-mian-fu-dian-yun-suan-de-xie-fa-by-en-9fc6
	int minSpeedOnTime(vector<int>& dist, double hour) {
		int n = dist.size();
		long long h100 = round(hour * 100); // 防止浮点数精度丢失，hour仅有两位小数，所以放大100倍
		long long delta = h100 - (n - 1) * 100; // 需要补足的小数部分
		if (delta <= 0) return -1; // 小数部分小于0，说明hour小于n-1，无法到达

		int max_dist = *max_element(dist.begin(), dist.end()); // ranges::max_element(dist);
		if (h100 <= n * 100) return max(max_dist, (int)((dist.back() * 100 - 1) / delta + 1)); // n-1<hour<=n的特殊情况：要么速度为max_dist，要么速度为delta的补足值
		function<bool(int)> check = [&](int speed)->bool {
			long long time = 0;
			for (int i = 0; i < n - 1; i++) time += (dist[i] - 1) / speed + 1;
			return (time * speed + dist[n - 1]) * 100 <= h100 * speed;
		};

		// 二分查找边界 细节优化
		long long sum_dist = reduce(dist.begin(), dist.end(), 0LL);
		int left = (sum_dist * 100 - 1) / h100;
		int h = h100 / (n * 100);
		int right = (max_dist - 1) / h + 1;

		while (left + 1 < right) {
			int mid = (left + right) / 2;
			(check(mid) ? right : left) = mid;
		}

		return right;
	}
};

int main() {
	Solution sln;
	vector<int> dist = { 1, 1, 100000 };
	double hour = 2.01;
	cout << sln.minSpeedOnTime(dist, hour) << endl;
	return 0;
}