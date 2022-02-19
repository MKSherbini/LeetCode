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

//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class RemoveDuplicatesFromSortedList2
{
public:
	//
	ListNode* solution(ListNode* head) {
		ListNode* head2 = head, * prev = head;
		bool removeHead = 0;
		while (head) {
			if (head->next && head->next->val == head->val) {
				while (head->next->val == head->val)
					head->next = head->next->next;
				if (prev != head) {
					prev->next = head->next;
					head = prev->next;
				}
				else {
					removeHead = 1;
				}
			}
			else {
				prev = head;
				head = head->next;
			}
		}
		if (removeHead) head2->next;
		return head2;
	}
	vector<vector<int>> output = {
		{1,2,5},
		{2,3}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,3,4,4,5},
		{1,1,1,2,3}
	};
};