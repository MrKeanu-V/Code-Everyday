#pragma once

/*
3095. Shortest Subarray With Or At Least K	[Easy - 2]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <functional>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum |= nums[j];
                if (sum >= k) res = min(res, j - i + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    void test() {
        Solution sln;
        vector<int> nums = { 1,2,3 };
        cout << sln.minimumSubarrayLength(nums, 2) << endl;
        nums = { 2,1,8 };
        cout << sln.minimumSubarrayLength(nums, 10) << endl;
        nums = { 2,1 };
        cout << sln.minimumSubarrayLength(nums, 0) << endl;
    }
};
