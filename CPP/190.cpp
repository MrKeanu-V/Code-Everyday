/*
190. Reverse Bits [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // �ⷨһ ��λ���� Time:O(32) Space:O(1)
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, i = 32;
        while (i--) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }
    // �ⷨ�� ���η� Time:O(1) Space:O(1)
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};