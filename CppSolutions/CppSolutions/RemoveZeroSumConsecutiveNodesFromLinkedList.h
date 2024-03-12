#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

class RemoveZeroSumConsecutiveNodesFromLinkedList
{
public:
	// 4 ms, faster than 90.44% : 14.8 MB, less than 49.07%
	ListNode* solution(ListNode* head) {
		auto it = new ListNode(0, head);
		head = it;

		int sum = 0;
		unordered_map<int, ListNode*> sums;

		while (it != nullptr) {
			sum += it->val;
			if (sums.count(sum)) {
				auto it2 = sums[sum]->next;
				int sum2 = sum + it2->val;
				while (sum2 != sum) {
					sums.erase(sum2);
					it2 = it2->next;
					sum2 += it2->val;
				}

				sums[sum]->next = it->next;
			}
			else
				sums[sum] = it;
			it = it->next;
		}

		return head->next;
	}

	// 3 ms, faster than 97.29% : 14.8 MB, less than 49.07%
	ListNode* solution3(ListNode* head) {
		auto it = new ListNode(0, head);
		head = it;

		int sum = 0;
		unordered_map<int, ListNode*> sums;
		sums[0] = it;

		while (it != nullptr) {
			sum += it->val;
			sums[sum] = it;
			it = it->next;
		}

		sum = 0;
		it = head;
		while (it) {
			sum += it->val;
			it->next = sums[sum]->next;
			it = it->next;
		}

		return head->next;
	}

	// 3 ms, faster than 97.32% : 13 MB, less than 81.69%
	ListNode* solution2(ListNode* head) {
		auto it = new ListNode(0, head);
		head = it;

		while (it) {
			int sum = 0;
			auto it2 = it->next;

			while (it2) {
				sum += it2->val;
				if (!sum) it->next = it2->next;
				it2 = it2->next;
			}
			it = it->next;
		}

		return head->next;
	}
	vector<vector<int>> output = {
		{3,1},
		{1,2,4},
		{1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,-3,3,1},
		{1,2,3,-3,4},
		{1,2,3,-3,-2}
	};
};