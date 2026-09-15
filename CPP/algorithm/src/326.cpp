/*
326. Power of Three [Easy - 1]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution326 : public BaseSolution {
private:
    long long _Max3 = 3;
public:
    FNT_SOLUTION_KEY("326")

    Solution326() {
        while (_Max3 <= INT32_MAX) _Max3 *= 3;
    }
    bool isPowerOfThree_(int n) {
        if(n<=0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
    bool isPowerOfThree_2(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
    bool isPowerOfThree(int n) {
        cout<< _Max3 << endl;
        return n > 0 && _Max3 % n == 0;
    }
    void test() override {
        cout << isPowerOfThree(27) << endl;
        cout << isPowerOfThree(0) << endl;
        cout << isPowerOfThree(99999) << endl;
    }
};
FNT_REGISTER(Solution326);
//int main() {
//    Solution().test();
//    return 0;
//}