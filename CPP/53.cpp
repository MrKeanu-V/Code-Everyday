/*
LeetCode 53 �е� �������� 
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
	// �ⷨһ ���� 
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
    // �ⷨ�� ǰ׺�� 
	int maxProfitPrefix(vector<int> &nums) {
		int result=INT_MIN,minPreSum=0,preSum=0;

        for(int num:nums){
            preSum += num;
            result = max(result, preSum - minPreSum);   // �����������൱�ں�׺�ͣ�������ǰ׺��-��Сǰ׺��
            minPreSum = min(minPreSum, preSum);
        }
        return result;
	}
	// �ⷨ�� ����
	int maxProfit(vector<int> &nums){
		// ����̫�鷳�ˣ�ǰ׺��ʵ��������������͸����� 
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

