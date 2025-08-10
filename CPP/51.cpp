/*
51. N-Queens [Hard - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    bool isValid(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < n; i++) if (board[row][i] == 'Q' || board[i][col] == 'Q') return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 'Q') return false;
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) if (board[i][j] == 'Q') return false;
        for (int i = row, j = col; i < n && j >= 0; i++, j--) if (board[i][j] == 'Q') return false;
        for (int i = row, j = col; i < n && j < n; i++, j++) if (board[i][j] == 'Q') return false;
        return true;
    }
public:
    // 解法一 回溯+递归
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        function<void(int)> dfs = [&](int r) {
            if(r==n) return res.push_back(board);
            for(int c=0;c<n;c++)
                if (isValid(board, r, c, n)) {
                    board[r][c] = 'Q';
                    dfs(r + 1);
                    board[r][c] = '.';
                }
        };
        dfs(0);
        return res;
    }
    // 解法二 回溯+数组
    vector<vector<string>> solveNQueens_2(int n) {
        vector<vector<string>> res;
        vector<int> queens(n);
        vector<int> cols(0), diag1(n * 2 - 1), diag2(n * 2 - 1);
        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                vector<string> board(n);
                for (int i = 0; i < n; i++) board[i] = string(queens[i], '.') + 'Q' + string(n - queens[i] - 1, '.');
                return res.push_back(board);
            }
            for (int c = 0; c < n; c++) {
                int rc = r - c + n - 1;
                if (!cols[c] && !diag1[r + c] && !diag2[rc]) {
                    queens[r] = c;
                    cols[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    cols[c] = diag1[r + c] = diag2[rc] = false;
                }
            }
        };
        dfs(0);
        return res;
    }

    void test() {
        vector<vector<string>> res = solveNQueens(4);
        printVector2D(res);
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}
