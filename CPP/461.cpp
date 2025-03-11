/*
461. Hamming Distance [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // �ⷨһ ��λ���� Time: O(1) Space: O(1)
    int hammingDistance_1(int x, int y) {
        int res = 0, i = 32;
        while (i--) {
            res += (x & 1) ^ (y & 1);
            x >>= 1, y >>= 1;
        }
        return res;
    }
    // �ⷨ�� ����Ż�
    int hammingDistance_2(int x, int y) {
        int s = x ^ y, res = 0;
        while (s) {
            res += s & 1;
            s >>= 1;
        }
        return res;
    }
    // �ⷨ�� Brian Kernighan �㷨
    int hammingDistance_3(int x, int y) {
        int s = x ^ y, res = 0;
        while (s) {
            s &= (s - 1);
            res++;
        }
        return res;
    }
    // �ⷨ�� ���ú���
    int hammingDistance_4(int x, int y) {
        //return _builtin_popcount(x ^ y);    // ����gcc����������Ч
        // vc++����������Ҫ�Լ�ʵ��
        return -1;
    }
};