/*
12. Integer to Roman [Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

struct Descending {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

class Solution {
private:
    map<int, string, Descending> _mp = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"}
    };
public:
    string intToRoman(int num) {
        string ans;
        for (auto& [val, str] : _mp) {
            while (num >= val) {
                ans += str;
                num -= val;
            }
            if (num == 0) break;
        }

        return ans;
    }
};