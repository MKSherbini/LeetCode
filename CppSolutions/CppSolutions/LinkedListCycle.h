#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class LinkedListCycle
{
public:
	// 7 ms, faster than 96.92% : 7.8 MB, less than 96%
	bool solution(ListNode* head) {
		auto* fast = head;

		while (fast)
		{
			fast = fast->next;
			if (!fast) break;
			fast = fast->next;
			head = head->next;
			if (fast == head) return true;
		}

		return false;
	}
	vector<bool> output = {
		true,
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{3,2,0,-4},
		{1,2},
		{1}
	};
	vector<int> input2 = {
		1,
		0,
		-1
	};
};