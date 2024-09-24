/*
307. Range Sum Query - Mutable (Mutable Segment Tree) medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 线段树 或 树状数组
/*
线段树与树状数组区别
1. 树状数组和线段树都是用来处理数组区间问题的数据结构，但树状数组在空间复杂度上优于线段树，线段树在时间复杂度上优于树状数组。
2. 树状数组在处理单点修改时，时间复杂度是O(logn)，在处理区间查询时，时间复杂度是O(logn)。
3. 线段树在处理单点修改时，时间复杂度是O(logn)，在处理区间查询时，时间复杂度是O(logn)。
4. 树状数组有的操作，线段树一定有；但线段树有的操作，树状数组不一定有。
5. 树状数组的代码实现比线段树短，思维清晰且速度也更快。

总结： 树状数组适合处理单点修改和区间查询的问题，线段树适合处理区间修改和区间查询的问题。

*/
class NumArray {
public:
	NumArray(vector<int>& nums) : nums(nums),tree(nums.size()+1) {
		for (int i = 1; i < tree.size(); i++) {
			tree[i] += nums[i - 1];
			int nxt = i + (i & -i);
			if( nxt < tree.size())
				tree[nxt] += tree[i];
		}

	}

	void update(int index, int val) {
		int delta = val - nums[index];
		nums[index] = val;
		for (int i = index + 1; i < tree.size(); i += lowbit(i))
			tree[i] += delta;
	}

	int sumRange(int left, int right) {
		return preSum(right + 1) - preSum(left);
	}
private:
	vector<int> &nums;
	vector<int> tree;

	int lowbit(int i) {
		return i & -i;
	}

	int preSum(int i) {
		int sum = 0;
		for (; i > 0; i -= lowbit(i))	//lowbit: i&=-i; 迭代: i+-=lowbit(i)
			sum += tree[i];
		return sum;
	}
};

int main() {
	vector<int> nums = { 1, 3, 5 };
  	NumArray numArray(nums);
	cout << numArray.sumRange(0, 2) << endl; // return 9
    numArray.update(1, 2);
	cout << numArray.sumRange(0, 2) << endl; // return 8
	return 0;
}