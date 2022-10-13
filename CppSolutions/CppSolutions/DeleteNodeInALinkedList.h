#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/delete-node-in-a-linked-list/

class DeleteNodeInALinkedList
{
public:
	// 10 ms, faster than 97.65% : 7.5 MB, less than 92.32%
	void solution(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
	vector<vector<int>> output = {
		{4,1,9},
		{4,5,9}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{4,5,1,9},
		{4,5,1,9}
	};
	vector<int> input2 = {
		5,
		1
	};
};