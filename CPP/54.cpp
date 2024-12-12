/*
54. Spiral Matrix [Mediunm - 4]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    static constexpr int DIRS[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };    //顺时针 右下坐上
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int x = 0, y = 0, d = 0;
        for (int i = 0; i < m * n; i++) {
            ans[i] = matrix[x][y];
            matrix[x][y] = INT_MIN;    // 已经访问
            int nx = x + DIRS[d][0], ny = y + DIRS[d][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] == INT_MIN) d = (d + 1) % 4;
            x += DIRS[d][0], y += DIRS[d][1];
        }
        return ans;
    }
};

int main() {
    Solution sln;
    vector<vector<int>> matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    vector<int> ans = sln.spiralOrder(matrix);
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}