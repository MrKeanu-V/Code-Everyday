/*
3074 Apple Redistribution Into Boxes [Easy - 1198]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ranges>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
		sort(capacity.begin(), capacity.end(), greater<int>());	// ½µÐògreater<type>(),ÉýÐòless<type>()
		int sum = 0,count=0;
		for (int i : apple) sum += i;
		while (sum > 0) sum -= capacity[count++];
		return count;
	}
};

int main() {
	Solution sln;
	vector<int> apple = { 1,3,2 };
	vector<int> capacity = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sln.minimumBoxes(apple, capacity) << endl;
	return 0;
}