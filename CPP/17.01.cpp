/*
17.01. Add Without Plus Icci [Esay]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <functional>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	int add1(int a, int b) {
		constexpr int mask = 1;
		int carry = 0;
		while (b) {
			int current = (a & mask) ^ (b & mask) ^ carry;
			carry = ((a & mask) & (b & mask)) | (carry & ((a & mask) ^ (b & mask)));
			a >>= 1;
			b >>= 1;
			a |= current << 1;
		}
		return a;
	}

	int add(int a, int b) {
		while (b != 0) {
			auto carry = (unsigned int)(a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
	}
};

int main() {
	Solution sln;
	int a = 1, b = 2;
	cout << sln.add(a, b) << endl;
	return 0;
}