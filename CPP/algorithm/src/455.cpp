/*
455. Assign Cookies [Easy - 3]
*/
#include "fnt_solution.h"
#include "fnt_template.h"

class Solution455 {
public:
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

    void test() {
        vector<int> g = { 1,2,3 };
        vector<int> s = { 1,1 };
        cout << findContentChildren(g, s) << endl;
        vector<int> g1 = { 1,2 };
        vector<int> s1 = { 1,2,3 };
        cout << findContentChildren(g1, s1) << endl;
    }
};

struct Solution455Register {
    Solution455Register() {
        Solution455 s;
        fnt::RegisterSolution("455", [&s] { s.test(); });
    }
};

// 455
static Solution455Register __reg455;