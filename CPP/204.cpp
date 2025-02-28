/*
204. Count Primes [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // 解法一 Brute Time: O(n^2) Space: O(1)
    int countPrimes_1(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) res++;
        }
        return res;
    }
    // 解法二 埃拉托斯特尼筛法 Time: O(nloglogn) Space: O(n)
    int countPrimes(int n) {
        int res = 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res++;
                if ((long long)i * i < n)
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
            }
        }
        return res;
    }

    void test() {
        int n = 10;
        cout << countPrimes(n) << endl;
        cout << countPrimes(0) << endl;
        cout << countPrimes(1) << endl;
        cout << countPrimes(15) << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}