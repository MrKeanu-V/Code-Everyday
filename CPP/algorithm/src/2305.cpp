/*
2305. Fair Distribution of Cookies [Medium - 5]
*/
#include "fnt_solution.h"
#include "fnt_template.h"

class Solution2305 {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        int result = INT_MAX;
        backtrack(cookies, children, result, 0);
        return result;
    }

    void backtrack(vector<int>& path, vector<int>& res, int& flag, int index) {
        // Terminate
        if (index == path.size()) {
            flag = min(flag, *max_element(res.begin(), res.end()));
            return;
        }
        // Prune
        if (flag <= *max_element(res.begin(), res.end())) return;

        // Traverse
        for (int idx = 0; idx < res.size(); ++idx) {
            // Update state
            res[idx] += path[index];
            // Backtrack
            backtrack(path, res, flag, index + 1);
            // Rollback state
            res[idx] -= path[index];

            // Prune, usually put it before backtrack
            if (res[idx] == 0) break;
        }
    }

    void test() {
        vector<int> cookies = { 8,15,10,20,8 };
        int k = 2;
        cout << "Result: " << distributeCookies(cookies, k) << endl;    // 31
    }
};

//struct Solution2305Register {
//    Solution2305Register() {
//        Solution2305 sln;
//        fnt::RegisterSolution("2305", [&sln] {sln.test(); });
//    }
//};
//
//static Solution2305Register __reg2305;

FNT_REGISTER_SOLUTION(Solution2305, 2305)