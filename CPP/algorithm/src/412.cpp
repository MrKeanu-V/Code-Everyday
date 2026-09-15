/*
412. Fizz Buzz [Easy - 2]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution412 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("412")

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

    void test() override {
        int n = 15;
        vector<string> res = fizzBuzz(n);
        printVector1D(res);
    }
};

FNT_REGISTER(Solution412);