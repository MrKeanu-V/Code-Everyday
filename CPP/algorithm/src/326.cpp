/*
326. Power of Three [Easy - 1]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    long long _Max3 = 3;
public:
    Solution() {
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
    void test() {
        cout << isPowerOfThree(27) << endl;
        cout << isPowerOfThree(0) << endl;
        cout << isPowerOfThree(99999) << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}