/*
17. Letter Combinations of a Phone Number [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    // 解法一 回溯 选或不选 Time: O(4^n) Space: O(n)
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) return {};
        vector<string> res;
        string path;
        function<void(int)> dfs = [&](int idx)->void {
            if (idx == n) return res.push_back(path);
            for (char c : mp[digits[idx]]) {
                path.push_back(c);
                dfs(idx + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }

    void test() {
        string digits = "234";
        vector<string> res = letterCombinations(digits);
        printVector1D(res);
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}