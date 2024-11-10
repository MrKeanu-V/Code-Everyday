/*
01.08. Zero Matrix LCCI [Medium]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 解法一 暴力 O(mn) O(m+n)
    void setZeroes1(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<bool> row(rows, false), col(cols, false);
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) 
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
        for (int i = 0; i < rows; i++) 
            if (row[i]) 
                for (int j = 0; j < cols; j++) matrix[i][j] = 0;
                    

        for (int i = 0; i < cols; i++) 
            if (col[i]) 
                for (int j = 0; j < rows; j++) matrix[j][i] = 0;
    }
    // 解法二 O(mn) O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) firstRowZero = true;
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int i = 0; i < cols; i++) matrix[0][i] = 0;
        }
        if (firstColZero) {
            for (int i = 0; i < rows; i++) matrix[i][0] = 0;
        }
    }
};

void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto& e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sln;
    vector<vector<int>> matrix = { {1,1,1}, {1,0,1}, {1,1,1} };
    cout << "Before: " << endl;
    printMatrix(matrix);
    sln.setZeroes(matrix);
    cout << "After: " << endl;
    printMatrix(matrix);
    return 0;
}