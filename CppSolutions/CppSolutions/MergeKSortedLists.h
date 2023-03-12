#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-k-sorted-lists/

class MergeKSortedLists
{
public:
	// 19 ms, faster than 93.2% : 13.2 MB, less than 81.27%
	ListNode* solution(vector<ListNode*> lists) {
		ListNode* ans = new ListNode();

		auto cmp = [](ListNode* x, ListNode* y) { return x->val < y->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

		for (auto l : lists)
			if (l)
				q.push(l);

		auto it = ans;
		while (!q.empty()) {
			auto l = q.top();
			q.pop();
			if (l->next)
				q.push(l->next);
			it = it->next = l;
		}

		return ans->next;
	}
	vector<vector<int>> output = {
		{1,1,2,3,4,4,5,6},
		{},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,4,5},{1,3,4},{2,6}},
		{},
		{{}}
	};
};