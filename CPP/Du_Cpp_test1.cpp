// ���� 25�����㷨����ʦC++

/*

����һ������������(��������)��ɵ��ַ�����������Ϸ�ǰ׺�ĳ��ȡ�
����ĳһǰ׺�����嵱�ҽ�����ǰ׺����һ�ֲ�ַ��������Խ���ǰ׺���Ϊ���ɶ�ƥ�������
 ����
  

*/
 
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include<iostream>
using namespace std;

// ˫ָ�� 
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
