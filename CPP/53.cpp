/*
LeetCode 53 中等 最大数组和 
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	// 解法一 动规 
    int maxProfitDP(vector<int>& nums) {
		vector<int> dp(nums.size(),0);
		dp[0]=nums[0];
		int result=dp[0];
		
		for(int i=1;i<nums.size();i++){
			dp[i]=max(nums[i],nums[i]+dp[i-1]);
			result=max(result, dp[i]);
		} 
		
		return result;
    }
    // 解法二 前缀和 
	int maxProfitPrefix(vector<int> &nums) {
		int result=INT_MIN,minPreSum=0,preSum=0;

        for(int num:nums){
            preSum += num;
            result = max(result, preSum - minPreSum);   // 最大子数组和相当于和缀和，即等于前缀和-最小前缀和
            minPreSum = min(minPreSum, preSum);
        }
        return result;
	}
	// 解法三 分治
	int maxProfit(vector<int> &nums){
		// 分治太麻烦了，前缀和实现这类型子区间和更合适 
	} 
};

int main(){
	vector<int> nums={
		-2,1,-3,4,-1,2,1,-5,4
	};
	
	Solution solution;
	cout<<solution.maxProfitDP(nums)<<endl;
	
	return 0;
}

