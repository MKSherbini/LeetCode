#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class MinimumDistanceBetweenBstNodes
{
public:
	// 0 ms, faster than 100% : 9.8 MB, less than 30.06%
	int solution(TreeNode* root) {
		set<int> s;
		f(root, s);
		auto last = begin(s), it = next(last);
		int ans = *it - *last;
		while (it != end(s))
			ans = min(ans, *it - *last), last = it, ++it;

		return ans;
	}
	void f(TreeNode* root, set<int>& s) {
		if (!root) return;

		s.insert(root->val);
		f(root->left, s), f(root->right, s);
	}
	vector<int> output = {
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,2,6,1,3},
		{1,0,48,NULL,NULL,12,49}
	};
};