/*
855. Exam Room [Medium - 2067]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <ranges>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;

struct Comp {
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
		int dist1 = p1.second - p1.first, dist2 = p2.second - p2.first;
		return (dist1 / 2 < dist2 / 2) || (dist1 / 2 == dist2 / 2 && p1.first > p2.first);
	}
};

class ExamRoom {
private:
	int n;
	set<int> seats;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
public:
	ExamRoom(int n) : n(n) {

	}

	int seat() {
		if (seats.empty()) {
			seats.insert(0);
			return 0;
		}
		int left = *seats.begin(), right = n - 1 - *seats.rbegin();	// 即左右距离
		while (seats.size() > 1) {
			auto p = pq.top();
			// 延迟删除区间,因为有可能当前区间被删除后，左右边界座位更优
			if (seats.count(p.first) > 0 && seats.count(p.second) > 0 && *next(seats.find(p.first)) == p.second) {
				int dist = p.second - p.first;
				if (dist/2 < right || dist/2 <= left) {	// 边界座位更优,由于相同时优先选择编号小的座位，所以这里mid <= left
					break;
				}
				pq.pop();
				pq.push({ p.first,p.first + dist/2 });
				pq.push({ p.first + dist/2, p.second });
				seats.insert(p.first + dist/2);
				return p.first + dist/2;
			}
			pq.pop();	// leave中的区间延迟在此被删除
		}
		if (right > left) {
			pq.push({ *seats.rbegin(), n - 1 });
			seats.insert(n - 1);
			return n - 1;
		}
		else {
			pq.push({ 0,*seats.begin() });
			seats.insert(0);
			return 0;
		}
	}

	void leave(int p) {
		if (p != *seats.begin() && p != *seats.rbegin()) {
			auto it = seats.find(p);
			pq.push({ *prev(it),*next(it)});	// *prev(it)
		}
		seats.erase(p);
	}
};

int main() {
	vector<string> input = { "ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat" };
	vector<int> input2 = { 10, -1, -1, -1, -1, 4, -1 };
	ExamRoom* obj = nullptr;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == "ExamRoom") {
			obj = new ExamRoom(input2[i]);
		}
		else if (input[i] == "seat") {
			cout << obj->seat() << endl;
		}
		else if (input[i] == "leave") {
			obj->leave(input2[i]);
			cout << "null" << endl;
		}
	}
	return 0;
}