/*
204. Count Primes [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

const long mx = 5000000;
long pi[mx+1];
auto init = []() {
    for (long i = 2; i < mx; i++) {
        if (pi[i] == 0) {
            pi[i] = pi[i - 1] + 1;
            for (long j = i*i; j <= mx; j += i) {
                pi[j] = -1;
            }
        }
        else {
            pi[i] = pi[i - 1];
        }
    }
    return 0;
}();

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
    int countPrimes_2(int n) {
        int res = 0;
        vector<bool> ppi(n, true);
        for (int i = 2; i < n; i++) {
            if (ppi[i]) {
                res++;
                if ((long long)i * i < n)
                    for (int j = i * i; j < n; j += i) {
                        ppi[j] = false;
                    }
            }
        }
        return res;
    }
    int countPrimes(int n) {
        if (n == 0) return 0;
        return pi[n - 1];
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