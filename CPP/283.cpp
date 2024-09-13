/*
LeetCode 283. �ƶ��� ��
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    // �ⷨһ��ģ��
    void moveZeroes1(vector<int>& nums) {
        vector<int> zeros;
        for (int i = 0; i < nums.size();i++) {
            if (nums[i] != 0) {
                zeros.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i]=(i<zeros.size())?zeros[i]:0;
        }
    }

    // �ⷨ����˫ָ��
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }

    // �ⷨ��������
    void moveZeroes3(vector<int>& nums) {
                
    }
};

int main() {
    Solution s;
    vector<int> nums = { 0,1,0,3,12, 0 };
    //vector<int> nums = { 0,0,1 };
    s.moveZeroes(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
	return 0;
}