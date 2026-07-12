/*
412. Fizz Buzz [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) res[i] = "FizzBuzz";
            else if (i % 3 == 0) res[i] = "Fizz";
            else if (i % 5 == 0) res[i] = "Buzz";
            else res[i] = to_string(i);
        }
        return res;
    }
};