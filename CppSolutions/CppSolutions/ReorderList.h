#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reorder-list/

class ReorderList
{
public:
	// 15 ms, faster than 98.75% : 21.1 MB, less than 99.47%
	void solution(ListNode* head) {
		if (!head->next) return;
		ListNode* fast = head, * slow = head;
		ListNode* prev = slow;
		while (fast) {
			prev = slow;
			slow = slow->next;
			fast = fast->next ? fast->next->next : fast->next;
		}
		prev->next = NULL;
		prev = slow;
		slow = slow->next;
		prev->next = NULL;

		while (slow) {
			auto nxt = slow->next;
			slow->next = prev;
			prev = slow;
			slow = nxt;
		}

		auto it = head->next, it2 = prev;
		while (it && it2) {
			auto nxt2 = it2->next;
			head->next = it2;
			it2->next = it;
			if(it) head = it;
			it = it->next, it2 = nxt2;
		}
		if (it2) head->next = it2;
	}
	vector<vector<int>> output = {
		{1,4,2,3},
		{1,5,2,4,3}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{1,2,3,4,5}
	};
};