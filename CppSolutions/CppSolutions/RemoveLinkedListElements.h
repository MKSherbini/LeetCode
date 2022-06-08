#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-linked-list-elements/

class RemoveLinkedListElements
{
public:
	// 22 ms, faster than 90.82% : 14.9 MB, less than 96.11%
	ListNode* solution(ListNode* head, int val) {
		if (!head) return head;

		ListNode* temp = head->next;
		ListNode* prev = head;
		while (temp) {
			if (temp->val == val)
				prev->next = temp->next;
			else
				prev = prev->next;
			temp = temp->next;
		}

		return head->val == val ? head->next : head;
	}

	vector<vector<int>> output = {
		{1,2,3,4,5},
		{},
		{}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,6,3,4,5,6},
		{},
		{7,7,7,7}
	};
	vector<int> input2 = {
		6,
		1,
		7
	};
};