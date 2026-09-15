/*
119. Pascal's Triangle II [Easy - 3]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution119 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("119")

    // 解法一 模拟 Time: O(n^2) Space: O(n)
    vector<int> getRow_1(int rowIndex) {
        vector<vector<int>> res(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        return res[rowIndex];
    }
    // 解法二 滚动数组 Time: O(n^2) Space: O(1)
    vector<int> getRow_2(int rowIndex) {
        vector<int> cur, pre;
        for (int i = 0; i <= rowIndex; i++) {
            cur.resize(i + 1, 1);
            for (int j = 1; j < i; j++) cur[j] = pre[j - 1] + pre[j];
            pre = cur;
        }
        return cur;
    }
    // 解法三 滚动数组优化 Time: O(n) Space: O(1)
    vector<int> getRow_3(int rowIndex) {
        vector<int> cur(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) cur[j] += cur[j - 1];
        }
        return cur;
    }

    void test() override {
        int rowIndex = 3;
        vector<int> res = getRow_3(rowIndex);
        printVector1D(res);    // [1,3,3,1]
    }
};

FNT_REGISTER(Solution119);