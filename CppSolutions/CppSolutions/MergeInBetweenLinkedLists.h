#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-in-between-linked-lists/

class MergeInBetweenLinkedLists
{
public:
	// 169 ms, faster than 85.5% : 97.9 MB, less than 97.82%
	ListNode* solution(ListNode* list1, int a, int b, ListNode* list2) {
		a--;
		b -= a;
		auto it = list1, it2 = list1;
		while (b--) it2 = it2->next;
		while (a--) it = it->next, it2 = it2->next;

		it->next = list2;
		while (list2->next) list2 = list2->next;
		list2->next = it2->next;

		return list1;
	}
	vector<vector<int>> output = {
		{10,1,13,1000000,1000001,1000002,5},
		{0,1,1000000,1000001,1000002,1000003,1000004,6}
	};
	static constexpr int const& inputs = 4;
	vector<vector<int>> input1 = {
		{10,1,13,6,9,5},
		{0,1,2,3,4,5,6}
	};
	vector<int> input2 = {
		3,
		2
	};
	vector<int> input3 = {
		4,
		5
	};
	vector<vector<int>> input4 = {
		{1000000,1000001,1000002},
		{1000000,1000001,1000002,1000003,1000004}
	};
};