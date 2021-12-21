#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MergeTwoSortedLists
{
public:
	// 4 ms, faster than 94.66% : 14.8 MB, less than 49.23%
	ListNode* solution(ListNode* list1, ListNode* list2) {
		if (!list1)return list2;
		if (!list2)return list1;

		ListNode* root;
		if (list1->val < list2->val)
			root = list1, list1 = list1->next;
		else
			root = list2, list2 = list2->next;

		ListNode* ret = root;

		while (list1 && list2)
			if (list1->val < list2->val)
				root->next = list1, root = list1, list1 = list1->next;
			else
				root->next = list2, root = list2, list2 = list2->next;

		while (list1)
			root->next = list1, root = list1, list1 = list1->next;

		while (list2)
			root->next = list2, root = list2, list2 = list2->next;

		return ret;
	}

	// 4 ms, faster than 94.66% : 14.7 MB, less than 99.18%
	ListNode* solution2(ListNode* list1, ListNode* list2) {
		if (!list1)	return list2;
		if (!list2)	return list1;

		if (list1 && list2)
			if (list1->val < list2->val)
				return list1->next = solution2(list1->next, list2), list1;
			else
				return list2->next = solution2(list1, list2->next), list2;

		return NULL;
	}
};

