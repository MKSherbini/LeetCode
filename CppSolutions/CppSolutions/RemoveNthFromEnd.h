#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class RemoveNthFromEnd
{
public:
	// 0 ms, faster than 100.00% : 10.6 MB, less than 73.81%
	ListNode* solution(ListNode* head, int n) {
		auto it = head, slowerIt = it;
		for (int i = 0; i < n; i++)
			it = it->next;
		if (!it) return head->next;
		slowerIt = head;
		while (it->next)
			it = it->next, slowerIt = slowerIt->next;
		slowerIt->next = slowerIt->next->next;
		return head;
	}
};

