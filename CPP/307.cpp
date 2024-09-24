/*
307. Range Sum Query - Mutable (Mutable Segment Tree) medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// �߶��� �� ��״����
/*
�߶�������״��������
1. ��״������߶�������������������������������ݽṹ������״�����ڿռ临�Ӷ��������߶������߶�����ʱ�临�Ӷ���������״���顣
2. ��״�����ڴ������޸�ʱ��ʱ�临�Ӷ���O(logn)���ڴ��������ѯʱ��ʱ�临�Ӷ���O(logn)��
3. �߶����ڴ������޸�ʱ��ʱ�临�Ӷ���O(logn)���ڴ��������ѯʱ��ʱ�临�Ӷ���O(logn)��
4. ��״�����еĲ������߶���һ���У����߶����еĲ�������״���鲻һ���С�
5. ��״����Ĵ���ʵ�ֱ��߶����̣�˼ά�������ٶ�Ҳ���졣

�ܽ᣺ ��״�����ʺϴ������޸ĺ������ѯ�����⣬�߶����ʺϴ��������޸ĺ������ѯ�����⡣

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
		for (; i > 0; i -= lowbit(i))	//lowbit: i&=-i; ����: i+-=lowbit(i)
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