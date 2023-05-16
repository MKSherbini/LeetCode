#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/swap-nodes-in-pairs/

class SwapNodesInPairs
{
public:
	// 0 ms, faster than 100% : 7.4 MB, less than 88.23%
	ListNode* solution(ListNode* head) {
		if (!head || !head->next) return head;

		auto slow = head, fast = head->next;
		slow->next = fast->next;
		fast->next = slow;
		head = fast;
		auto prev = slow, it = slow->next;
		while (it && it->next) {
			slow = it, fast = it->next;
			slow->next = fast->next;
			fast->next = slow;
			prev->next = fast;
			prev = slow;
			it = slow->next;
		}

		return head;
	}
	vector<vector<int>> output = {
		{2,1,4,3},
		{},
		{1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{},
		{1}
	};
};