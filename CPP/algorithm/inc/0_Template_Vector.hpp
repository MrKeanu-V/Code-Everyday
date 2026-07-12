/*
 STL 容器类模板

 涵盖 C++ 标准库中常用的容器及算法，用于快速参考：
   - vector: 动态数组
   - queue: 队列
   - priority_queue: 优先队列
   - set: 有序集合
   - map: 有序映射
   - unordered_set / unordered_map: 哈希集合/映射
   - stack: 栈
   - 常用 <algorithm> / <numeric> / <ranges> 操作
*/
#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <ranges>
#include <functional>
using namespace std;

namespace STLTemplate {

// vector 基本操作
inline void test_vector() {
	// vector<Type> name(size, value);
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	for (auto it = v1.cbegin(); it != v1.cend(); it++) cout << *it << " ";
	v1.clear();
}

// queue 队列（FIFO）
inline void test_queue() {
	// queue<Type> name;
	queue<int> q1({ 1, 2, 3, 4, 5 });
	q1.push(6);
	q1.pop();
	q1.front();
	q1.back();
	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}
}

// priority_queue 优先队列（默认大顶堆）
inline void test_priority_queue() {
	// priority_queue<Type, Container, Compare> name;
	priority_queue<int, vector<int>, greater<int>> q1;
	q1.push(1);
	q1.push(3);
	q1.push(2);
	while (!q1.empty()) {
		cout << q1.top() << " ";
		q1.pop();
	}
}

// set 有序集合
inline void test_set() {
	// set<Type> name;
	set<int> s1 = { 1, 2, 3, 4, 5 };
	s1.insert(6);
	s1.erase(3);
	for (auto it = s1.cbegin(); it != s1.cend(); it++) cout << *it << " ";
	s1.clear();
}

// map 有序字典，按 key 顺序排列
inline void test_map() {
	// map<Type, Type> name;
	map<string, int> m1 = { { "a", 1 }, { "b", 2 }, { "c", 3 } };
	m1.insert({ "d", 4 });
	m1.erase("b");
	for (auto it = m1.cbegin(); it != m1.cend(); it++) cout << it->first << " " << it->second << " ";
	m1.clear();
}

} // namespace STLTemplate