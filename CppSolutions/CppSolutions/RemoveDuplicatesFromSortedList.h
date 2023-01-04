#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-list/?envType=study-plan&id=data-structure-i

class RemoveDuplicatesFromSortedList
{
public:
	// 7 ms, faster than 96.96% : 11.5 MB, less than 81.76%
	ListNode* solution(ListNode* head) {
		if (!head) return head;

		auto cur = head->next, prev = head;

		while (cur) {
			if (cur->val == prev->val) {
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
			}
			else {
				prev = cur;
				cur = prev->next;
			}
		}

		return head;
	}
	vector<vector<int>> output = {
		{1,2},
		{1,2,3}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,2},
		{1,1,2,3,3}
	};
};