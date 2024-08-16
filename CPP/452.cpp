/*
LeetCode 452 ̰�� 
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

/* ̰��+˫ָ�� ����ؼ�����������*/
// �ֶ�д�ж�����  
bool compare(const vector<int> &a, const vector<int> &b){
	return a[0]<b[0];
}

void  printPoints(const std::vector<std::vector<int> >& points) {
    for (const auto& point : points) {
        for (int value : point) {
            std::cout << value << " ";
        }
        std::cout << std::endl; // ÿ�к���
    }
    std::cout << std::endl; // ÿ�к���
}

class Solution {
public:
	//�ⷨһ�����ˣ���ȫģ�� 
//    int findMinArrowShots(vector<vector<int> >& points) {
//		if(points.size()==0)
//			return 0;
//			
//		printPoints(points);
//		sort(points.begin(), points.end(), compare);
//		printPoints(points);
//		
//		int left=points[0][0];
//		int right=points[0][1];
//		int result = 1;
//		
//		for(int i=1;i<points.size();i++){
//			if(points[i][0]<=right){
//				left=points[i][0];
//				if(points[i][1]<right){
//					right=points[i][1];
//				}
//			}
//			else{
//				result++;
//				left=points[i][0];
//				right=points[i][1];
//			}
//		}
//		
//		return result;
//    }

	//�ⷨ��������+̰�� 
	int findMinArrowShots(vector<vector<int> >& points) {
		if(points.empty())
			return 0;
		
		printPoints(points);
		sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){
			return a[0]>b[0];
		});	//ʹ���麯�� C++ 
		printPoints(points);
		int arrow=points[0][0];
		int result = 1;
		
		for(const vector<int>& balloon: points)
			if(balloon[1]<arrow){
				arrow=balloon[0];
				result++;
			}
		
		return result;
    }
};

int main(){
	std::vector<std::vector<int>> points = {
        {3,9},{7,10},{3,8},{6,8},{9,12},{2,9},{0,9},{3,9},{0,6},{2,8}
    };
//	vector<vector<int> > points;
//	vector<int> p0, p1, p2, p3;
////	p0.push_back(1);
////	p0.push_back(2);
////	p1.push_back(3);
////	p1.push_back(4);
////	p2.push_back(5);
////	p2.push_back(6);
////	p3.push_back(7);
////	p3.push_back(8);
//
//	points.push_back(p0);
//	points.push_back(p1);
//	points.push_back(p2);
//	points.push_back(p3);
	
	Solution solution;
	printf("%d\n", solution.findMinArrowShots(points));
	
	return 0;
}

