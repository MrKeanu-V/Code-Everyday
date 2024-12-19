/*
LCP 01. Guess Number [Easy]
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
using namespace std;

class Solution {
public:
	int game(vector<int>& guess, vector<int>& answer) {
		//return accumulate(guess.begin(), guess.end(), 0, [answer](int sum, int x) {return sum + (x == answer[sum]); });
		int index = 0;
		return accumulate(guess.begin(), guess.end(), 0, [&](int sum, int x) { return sum + (x == answer[index++]); });
	}
};

int main() {
	Solution sln;
	vector<int> guess = { 1,2,3 };
	vector<int> answer = { 1,2,3 };
	cout << sln.game(guess, answer) << endl;
	return 0;
}