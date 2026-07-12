/*
LCR.157. Full String Permutations [Medium]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
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
};
