// vc++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//Ctrl + Space 或 Alt + Right Arrow：触发完整的 IntelliSense 自动完成菜单。
//Ctrl + Shift + Space：显示当前方法的参数信息。

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
小红书笔试1
机器人
具体来说，一张n*m的网格地图，左上角为（1,1），右下角为（n,m），
每个格子都有一个滑行带，前进方向为L，R，U，D，分别表示左右上下四个方向前进。
·如果第t时刻，机器人在（i,j）位置，（i,j）滑行带前进方向为L，则第t+1时刻机器人会滑行到（i,j-1）位置。
·如果第t时刻，机器人在（i,j）位置，（i,j）滑行带前进方向为R，则第t+1时刻机器人会滑行到（i,j+1）位置。
·如果第t时刻，机器人在（i,j）位置，（i,j）滑行带前进方向为U，则第t+1时刻机器人会滑行到（i-1,j）位置。
·如果第t时刻，机器人在（i,j）位置，（i,j）滑行带前进方向为D，则第t+1时刻机器人会滑行到（i+1,j）位置。
机器人走出地图后就会毁坏，一个格子可以容纳多个机器人。
第0时刻，每个位置都有一个机器人，问：第10^8时刻，地图上还剩下多少个机器人？

输入：
2 5
LRRLR
UULLR
输出：
6
*/

// 找循环周期
int findCycle(int n, int m, int i, int j, vector<string> &directions) {
    int cycle = 0;
    
    unordered_map<vector<pair<int,int>>, int> visited;

    while (true) {
        
        

    return cycle;
}

// 判断是否在循环中
bool isInCycle(int n, int m, int i, int j, vector<string> &directions) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

long long ans1(int n, int m) {
    long long res = n * m;
    vector<string> directions(n);
    for (int i = 0; i < n; i++) {
        cin >> directions[i];
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << directions[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char dir = directions[i][j];
            int cycle = findCycle(n, m, i, j, dir);
            int pos = ((i+1) * 100000000% cycle+1)*dir + (j+1);
            if (!isInCycle(n, m, pos/m, pos%m)) {
                res--;
            }
        }
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long  res = ans1(n, m);
    std::cout << res<<endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
