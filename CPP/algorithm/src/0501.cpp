/*
05.01. Insert Into Bits LCCI [Esay]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int insertBits(int N, int M, int i, int j) {
		int mask = (0 | M) << i;
		for (int k = i; k <= j; ++k) {
			N &= ~(1 << k);
		}
		int result = N | mask;
		return result;
	}
};

int main() {
	Solution sln;
	int N = 1024, M = 19, i = 2, j = 6;
	cout << sln.insertBits(N, M, i, j) << endl;
	return 0;
}