/*
155. Min Stack [Medium - 4]
*/
#include "pub_template.h"
#include <forward_list>	// C++ 11引入

// 解法一：使用前向链表实现
class MinStack_ForwardList {
private:
	vector<int> stk;
	forward_list<int> flst;
public:
	MinStack_ForwardList() {
		stk.clear();
		flst.clear();
	}

	void push(int val) {
		stk.push_back(val);
		if (flst.empty()|| flst.front() >= val) {
			flst.push_front(val);
			return;
		}
		forward_list<int>::iterator it = flst.begin(), pre = flst.before_begin();
		while (it != flst.end() && *it < val) it++, pre++;
		flst.insert_after(pre, val);
	}

	void pop() {
		if (stk.empty()) return;
		int temp = stk.back();
		stk.pop_back();
		forward_list<int>::iterator it = flst.begin(), pre = flst.before_begin();
		while (it != flst.end() && *it != temp) it++, pre++;
		flst.erase_after(pre);
	}

	int top() {
		return stk.back();
	}

	int getMin() {
		return flst.front();
	}

};

// 解法二：使用两个栈实现
class MinStack {
private:
	stack<int> stk;
	stack<int> min_stk;
public:
	MinStack() {
		min_stk.push(INT_MAX);
	}

	void push(int val) {
		stk.push(val);
		min_stk.push(min(min_stk.top(),val));
	}

	void pop() {
		stk.pop();
		min_stk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return min_stk.top();
	}

};

void test() {
	MinStack* obj = new MinStack();

	vector<string> ops = { "MinStack","push","push","push","getMin","pop","top","getMin" };
	vector<int> vals = { INT_MAX,-2,0,-3,INT_MAX,INT_MAX,INT_MAX,INT_MAX };
	for (int i = 0; i < ops.size(); i++) {
		if (ops[i] == "push") obj->push(vals[i]);
		else if (ops[i] == "pop") obj->pop();
		else if (ops[i] == "top") cout << obj->top() << endl;
		else if (ops[i] == "getMin") cout << obj->getMin() << endl;
	}

	delete obj;
}

//int main() {
//	test();
//	return 0;
//}