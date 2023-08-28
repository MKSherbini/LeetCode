#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/implement-stack-using-queues/

class ImplementStackUsingQueues
{
public:
	// 0 ms, faster than 100% : 6.7 MB, less than 97.83%
	ImplementStackUsingQueues() {

	}

	void push(int x) {
		auto& qq = q2.empty() ? q : q2;
		qq.push(x);
	}

	int pop() {
		auto& qe = q2.empty() ? q2 : q;
		auto& qq = q2.empty() ? q : q2;
		while (size(qq) > 1) {
			qe.push(qq.front());
			qq.pop();
		}
		int x = qq.front();
		qq.pop();

		return x;
	}

	int top() {
		auto& qe = q2.empty() ? q2 : q;
		auto& qq = q2.empty() ? q : q2;
		while (size(qq) > 1) {
			qe.push(qq.front());
			qq.pop();
		}
		int x = qq.front();
		qe.push(qq.front());
		qq.pop();

		return x;
	}

	bool empty() {
		auto& qq = q2.empty() ? q : q2;
		return qq.empty();
	}
private:
	queue<int> q, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * ImplementStackUsingQueues* obj = new ImplementStackUsingQueues();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */