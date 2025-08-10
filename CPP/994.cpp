/*
994. Rotting Oranges [Medium - 1433]
*/

#include "pub_template.h"

class Solution {
public:
    // Solution1: BFS Time: O(MN) Space: O(MN)
    int orangesRotting(vector<vector<int>>& grid) {
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

    void test() {
        vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
        printf("Result: %d\n", orangesRotting(grid));

        grid = {{2,1,1},{0,1,1},{1,0,1}};
        printf("Result: %d\n", orangesRotting(grid));

        grid = {{0,2}};
        printf("Result: %d\n", orangesRotting(grid));
    }
};

int main() {
    Solution().test();
    return 0;
}