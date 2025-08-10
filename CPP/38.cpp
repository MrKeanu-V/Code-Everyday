/*
38. Count and Say [Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    string RLE(string num) {
        string res;
        for (int i = 0; i < num.length(); i++) {
            int cnt = 1, j=i+1;
            while (j < num.length() && num[j - 1] == num[j]) cnt++, j++;
            res.push_back(cnt + '0');
            res.push_back(num[i]);
            i = j - 1;
        }
        return res;
    }
    // 解法一：递归 Time:O(n^2) Space:O(n)
    string countAndSay_1(int n) {
        if (n == 1) return "1";
        return RLE(countAndSay_1(n - 1));
    }
    // 解法二：递推 Time:O(n^2) Space:O(n)
    string countAndSay(int n) {
        vector<string> res(n);
        res[0] = "1";
        for (int i = 1; i < n; i++) res[i] = RLE(res[i - 1]);
        return res[n - 1];
    }

    void test() {
        cout << countAndSay(1) << endl;
        cout << countAndSay(4) << endl;
        cout << countAndSay(5) << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}