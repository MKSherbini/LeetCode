#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-linked-list-ii/

class ReverseLinkedListII
{
public:
	// 0 ms, faster than 100% : 7.4 MB, less than 93.11%
	ListNode* solution(ListNode* head, int left, int right) {
		ListNode* cur = head, * prev = NULL;

		for (size_t i = 1; i < left; i++)
		{
			prev = cur;
			cur = cur->next;
		}

		auto prestart = prev;
		auto end = cur;

		for (size_t i = left; i <= right; i++)
		{
			auto nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}

		end->next = cur;
		if (!prestart)
			return prev;

		prestart->next = prev;
		return head;
	}
	vector<vector<int>> output = {
		{1,4,3,2,5},
		{5}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{5}
	};
	vector<int> input2 = {
		2,
		1
	};
	vector<int> input3 = {
		4,
		1
	};
};