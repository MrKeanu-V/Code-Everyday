/*
��һЩ������������һ���� XY ƽ���ʾ��ǽ���ϡ�
ǽ���ϵ������¼���������� points ������points[i] = [xstart, xend] ��ʾˮƽֱ���� xstart �� xend֮��������㲻֪�������ȷ�� y ���ꡣ
һ֧������������ x ��Ӳ�ͬ�� ��ȫ��ֱ �������
������ x �����һ֧��������һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend�� ������  xstart �� x �� xend���������ᱻ ���� ��
��������Ĺ��������� û������ �� ����һ�������֮�󣬿������޵�ǰ����
����һ������ points ����������������������������� ��С ������ ��

 
ʾ�� 1��

���룺points = [[10,16],[2,8],[1,6],[7,12]]
�����2
���ͣ����������2֧��������:
-��x = 6�����������������[2,8]��[1,6]��
-��x = 11�����������������[10,16]��[7,12]��
ʾ�� 2��

���룺points = [[1,2],[3,4],[5,6],[7,8]]
�����4
���ͣ�ÿ��������Ҫ���һ֧�����ܹ���Ҫ4֧����
ʾ�� 3��

���룺points = [[1,2],[2,3],[3,4],[4,5]]
�����2
���ͣ����������2֧��������:
- ��x = 2�����������������[1,2]��[2,3]��
- ��x = 4�����������������[3,4]��[4,5]��
 

��ʾ:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1
*/
//#include<stdio>
#include"stdlib.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/* ̰��+˫ָ�� */
// �ֶ�д�ж����� 
bool compare(const vector<int> &a, const vector<int> &b){
	return a[0]<b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int> >& points) {
		if(points.size()==0)
			return 0;
		sort(points.begin(), points.end(), compare);
		
		int left=points[0][0];
		int right=points.end()[1];
		int result = 1;
		
		for(int i=0;i<points.size();i++){
			if(points[i][0]>left&&){
				right=;
			}
		}
		
		return result;
    }
};

int main(){
	vector<vector<int> > points;
	vector<int> p0, p1, p2, p3;
	p0.push_back(10);
	p0.push_back(16);
	p1.push_back(2);
	p1.push_back(8);
	p2.push_back(1);
	p2.push_back(6);
	p3.push_back(7);
	p3.push_back(12);
	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	
	Solution solution;
	printf("%d\n", solution.findMinArrowShots(points));
	
	return 0;
}

