/*
Interview 17.01. Add Without Plus Icci [Esay]
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
#include <fnt/fnt_solution.h>
#include <fnt/fnt_utils.h>
using namespace fnt;
using namespace std;

class Solution17_01 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("17.01")

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

	void test() override {
		cout << add(1, 2) << endl;
		cout << add(2, 3) << endl;
		cout << add(-1, 1) << endl;
		cout << add(-2, -3) << endl;
	}
};

FNT_REGISTER(Solution17_01)