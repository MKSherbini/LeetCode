#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-maximum-path-sum/

class BinaryTreeMaximumPathSum
{
public:
	// 26 ms, faster than 93.18% : 27.5 MB, less than 91.85%
	int solution(TreeNode* root) {
		int ans = INT_MIN;
		f(root, ans);
		return ans;
	}

	int f(TreeNode* node, int& ans) {
		if (!node) return 0;

		int l = f(node->left, ans), r = f(node->right, ans);
		ans = max(ans, node->val + max(l, 0) + max(r, 0));
		Printer::print(ans, node->val, l, r);

		return node->val + max(max(l, r), 0);
	}


	vector<int> output = {
		6,
		42
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3},
		{-10,9,20,NULL,NULL,15,7}
	};
};