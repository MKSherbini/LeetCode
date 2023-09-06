#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/split-linked-list-in-parts/

class SplitLinkedListInParts
{
public:
	// 2 ms, faster than 96.57% : 8.7 MB, less than 86.06%
	vector<ListNode*> solution(ListNode* head, int k) {
		int n = 0;
		auto it = head;
		while (it) {
			n++, it = it->next;
		}

		it = head;
		vector<ListNode*> ans(k, NULL);

		int len = n / k, extras = n % k;
		int i = 0;
		while (it) {
			int stride = len + (extras-- > 0);
			auto prev = it;
			ans[i++] = it;
			for (size_t j = 0; j < stride; j++) {
				prev = it, it = it->next;
			}
			prev->next = NULL;
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1},{2},{3},{},{}},
		{{1,2,3,4},{5,6,7},{8,9,10}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,2,3,4,5,6,7,8,9,10}
	};
	vector<int> input2 = {
		5,
		3
	};
};