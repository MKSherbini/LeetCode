#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/implement-queue-using-stacks/

class ImplementQueueUsingStacks
{
public:

	// 0 ms, faster than 100% : 7 MB, less than 89.46%
	ImplementQueueUsingStacks() {

	}

	void push(int x) {
		while (!st2.empty())
			st.push(st2.top()), st2.pop();
		st.push(x);
	}

	int pop() {
		int ret = peek();
		st2.pop();
		return ret;
	}

	int peek() {
		while (!st.empty())
			st2.push(st.top()), st.pop();

		int ret = st2.top();
		return ret;
	}

	bool empty() {
		return st.empty() && st2.empty();
	}

private:
	stack<int> st, st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */