/*
小红书C++笔试2
魔法阅读室
小红书总部有一家神奇的魔法阅读室，它四四方方的，三边长为x，y和z。在三维空间里，我们假定它占了(0,0,0) 到(x,y,z)的空间。该魔法空间没有重力，阅读桌可以放在任何位置。
现在，大家购买了一张体积为k，边长可以为任意正整数的魔法桌，魔法桌可以放在魔法阅读室的任意位置，但必须保证魔法桌的四个角都在魔法阅读室的空间内。
请你求出魔法桌在所有可能的边长选取情况下（旋转桌子也视为一种摆放方式），找到全部三种方向里摆放方式数量最多的那一种。
输入描述：
第一行为T，表示有T组数据。
每组数据包含一行，有四个整数x,y,z,k，分别表示魔法阅读室的尺寸，和桌子的体积。
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
	int countWays(int x, int y, int z, int a, int b, int c) {
		int count = 0;
		if (a <= x && b <= y && c <= z) count++;
		if (b <= x && c <= y && a <= z) count++;
		if (c <= x && a <= y && b <= z) count++;
		return count;
	}
	// 以魔法桌边长可能情况为key，以摆放方式数量为value
	int magicTable(int x, int y, int z, int k) {
		int maxCount = 0;
		for (int a = 1; a * a * a <= k; a++)	// 第一个方向边长
		{
			if (k % a != 0) continue;
			for (int b = 1; a * b * b <= k; b++)	// 第二个方向边长{
			{
				if (k % (a * b) == 0) {
					int c = k / (a * b);
					int count = countWays(x, y, z, a, b, c);
					maxCount = max(maxCount, count);
				}
			}
		}
   		return maxCount;
	}
};

int main() {
	int T;
	cin >> T;
	Solution s;
	while (T--) {
		int x, y, z, k;
		cin>> x >> y >> z >> k;
		cout<< s.magicTable(x, y, z, k) << endl;
	}
	return 0;
}