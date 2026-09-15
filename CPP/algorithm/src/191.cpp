/*
191. Number of 1 Bits [Easy - 2]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution191 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("191")

    // 方法一 逐位
    int hammingWeight_1(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
    // 方法二 位运算优化
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n &= n - 1; // 消除最右侧的1
            cnt++;
        }
        return cnt;
    }

    void test() override {
        int n = 0b00000000000000000000000000001011;
        cout << hammingWeight(n) << endl;    // 3
        n = 0b00000000000000000000000010000000;
        cout << hammingWeight(n) << endl;    // 1
    }
};

FNT_REGISTER(Solution191);

//int main() {
//    Solution().test();
//    return 0;
//}