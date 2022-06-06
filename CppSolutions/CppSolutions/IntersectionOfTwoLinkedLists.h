#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/intersection-of-two-linked-lists/


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class IntersectionOfTwoLinkedLists
{
public:
	// 53 ms, faster than 73.19% : 17.1 MB, less than 15.93%
	ListNode* solution(ListNode* headA, ListNode* headB) {
		unordered_set<ListNode*> vis;

		auto t = headA;
		while (t)
			vis.insert(t), t = t->next;

		t = headB;
		int f = 0;
		while (t)
			if (vis.count(t)) {
				f = 1; break;
			}
			else
				t = t->next;

		return f ? t : NULL;
	}

	ListNode* reverse(ListNode* head) {
		ListNode* nxt = NULL;
		while (head)
		{
			auto t = head->next;
			head->next = nxt;
			nxt = head;
			head = t;
		}
		return nxt;
	}
	void print(ListNode* head) {
		auto t = head;
		while (t)
		{
			cout << t->val << " ";
			t = t->next;
		}
		cout << endl;
	}
};