#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/linked-list-cycle-ii/

class LinkedListCycleIi
{
public:
	// 4 ms, faster than 97.1% : 7.4 MB, less than 99.05%
	ListNode* solution(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (!fast) return NULL;
			fast = fast->next;

			if (fast == slow) {
				do {
					slow->val = slow->val > 0 ? slow->val + 1000000 : slow->val - 1000000;
					slow = slow->next;
				} while (slow != fast);

				while (abs(head->val) <= 1000000) {
					head = head->next;
				}
				return head;
			}
		}

		return NULL;
	}
	vector<int> output = {
		3,
		1,
		NULL,
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,2,0,-4},
		{1,2},
		{1}
	};
};