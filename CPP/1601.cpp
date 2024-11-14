/*
16.01 Swap Numbers LCCI [Medium]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> swapNumbers1(vector<int>& numbers) {
		return { numbers[1], numbers[0] };
	}

	vector<int> swapNumbers2(vector<int>& numbers) {
		swap(numbers[0], numbers[1]);
		return numbers;
	}
	// 方法三 位运算 异或
	vector<int> swapNumbers(vector<int>& numbers) {
		numbers[0] ^= numbers[1];
		numbers[1] ^= numbers[0];
		numbers[0] ^= numbers[1];
		return numbers;
	}
};

int main() {
	Solution sln;
	vector<int> numbers = { 1, 2 };
	auto ans = sln.swapNumbers(numbers);
	for (auto& n : ans) cout << n << " ";
	return 0;
}