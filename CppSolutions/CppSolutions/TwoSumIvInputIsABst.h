#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class TwoSumIvInputIsABst
{
public:
	// 42 ms, faster than 93.23% : 35.9 MB, less than 98.68%
	bool solution(TreeNode* root, int k) {
		this->root = root;
		this->k = k;
		return f(root);
	}
	bool f(TreeNode* node) {
		if (!node) return 0;

		bool ret = f(root, node, k - node->val);
		if (ret) return ret;
		ret |= f(node->left);
		if (ret) return ret;
		ret |= f(node->right);
		return ret;
	}
	TreeNode* root;
	int k;
	bool f(TreeNode* node, TreeNode* other, int val) {
		if (!node) return 0;

		if (val == node->val && other != node) return 1;
		if (val < node->val) return f(node->right, other, val);
		return f(node->left, other, val);
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{5,3,6,2,4,NULL,7},
		{5,3,6,2,4,NULL,7}
	};
	vector<int> input2 = {
		9,
		28
	};
};