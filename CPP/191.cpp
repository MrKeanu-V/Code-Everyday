/*
191. Number of 1 Bits [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // ����һ ��λ
    int hammingWeight_1(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
    // ������ λ�����Ż�
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n &= n - 1; // �������Ҳ��1
            cnt++;
        }
        return cnt;
    }
    void test() {
        int n = 0b00000000000000000000000000001011;
        cout << hammingWeight(n) << endl;
        n = 0b00000000000000000000000010000000;
        cout << hammingWeight(n) << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}