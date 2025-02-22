/*
20. Valid Parentheses [Esay - 3]
*/
#include "pub_template.h"

class Solution {
private:
    unordered_map<char, char> mp = { {')', '('}, {']', '['}, {'}', '{'} };

public:
    // 解法一：栈+模拟 Time:O(n) Space:O(n)
    bool isValid_1(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (stk.empty()) return false;
                if ((c == ')' && stk.top() == '(')|| (c == ']' && stk.top() == '[')|| (c == '}' && stk.top() == '{')) stk.pop();
                else stk.push(c);
            }
        }
        return stk.empty() ? true : false;
    }
    // 解法二：栈+哈希表 Time:O(n) Space:O(n)
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        stack<char>stk;
        for (char c : s) {
            if (!mp.count(c)) stk.push(c);
            else if (stk.empty() || mp[c] != stk.top()) return false;
            else stk.pop();
        }
        return stk.empty();
    }

    void test() {
        string s = "()[]{}";
        string ans = isValid(s) ? "true" : "false";
        cout << ans << endl;

        s = "([}}])";
        ans = isValid(s) ? "true" : "false";
        cout << ans << endl;

        s = "([)]";
        ans = isValid(s) ? "true" : "false";
        cout << ans << endl;
    }
};

int main() {
    Solution().test();
    return 0;
}