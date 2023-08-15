#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/partition-list/

class PartitionList
{
public:
	// 0 ms, faster than 100% : 10.2 MB, less than 83.57%
	ListNode* solution(ListNode* head, int x) {
		ListNode* smaller = NULL;
		ListNode* smallerSt = NULL;
		ListNode* larger = NULL;
		ListNode* largerSt = NULL;

		while (head) {
			if (head->val < x) {
				if (!smaller) smaller = head, smallerSt = smaller;
				else smaller->next = head, smaller = smaller->next;
			}
			else {
				if (!larger) larger = head, largerSt = larger;
				else larger->next = head, larger = larger->next;
			}
			head = head->next;
		}
		if (larger) larger->next = NULL;

		if (smaller) {
			smaller->next = largerSt;
			return smallerSt;
		}
		else {
			return largerSt;
		}
	}

	// 0 ms, faster than 100% : 10.1 MB, less than 99.85%
	ListNode* solution(ListNode* head, int x) {
		if (!head) return head;

		ListNode* cur = head, * prev = NULL;

		while (cur && cur->val >= x)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!cur) return head;

		if (prev) {
			prev->next = cur->next;
			cur->next = head;
			head = cur;
			cur = prev->next;
		}

		auto smallsIT = head;

		while (cur)
		{
			if (cur->val < x && prev)
			{
				if (prev == smallsIT) {
					smallsIT = cur;
					prev = cur;
					cur = cur->next;
					continue;
				}
				prev->next = cur->next;
				cur->next = smallsIT->next;
				smallsIT->next = cur;
				smallsIT = cur;
				cur = prev->next;
			}
			else {
				prev = cur;
				cur = cur->next;
			}
		}

		return head;
	}
	vector<vector<int>> output = {
		{1,2,2,4,3,5},
		{1,2}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,4,3,2,5,2},
		{2,1}
	};
	vector<int> input2 = {
		3,
		2
	};
};