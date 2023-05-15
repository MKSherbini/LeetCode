#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class SwappingNodesInALinkedList
{
public:
	// 672 ms, faster than 72.53% : 180 MB, less than 87.37%
	ListNode* solution(ListNode* head, int k) {
		auto slow = head, fast = head;

		int i = 1;
		while (true) {
			if (k == i) break;
			i++;
			fast = fast->next;
		}
		auto x = fast;

		fast = fast->next;
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}

		int t = slow->val;
		slow->val = x->val;
		x->val = t;

		return head;
	}
	vector<vector<int>> output = {
		{1,4,3,2,5},
		{7,9,6,6,8,7,3,0,9,5}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{7,9,6,6,7,8,3,0,9,5}
	};
	vector<int> input2 = {
		2,
		5
	};
};