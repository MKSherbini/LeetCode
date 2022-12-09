#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

class MaximumDifferenceBetweenNodeAndAncestor
{
public:
	// 3 ms, faster than 97.1% : 9.6 MB, less than 99.78%
	int solution(TreeNode* root) {
		return f(root, root->val, root->val);
	}
	int f(TreeNode* node, int mn, int mx) {
		if (!node) return -OO;

		mn = min(mn, node->val);
		mx = max(mx, node->val);

		int ret = max(mx - node->val, node->val - mn);

		ret = max(ret, f(node->left, mn, mx));
		ret = max(ret, f(node->right, mn, mx));

		return ret;
	}
	const int OO = 1e5;

	vector<int> output = {
		7,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{8,3,10,1,6,NULL,14,NULL,NULL,4,7,13},
		{1,NULL,2,NULL,0,3}
	};
};