#pragma once
#include "stdc++.h"
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedListSupport
{
public:
	static ListNode* create(vector<int> v) {
		ListNode* root = NULL;
		for (int i = v.size() - 1; i >= 0; i--)
			root = new ListNode(v[i], root);

		return root;
	}

	static ListNode* create(int v) {
		return v ? new ListNode(v) : NULL;
	}

	static ListNode* reverse(ListNode* head) {
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
};

