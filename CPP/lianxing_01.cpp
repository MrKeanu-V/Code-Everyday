/*
* �ɼ�����
��Ŀ������
ĳ����10��ͬѧ��Ŀǰ�Ѿ���9��ͬѧ�ɼ��Ѿ����մӵ͵��ߵĴ���������У���1��ͬѧ�ɼ����ڵȷֹ����У�
��С����©������Ҫ�������ͬѧ�ɼ�����Ȼ��������

����������
�ֱ�����ԭ�е�9��ͬѧ�ɼ�
�Լ�����©�ĵ�10��ͬѧ�ɼ�

���������
������10��ͬѧ�ɼ���

ʾ��1
���룺
60 70 80 90 100 110 120 130 140
160
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ����
vector<int> insertGrade(vector<int>& grades, int g) {
    sort(grades.begin(), grades.end());
    vector<int> temp(grades.size() + 1);
    for (int i = 0, j = 0; i < grades.size(); i++, j++) {
        if (grades[i] > g) {
            temp[j++] = g;
            temp[j] = grades[i];
            g = INT_MAX;
        }
        else {
            temp[j] = grades[i];
            if (i == grades.size() - 1)
                temp[j + 1] = g;
        }
    }
    return temp;
}

int main()
{
    vector<int> grades(9);
    for (int i = 0; i < grades.size(); i++)
        cin >> grades[i];

    int missed_grade;
    cin >> missed_grade;

    for (int i = 0; i < grades.size(); i++)
        cout << grades[i] << " ";
    cout << endl;

    vector<int> result = insertGrade(grades, missed_grade);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}