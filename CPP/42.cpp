/*
LeetCode 42. Trapping Rain Water Hard 接雨水 困难
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    // 解法一：双指针
    int trap(vector<int>& height) {
        int sum = 0;
        int left=0,right=height.size()-1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
           leftMax= max(leftMax, height[left]);
           rightMax = max(rightMax, height[right]);
           if (leftMax < rightMax) {
               sum += leftMax - height[left];
               left++;
           }
           else {
               sum += rightMax - height[right];
               right--;
           }
        }

        return sum;
    }
};

int main() {
    Solution s;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << s.trap(height) << endl;
    return 0;
}
