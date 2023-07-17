#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/add-two-numbers-ii/

class AddTwoNumbersII
{
public:
	// 23 ms, faster than 98.46% : 71 MB, less than 93.1%
	ListNode* solution(ListNode* l1, ListNode* l2) {
		l1 = reverse(l1), l2 = reverse(l2);

		int c = 0;
		ListNode* it = NULL, * ans = NULL;
		while (l1 && l2) {
			c += l1->val + l2->val;
			if (!it) it = new ListNode(c % 10), ans = it;
			else it->next = new ListNode(c % 10), it = it->next;
			c /= 10;
			l1 = l1->next, l2 = l2->next;
		}
		while (it && l1) {
			c += l1->val;
			it->next = new ListNode(c % 10), it = it->next;
			c /= 10;
			l1 = l1->next;
		}
		while (it && l2) {
			c += l2->val;
			it->next = new ListNode(c % 10), it = it->next;
			c /= 10;
			l2 = l2->next;
		}

		if (it && c)
			it->next = new ListNode(c);

		return reverse(ans);
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
	vector<vector<int>> output = {
		{7,8,0,7},
		{8,0,7},
		{0}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{7,2,4,3},
		{2,4,3},
		{0}
	};
	vector<vector<int>> input2 = {
		{5,6,4},
		{5,6,4},
		{0}
	};
};