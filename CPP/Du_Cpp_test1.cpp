// 得物 25秋招算法工程师C++

/*

对于一个仅有左括号(和右括号)组成的字符串，求其最长合法前缀的长度。
对于某一前缀，定义当且仅当该前缀存在一种拆分方案，可以将该前缀拆分为若干对匹配的括号
 输入
  

*/
 
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include<iostream>
using namespace std;

// 双指针 
// (()))

int main(){
	int n, count=0, maxLen=0, result=0;
	cin>>n;
	char temp;
	for(int i=0;i < n;i++){
		cin>>temp;
		if(temp=='('){
			count++;
		}		
		else{
			count--;
			maxLen++;
			if(count<0){
				count=0;
				maxLen=0;
			}

			result = max(result, maxLen*2);
			
		}
	}
	
	cout << result; 
	
	return 0;
} 
