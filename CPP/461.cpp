/*
461. Hamming Distance [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // 解法一 逐位运算 Time: O(1) Space: O(1)
    int hammingDistance_1(int x, int y) {
        int res = 0, i = 32;
        while (i--) {
            res += (x & 1) ^ (y & 1);
            x >>= 1, y >>= 1;
        }
        return res;
    }
    // 解法二 异或优化
    int hammingDistance_2(int x, int y) {
        int s = x ^ y, res = 0;
        while (s) {
            res += s & 1;
            s >>= 1;
        }
        return res;
    }
    // 解法三 Brian Kernighan 算法
    int hammingDistance_3(int x, int y) {
        int s = x ^ y, res = 0;
        while (s) {
            s &= (s - 1);
            res++;
        }
        return res;
    }
    // 解法三 内置函数
    int hammingDistance_4(int x, int y) {
        //return _builtin_popcount(x ^ y);    // 仅在gcc编译器中有效
        // vc++编译器中需要自己实现
        return -1;
    }
};