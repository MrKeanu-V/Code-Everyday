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
        solveSudoku(board);
		print2DVector(board);
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}
