/*
类型1：相邻
类型2：不相邻但连通
类型3：不联通

输入：
N M T		分别为定点数量，三角形信息数量，查询数量
M行a b c	分别为三角形三个顶点
T行a b		分别要查找的两个顶点

样例输入：
9 4 5
0 1 2
0 2 3
3 2 4
5 6 7
0 1
1 4
3 6
5 7
6 8
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> points;
    void initPoints(int N, int M) {
        vector<int> temp(N, 3);
        points.resize(N, temp);

        // 初始化
        for (int i = 0; i < N; i++) {
            points[i][i] = 1;
        }
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            points[a][b] = 1;
            points[a][c] = 1;
            points[b][c] = 1;

            points[b][a] = 1;
            points[c][a] = 1;
            points[c][b] = 1;
        }
        // Floyd连通性判断
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (points[i][j] == 1 && points[j][k] == 1) {
                        points[i][k] = points[i][k] == 1 ? 1 : 2;
                    }
                }
            }
        }

    }

    // 题型：连通性、查询 解法：BFS 贪心
    int findPointsType(int a, int b) {
        return points[a][b];
    }
};

int main() {
    Solution sln;
    int N, M, T;
    cin >> N >> M >> T;
    sln.initPoints(N, M);
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        cout << sln.findPointsType(a, b) << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
// 64 位输出请用 printf("%lld")