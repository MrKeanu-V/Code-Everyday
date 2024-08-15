/*
LeetCode 174地下城游戏
思路一：动态规划 逆向（二维动规都考虑逆向，解决后无效性） 
思路二：BFS + 记忆化搜索 
*/
//#include<stdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/* 动态规划+逆向 */ 

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        
        dp[m][n-1]=dp[m-1][n]=1;
        for(int i=m-1;i>=0;--i){
        	for(int j=n-1;j>=0;--j){
        		int minHp = min(dp[i+1][j], dp[i][j+1]);
				dp[i][j] = max(minHp-dungeon[i][j], 1);
			}
		}
		
		return dp[0][0];
    }
};

int main(){
	vector<vector<int> > dungeon;
    vector<int> p0, p1, p2;
    p0.push_back(-2);
	p0.push_back(-3);
	p0.push_back(3);
	p1.push_back(-5);
	p1.push_back(-10);
	p1.push_back(1);
	p2.push_back(10);
	p2.push_back(30);
	p2.push_back(-5);
	dungeon.push_back(p0);
	dungeon.push_back(p1);
	dungeon.push_back(p2);

	
	Solution solution;
	printf("%d\n", solution.calculateMinimumHP(dungeon));
	
	return 0;
}

