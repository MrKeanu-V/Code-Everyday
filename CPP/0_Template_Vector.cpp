/*
STL 容器类

*/

#include <iostream>
// STL Vector Class
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
// STL Algorithm
#include <algorithm>
#include <numeric>
#include <iterator>
#include <ranges>
#include <functional>
using namespace std;

void test_vector() {
	// vector<Type> name(size, value);
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	for (auto it = v1.cbegin(); it != v1.cend(); it++) cout << *it << " ";
	v1.clear();
}
// queue为队列
void test_queue() {
	// queue<Type> name;
	queue<int> q1 = { 1, 2, 3, 4, 5 };
	q1.push(6);
	q1.pop();
	q1.front();
	q1.back();
	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}
}

// priority_queue为优先队列
void test_priority_queue() {
	// priority_queue<Type, Container, Compare> name;
	priority_queue<int,vector<int>, greater<int>> q1;
	q1.push(1);
	q1.push(3);
	q1.push(2);
	while(!q1.empty()) {
		cout << q1.top() << " ";
		q1.pop();
	}
}

// set为集合
void test_set() {
	// set<Type> name;
	set<int> s1 = { 1, 2, 3, 4, 5 };
	s1.insert(6);
	s1.erase(3);
	for (auto it = s1.cbegin(); it != s1.cend(); it++) cout << *it << " ";
	s1.clear();
}

// map为有序字典，按照key的顺序排列
void test_map() {
    // map<Type, Type> name;
	map<string, int> m1 = { { "a", 1 }, { "b", 2 }, { "c", 3 } };
	m1.insert({ "d", 4 });
	m1.erase("b");
	for (auto it = m1.cbegin(); it != m1.cend(); it++) cout << it->first << " " << it->second << " ";
	m1.clear();
}