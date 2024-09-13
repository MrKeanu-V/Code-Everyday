/*
LeetCode 15. 三数之和 中等
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
	// 解法一：暴力法 超时
	vector<vector<int>> threeSum1(vector<int>& nums) {
		vector<vector<int>> res;
		set<vector<int>> uni_res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-2; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				for (int k = j + 1; k < nums.size(); k++) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						vector<int> temp = { nums[i], nums[j], nums[k] };
						
						if (uni_res.find(temp) == uni_res.end()) {
							uni_res.insert(temp);
							res.push_back(temp);
						}
					}
				}
			}
		}

		return res;
	}

	// 解法二：双指针 + 排序
	vector<vector<int>> threeSum2(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				if (left > i + 1 && nums[left] == nums[left - 1]) left++;
				else if(right<nums.size()-1&&nums[right]==nums[right+1]) right--;
				else if (nums[i] + nums[left] + nums[right] < 0) left++;
				else if (nums[i] + nums[left] + nums[right] > 0) right--;
				else {
					res.push_back({ nums[i], nums[left], nums[right] });
					left++;
					right--;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { -2,0,0,2,2 };
	vector<vector<int>> res = s.threeSum2(nums);
    for (auto& r : res) {
        for (auto& n : r) {
            cout << n << " ";
        }
        cout << endl;
    }
	return 0;
}
