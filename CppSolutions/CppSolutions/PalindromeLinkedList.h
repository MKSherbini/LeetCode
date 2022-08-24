#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/palindrome-linked-list/

class PalindromeLinkedList
{
public:
	// 232 ms, faster than 96.29% : 113.9 MB, less than 91.66%
	bool solution(ListNode* head) {
		if (!head->next) return true;
		ListNode* fast = head, * slow = head;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next ? fast->next->next : fast->next;
		}
		ListNode* prev = slow;
		slow = slow->next;
		prev->next = NULL;

		while (slow)
		{
			auto nxt = slow->next;
			slow->next = prev;
			prev = slow;
			slow = nxt;
		}


		while (head && prev && head->val == prev->val)
		{
			// cout << head->val << " " << prev->val << endl;
			head = head->next;
			prev = prev->next;
		}

		return !head || !prev;
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,1},
		{1,2}
	};
};