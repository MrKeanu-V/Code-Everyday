/*
LeetCode 121 �� ������Ʊ�����ʱ��
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	// �ⷨһ ̰�� 
    int maxProfit(vector<int>& prices) {
		int l=0, profit=0;
		
		for(int i=1;i<prices.size();i++){
			if(prices[i]<prices[l]){
				l = i;
			}
			if(profit<prices[i]-prices[l]){
				profit=prices[i]-prices[l];
			}
			
		}
		
		return profit;
    }
    // �ⷨ�� ����
	int maxProfitDP(vector<int> &prices) {
		int cost = INT_MAX, profit=0;
		
		for(int &price:prices){
			cost = min(cost, price);
            profit = max(profit, price-cost);			
		}
		
		return profit;
	} 
};

int main(){
	vector<int> prices={
//		7,1,5,3,6,4
8,9,7,3,7
	};
	
	Solution solution;
	cout<<solution.maxProfitDP(prices)<<endl;
	
	return 0;
}

