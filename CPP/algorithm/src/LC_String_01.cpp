/*
LC Valid isAnagram [https://leetcode.cn/leetbook/read/top-interview-questions-easy/xn96us/]
*/
#include "pub_template.h"

class Solution {
private:
    int arr[26] = { 0 };
public:
    // ¹þÏ£ Time:O(n) Space:O(1)
    bool isAnagram(string s, string t) {
        int size_s = s.size(), size_t = t.size();
        if (size_s != size_t) return false;
        for (int i = 0; i < size_s; i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) 
            if (arr[i] != 0) return false;
        return true;
    }

    void test() {
        string s = "rat";
        string t = "cat";
        string ans = isAnagram(s, t) ? "true" : "false";
        cout << ans << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}