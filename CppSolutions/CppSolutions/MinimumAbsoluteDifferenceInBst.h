#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-absolute-difference-in-bst/

class MinimumAbsoluteDifferenceInBst
{
public:
	// 19 ms, faster than 66.97% : 26.8 MB, less than 6.32%
	int solution(TreeNode* root) {
		f(root);
		int ans = 1e7;
		int last = -1e7;
		for (auto x : s)
			ans = min(ans, x - last), last = x;
		return ans;
	}
	set<int> s;
	void f(TreeNode* node) {
		if (!node) return;

		s.insert(node->val);
		f(node->left);
		f(node->right);
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