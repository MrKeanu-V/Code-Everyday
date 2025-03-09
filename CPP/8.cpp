/*
8. String To Integer (atoi) [Medium - 6]
*/
#include "pub_template.h"
using namespace pub;

// 解法一：有限状态机(Deterministic Finite Automaton,DFA)一般简称为自动机
// 此类型题目统称为有限状态机，其难点在于边界条件的处理，需要考虑很多种情况，因此需要使用有限状态机来处理。
class Automaton {
private:
    string state = "start";
    unordered_map<string, vector<string>> state_trans = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int next_state(char c) {
        if (c == ' ') return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = state_trans[state][next_state(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed") sign = c == '+' ? 1 : -1;
    }
};

class Solution {
private:
    
public:
    // 解法一 有限状态机Time:O(n) Space:O(1)
    int myAtoi_1(string s) {
        Automaton automaton;
        for(char c:s) automaton.get(c);
        return automaton.sign * automaton.ans;
    }
    // 解法二 模拟Time:O(n) Space:O(1)
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long res = 0;

        while (s[i] == ' ') i++;
        if (s[i] == '-' || s[i] == '+') sign = s[i++] == '-' ? -1 : 1;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                res = res * 10 + s[i++] - '0';
                if (res * sign >= INT_MAX) return INT_MAX;
                if (res * sign <= INT_MIN) return INT_MIN;
            }
            else break;
        }

        return res * sign;
    }
    void test() {
        string str = "42";
        cout << myAtoi(str) << endl;
        str = "-042";
        cout << myAtoi(str) << endl;
        str = "words and 987";
        cout << myAtoi(str) << endl;
        str = "0 - 1";
        cout << myAtoi(str) << endl;
        str = "1337c0d3";
        cout << myAtoi(str) << endl;
        str = "-91283472332";
        cout << myAtoi(str) << endl;
    }
};

int main() {
    Solution().test();
    return 0;
}