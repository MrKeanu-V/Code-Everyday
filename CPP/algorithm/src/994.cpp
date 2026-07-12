/*
994. Rotting Oranges [Medium - 1433]
*/

#include "pub_template.h"

class Solution {
public:
    // Solution1: BFS Time: O(MN) Space: O(MN)
    int orangesRotting_1(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int step = 0, fresh = 0, rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push(make_pair(i, j));
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        function<void(int, int)> Infect = [&](int x, int y) {
            grid[x][y] = 2;
            fresh--;
            q.push(make_pair(x, y));
        };

        while (fresh && !q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                if (x > 0 && grid[x - 1][y] == 1) Infect(x - 1, y);
                if (x < rows - 1 && grid[x + 1][y] == 1) Infect(x + 1, y);
                if (y > 0 && grid[x][y - 1] == 1) Infect(x, y - 1);
                if (y < cols - 1 && grid[x][y + 1] == 1) Infect(x, y + 1);
            }
            step++;
        }
        
        return fresh ? -1 : step;
    }

    // Solution2 Optimize: Time: 0ms far faster than Solution1 4ms
    int DIRECTIONS[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // up, down, left, right
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.emplace_back(i, j); // emplace() is faster than push_back()

        int step = 0;
        while (fresh && !q.empty()) {
            vector<pair<int, int>> nxt;
            for (auto& [x, y] : q) { 
                for (auto d : DIRECTIONS) { // quickly iterate 4 directions
                    int i = x + d[0], j = y + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) {
                        fresh--;
                        grid[i][j] = 2;
                        nxt.emplace_back(i, j);
                    }
                }
            }
            q = move(nxt);  // move() is faster than assign()
            step++;
        }

        return fresh ? -1 : step;
    }

    void test() {
        vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
        printf("Result: %d\n", orangesRotting(grid));

        grid = {{2,1,1},{0,1,1},{1,0,1}};
        printf("Result: %d\n", orangesRotting(grid));

        grid = {{0,2}};
        printf("Result: %d\n", orangesRotting(grid));
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}