/*
744. Find Smallest Letter Greater Than Target [Easy - 3]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	// 解法一 闭区间二分查找
	char nextGreaterLetter1(vector<char>& letters, char target) {
		int left = 0, right = letters.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (letters[mid] < target+1) left = mid + 1;
			else right = mid - 1;
		}
		return left == letters.size() ? letters[0] : letters[left];
	}
	// 解法二 左开右开区间二分查找
	char nextGreaterLetter2(vector<char>& letters, char target) {
		int left = 0, right = letters.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			(letters[mid] < target + 1) ? left = mid + 1 : right = mid;
		}
		return left == letters.size() ? letters[0] : letters[left];
	}
	// 解法三 开区间二分查找
	char nextGreaterLetter(vector<char>& letters, char target) {
		int left = -1, right = letters.size();
		while (left+1 < right) {
			int mid = left + (right - left) / 2;
			(letters[mid] < target + 1) ? left = mid : right = mid;
		}
		return right == letters.size() ? letters[0] : letters[right];
	}
};

int main() {
	Solution sln;
	vector<char> letters = { 'c', 'f', 'j' };
	char target = 'c';
	cout << sln.nextGreaterLetter(letters, target) << endl;
	return 0;
}