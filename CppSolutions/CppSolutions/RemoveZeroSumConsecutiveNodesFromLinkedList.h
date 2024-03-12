#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

class RemoveZeroSumConsecutiveNodesFromLinkedList
{
public:
	// 3 ms, faster than 97.32% : 13 MB, less than 81.69%
	ListNode* solution(ListNode* head) {
		auto it = new ListNode(0, head);
		head = it;

		while (it) {
			int sum = 0;
			auto it2 = it->next;

			while (it2) {
				sum += it2->val;
				if (!sum) it->next = it2->next;
				it2 = it2->next;
			}
			it = it->next;
		}

		return head->next;
	}
	vector<vector<int>> output = {
		{3,1},
		{1,2,4},
		{1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,-3,3,1},
		{1,2,3,-3,4},
		{1,2,3,-3,-2}
	};
};