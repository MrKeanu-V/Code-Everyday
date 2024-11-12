/*
* 成绩排名
题目描述：
某班有10名同学，目前已经有9名同学成绩已经按照从低到高的次序进行排列，有1名同学成绩因在等分过程中，
不小心遗漏掉，现要求输入该同学成绩后，依然保持有序。

输入描述：
分别输入原有的9名同学成绩
以及被遗漏的第10名同学成绩

输出描述：
排序后的10名同学成绩。

示例1
输入：
60 70 80 90 100 110 120 130 140
160
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 暴力
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