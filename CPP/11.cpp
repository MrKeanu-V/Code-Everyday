/*
LeetCode 11. ʢ���ˮ������ �е�
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	// �ⷨһ�������� �ض���ʱ
	int maxArea1(vector<int>& height) {
		int maxRes = 0;
		for (int i = 0; i < height.size(); i++) {
			for (int j = i + 1; j < height.size(); j++) {
				maxRes = max(maxRes, min(height[i], height[j]) * ((j - i)));
			}
		}
		return maxRes;
	}

	// �ⷨһ��˫ָ��
	int maxArea2(vector<int>& height) {
		int maxRes = 0, left = 0, right = height.size() - 1;

		while (left < right) {
			maxRes = max(maxRes, min(height[left], height[right]) * (right - left));
			if (height[left] < height[right]) {
				left++;
			}
			else {
				right--;
			}
		}

		return maxRes;
	}
};

int main() {
	Solution s;
   	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	//vector<int> height = { 1,1 };
    cout << s.maxArea2(height);
   	return 0;
}