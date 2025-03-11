/*
240. Search a 2D Matrix II [Medium - 5]
*/
#include "pub_template.h"
using namespace std;

class Solution {
public:
    // 解法一 二分 Time: O(log(mn)) Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};