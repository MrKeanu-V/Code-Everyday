/*
240. Search a 2D Matrix II [Medium - 5]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace std;
using namespace fnt;

class Solution240 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("240")
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

    void test() override {
        vector<vector<int>> matrix = {
            { 1,  4,  7, 11, 15},
            { 2,  5,  8, 12, 19},
            { 3,  6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        cout << Bool2Str(searchMatrix(matrix, 5))  << endl;    // true
        cout << Bool2Str(searchMatrix(matrix, 20)) << endl;    // false
        cout << Bool2Str(searchMatrix(matrix, 30)) << endl;    // true
    }
};

FNT_REGISTER(Solution240);
