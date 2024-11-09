/*
2037. Minimum Number of Moves to Seat Everyone [Easy - 1357]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <climits>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());
		int res = 0;
		for (int i = 0; i < seats.size(); i++) {
			res += abs(seats[i] - students[i]);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<int> seats = { 3,1,5 };
	vector<int> students = { 2,7,4 };
	cout << sln.minMovesToSeat(seats, students) << endl;
	return 0;
}