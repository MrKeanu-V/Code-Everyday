/*
79. Word Search [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // �ⷨһ DFS
    bool exist_1(vector<vector<char>>& board, string word) {
        string path;
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<bool(int, int)> dfs = [&](int x, int y)->bool {
            if (path.size() == word.size()) return true;
            if (x - 1 >= 0 && !visited[x - 1][y] && board[x - 1][y] == word[path.size()]) {
                visited[x - 1][y] = true;
                path.push_back(board[x - 1][y]);
                if (dfs(x - 1, y)) return true;
                path.pop_back();
                visited[x - 1][y] = false;
            }
            if (y - 1 >= 0 && !visited[x][y - 1] && board[x][y - 1] == word[path.size()]) {
                visited[x][y - 1] = true;
                path.push_back(board[x][y - 1]);
                if (dfs(x, y - 1)) return true;
                path.pop_back();
                visited[x][y - 1] = false;
            }
            if (x + 1 < m && !visited[x + 1][y] && board[x + 1][y] == word[path.size()]) {
                visited[x + 1][y] = true;
                path.push_back(board[x + 1][y]);
                if (dfs(x + 1, y)) return true;
                path.pop_back();
                visited[x + 1][y] = false;
            }
            if (y + 1 < n && !visited[x][y + 1] && board[x][y + 1] == word[path.size()]) {
                visited[x][y + 1] = true;
                path.push_back(board[x][y + 1]);
                if (dfs(x, y + 1)) return true;
                path.pop_back();
                visited[x][y + 1] = false;
            }
            return false;
        };
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    path.push_back(board[i][j]);
                    if (dfs(i, j)) return true;
                    path.pop_back();
                    visited[i][j] = false;
                }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        function<bool(int idx, int, int)> dfs = [&](int idx, int x, int y)->bool {
            if (x >= m || x < 0 || y >= n || y < 0 || word[idx] != board[x][y]) return false;
            if (idx == word.size() - 1) return true;
            board[x][y] = '\0';
            bool res = dfs(idx + 1, x + 1, y) || dfs(idx + 1, x - 1, y) || dfs(idx + 1, x, y + 1) || dfs(idx + 1, x, y - 1);
            board[x][y] = word[idx];
            return res;
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(0, i,j)) return true;
        return false;
    }
};