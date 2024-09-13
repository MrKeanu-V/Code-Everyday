/*
给定一个十六进制数n,但是该整数不会出现A, B, C, D, E, F以外的数字。已知，数字A ~ F依次代表代表十到十五。
当n用八进制表示时,输出出现次数最多的数字。
如果有多个这样的数字，则按升序输出。
*/ 
/*
当n用八进制表示时，输出出现次数最多的数字。如果有多个这样的数字，则按升序输出
样例 
AA
2

ABCD
1 5
*/
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include<iostream>
using namespace std;

int getBestString(string& chars, int n, int k){
	
}

int main(){
	int n, k;
	cin>>n>>k;
	char chars[n];
    for(int i=0;i<n;i++){
    	cin>>chars[i];
	}
	
	cout<<endl;
	for(int i=0;i<n;i++){
    	cout<<chars[i];
	}
}

