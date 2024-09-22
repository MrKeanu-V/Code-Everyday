/*
����1������
����2�������ڵ���ͨ
����3������ͨ

���룺
N M T		�ֱ�Ϊ������������������Ϣ��������ѯ����
M��a b c	�ֱ�Ϊ��������������
T��a b		�ֱ�Ҫ���ҵ���������

�������룺
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

        // ��ʼ��
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
        // Floyd��ͨ���ж�
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

    // ���ͣ���ͨ�ԡ���ѯ �ⷨ��BFS ̰��
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
// 64 λ������� printf("%lld")
// 64 λ������� printf("%lld")