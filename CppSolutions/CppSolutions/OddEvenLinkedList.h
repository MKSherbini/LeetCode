#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/odd-even-linked-list/

class OddEvenLinkedList
{
public:
	// 11 ms, faster than 95.59% : 10.4 MB, less than 96.54%
	ListNode* solution(ListNode* head) {
		if (!head) return head;

		auto evens = head->next, evensIt = evens, odds = head, it = head;
		it = evens;
		if (it) it = it->next;

		while (it) {
			odds->next = it;
			odds = odds->next;
			evensIt->next = it->next;
			evensIt = evensIt->next;
			it = evensIt;
			if (it) it = it->next;
		}

		odds->next = evens;

		return head;
	}
	vector<vector<int>> output = {
		{1,3,5,2,4},
		{2,3,6,7,1,5,4}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{2,1,3,5,6,4,7}
	};
};