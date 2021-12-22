#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-linked-list/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ReverseLinkedList
{
public:
	// 4 ms, faster than 95.63% : 8.3 MB, less than 77.54%
	ListNode* solution(ListNode* head) {
		return recurse(head, NULL);
	}

	ListNode* recurse(ListNode* cur, ListNode* next) {
		if (!cur) return next;
		auto t = cur->next;
		cur->next = next;

		return recurse(t, cur);
	}

	// 4 ms, faster than 95.63% : 8.2 MB, less than 97.51% 
	ListNode* solution2(ListNode* head) {
		ListNode* cur = head, * next = NULL;
		while (cur) {
			auto t = cur->next;
			cur->next = next;
			next = cur;
			cur = t;
		}
		return next;
	}

};

