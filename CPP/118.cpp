/*
118. Pascal's Triangle [Easy - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 模拟 Time: O(n^2), Space: O(n^2)
	vector<vector<int>> generate_1(int numRows) {
		if (numRows <= 0) return {};
		vector<vector<int>> res(numRows);

		for (int i = 0; i < numRows; i++) {
			vector<int> row(i + 1, 1);
			for (int j = 1; j < i; j++) {
				row[j] = res[i - 1][j - 1] + res[i - 1][j];
			}
			//res[i] = row;
			res[i] = move(row);
		}

		return res;
	}
	vector<vector<int>> generate(int numRows) {
		if(numRows <= 0) return {};
		vector<vector<int>> res(numRows);
		for (int i = 0; i < numRows; i++) {
			res[i].resize(i + 1, 1);
			for (int j = 1; j < i; j++) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
		return res;
	}
};