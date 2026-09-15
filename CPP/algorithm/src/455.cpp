/*
455. Assign Cookies [Easy - 3]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"

class Solution455 : public fnt::BaseSolution {
public:
    FNT_SOLUTION_KEY("455")

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), std::greater<int>());
        sort(s.begin(), s.end(), std::greater<int>());
        int jdx = 0;
        for (int idx = 0; idx < g.size() && jdx < s.size(); ++idx, ++jdx) {
            if (g[idx] > s[jdx]) {
                --jdx;
            }
        }
        return jdx;
    }

    void test() override {
        vector<int> g = { 1,2,3 };
        vector<int> s = { 1,1 };
        cout << findContentChildren(g, s) << endl;
        vector<int> g1 = { 1,2 };
        vector<int> s1 = { 1,2,3 };
        cout << findContentChildren(g1, s1) << endl;
    }
};

FNT_REGISTER(Solution455);