#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class MaximumTwinSumOfALinkedList
{
public:
	// 248 ms, faster than 90.13% : 116.5 MB, less than 99.29%
	int solution(ListNode* head) {
		auto slow = head, fast = head->next;
		ListNode* prev = NULL;
		while (fast->next) {
			fast = fast->next->next;

			auto t = slow;
			slow = slow->next;
			t->next = prev;
			prev = t;
		}
		
		fast = slow->next;
		slow->next = prev;

		int ans = 0;
		while (fast) {
			ans = max(ans, fast->val + slow->val);
			fast = fast->next;
			slow = slow->next;
		}

		return ans;
	}
	vector<int> output = {
		6,
		7,
		100001
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,4,2,1},
		{4,2,2,3},
		{1,100000}
	};
};