/*
89. Gray Code [Medium - 5 - Backtrack]
*/
#include "fnt_template.h"
#include "fnt_solution.h"

class Solution89 {
public:
    // Solution 1: Backtrack + SubTree Time: O(2^n) Space: O(2^n)
    // Find the number patterns, then use backtrack to find all the patterns
    vector<int> grayCode(int n) {
        vector<int> res;
        string path = "";
        function<void(string, string&)> backtrack = [&](string choice, string& path)->void {
            if (path.size() == n) return res.push_back(stoi(path, nullptr, 2));
            bool isRight = false;
            for (auto& c : choice) {
                path.push_back(c);
                backtrack(isRight ? "10" : "01", path);
                isRight = true;
                path.pop_back();
            }
        };
        backtrack("01", path);
        return res;
    }

    void test() {
        vector<int> res = grayCode(2);
        fnt::printVector1D(res);    // [0,1,3,2]
        res = grayCode(3);
        fnt::printVector1D(res);    // [0,1,3,2,6,7,5,4]
        res = grayCode(1);
        fnt::printVector1D(res);    // [0,1]
    }
};

FNT_REGISTER_SOLUTION(Solution89, 89)