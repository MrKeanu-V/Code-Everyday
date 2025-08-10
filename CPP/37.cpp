/*
37. Sudoku Solver [Hard - 7]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
	bool CheckNum(vector<vector<char>>& board, int row, int col, char val) {
		for (int i = 0; i < 9; i++)
			if(board[row][i] == val|| board[i][col] == val) return false;
		// check 3*3 block
		int row_start = row / 3 * 3, col_start = col / 3 * 3;
		for(int i=0; i<3; i++)
			for (int j = 0; j < 3; j++)
				if (board[row_start + i][col_start + j] == val) return false;
		return true;
	}
	bool isValid(vector<vector<char>>& board, int row, int col, char val) {
		int row_start = row / 3 * 3, col_start = col / 3 * 3;
		for (int i = 0; i < 9; i++)
			if (board[row][i] == val || board[i][col] == val || board[row_start + i / 3][col_start + i % 3] == val) return false;
	}

	int row[9], col[9], block[3][3];
	vector<pair<int, int>> space;
	void flip(int i, int j, int val) {
		row[i] ^= (1 << val);
		col[j] ^= (1 << val);
		block[i / 3][j / 3] ^= (1 << val);
	}
public:
	// 解法一 回溯 Time:O(9^81) Space:O(1)
	void solveSudoku(vector<vector<char>>& board) {
		function<bool(int, int)> dfs = [&](int r, int c)->bool {
			if (r == 9) return true;
			if (c == 9) return dfs(r + 1, 0);
			if (board[r][c] != '.') return dfs(r, c + 1);
			for (char val = '1'; val <= '9'; val++) {
				if (CheckNum(board, r, c, val)) {
					board[r][c] = val;
					if (dfs(r, c + 1)) return true;
					board[r][c] = '.';
				}
			}
			return false;
		};
		bool res = dfs(0, 0);
	}
	// 解法一变体
	void solveSudoku_2(vector<vector<char>>& board) {
		function<bool()> dfs = [&]()->bool {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] != '.') continue;
					for (char val = '1'; val <= '9'; val++) {
						if (CheckNum(board, i, j, val)) {
							board[i][j] = val;
							if (dfs()) return true;
						}
					}
					board[i][j] = '.';
					return false;
				}
			}
			return true;
		};
		dfs();
	}
	// 解法二 回溯+集合，解法一时间优化
	bool rows[9][9], cols[9][9], blocks[3][3][9];
	vector<pair<int, int>> spaces;
	void solveSudoku_3(vector<vector<char>>& board) {
		memset(rows, false, sizeof(rows));
		memset(cols, false, sizeof(cols));
		memset(blocks, false, sizeof(blocks));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') spaces.emplace_back(i, j);
				else {
					int num = board[i][j] - '1';
					rows[i][num] = cols[j][num] = blocks[i / 3][j / 3][num] = true;
				}
			}
		}
		function<bool(int)> dfs = [&](int pos)->bool {
			if (pos == spaces.size()) return true;
			auto [i, j] = spaces[pos];
			for (int num = 0; num < 9; num++) {
				if (!rows[i][num] && !cols[j][num] && !blocks[i / 3][j / 3][num]) {
					board[i][j] = num + '1';
					rows[i][num] = cols[j][num] = blocks[i / 3][j / 3][num] = true;
					if (dfs(pos + 1)) return true;
					rows[i][num] = cols[j][num] = blocks[i / 3][j / 3][num] = false;
				}
			}
			return false;
		};
		dfs(0);
	}
	// 解法三 回溯+位运算
	void solveSudoku_4(vector<vector<char>>& board) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(block, 0, sizeof(block));
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] == '.') space.emplace_back(i, j);
				else flip(i, j, board[i][j] - '1');
		function<bool(int)> dfs = [&](int pos)->bool {
			if (pos == space.size()) return true;
			auto [i, j] = space[pos];
			for (int mask = ~(row[i] | col[j] | block[i / 3][j / 3]) & 0x1ff; mask; mask &= (mask - 1)) {
				int num = __builtin_ctz(mask & (-mask));
				flip(i, j, num);
				board[i][j] = num + '1';
				if (dfs(pos + 1)) return true;
				flip(i, j, num);
			}
			return false;
		};
		dfs(0);
	}

	void test() {
        vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},
                                      {'6','.','.','1','9','5','.','.','.'},
                                      {'.','9','8','.','.','.','.','6','.'},
                                      {'8','.','.','.','6','.','.','.','3'},
                                      {'4','.','.','8','.','3','.','.','1'},
                                      {'7','.','.','.','2','.','.','.','6'},
                                      {'.','6','.','.','.','.','2','8','.'},
                                      {'.','.','.','4','1','9','.','.','5'},
                                      {'.','.','.','.','8','.','.','7','9'}};
        solveSudoku_4(board);
		printVector2D(board);
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}
