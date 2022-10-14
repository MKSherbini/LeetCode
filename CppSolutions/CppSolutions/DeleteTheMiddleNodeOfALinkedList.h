#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

class DeleteTheMiddleNodeOfALinkedList
{
public:
	// 1014 ms, faster than 99.36% : 294.2 MB, less than 98.95%
	ListNode* solution(ListNode* head) {
		ListNode* slo = head, * fast = head->next;
		if (fast)
			fast = fast->next;


		while (fast)
		{
			slo = slo->next;
			fast = fast->next;
			if (fast)
				fast = fast->next;
		}

		slo->next = slo->next->next;
		return head;
	}
	vector<vector<int>> output = {
		{1,3,4,1,2,6},
		{1,2,4},
		{2}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,4,7,1,2,6},
		{1,2,3,4},
		{2,1}
	};
};