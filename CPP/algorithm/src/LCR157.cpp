/*
LCR.157. Full String Permutations [Medium]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution_LCR157 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("LCR157")

    vector<string> goodsOrder(string goods) {
        vector<string> res;
        int n = goods.size();
        vector<bool> used(n, false);
        string path(n,0);
        sort(goods.begin(), goods.end());
        function<void(int)> dfs = [&](int pos)->void {
            if (pos == n) return res.push_back(path);
            for (int i = 0; i < n; ++i) {
                if (used[i] || (i && !used[i - 1] && goods[i] == goods[i - 1])) {
                    continue;
                }
                path[pos] = goods[i];
                used[i] = true;
                dfs(pos + 1);
                used[i] = false;
            }
        };
        dfs(0);
        return res;
    }

    void test() override {
        string goods = "abc";
        vector<string> res = goodsOrder(goods);
        printVector1D(res);    // ["abc","acb","bac","bca","cab","cba"]
        goods = "aab";
        res = goodsOrder(goods);
        printVector1D(res);    // ["aab","aba","baa"]
    }
};
FNT_REGISTER(Solution_LCR157);