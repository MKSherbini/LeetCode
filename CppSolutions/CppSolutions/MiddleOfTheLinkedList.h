#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/middle-of-the-linked-list/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MiddleOfTheLinkedList
{
public:
	// 0 ms	7.1 MB
	ListNode* solution(ListNode* it2) {
		auto it = it2;
		while (it2->next && it2->next->next)
			it2 = it2->next->next, it = it->next;
		if (it2->next) it = it->next;
		return it;
	}

	// 0 ms	7 MB
	ListNode* solution2(ListNode* head) {
		auto it = head, it2 = head;
		while (it2->next && it2->next->next)
			it2 = it2->next->next, it = it->next;
		if (it2->next) it = it->next;
		return it;
	}
};

