#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/validate-binary-search-tree/

class ValidateBinarySearchTree
{
public:
	// 3 ms, faster than 99.83% : 21.5 MB, less than 93.01%
	bool solution(TreeNode* root) {
		return f(root, LLONG_MIN, LLONG_MAX);
	}

	bool f(TreeNode* node, long long mn, long long mx) {
		if (!node) return true;

		return node->val > mn && node->val < mx &&
			(!node->left || node->left->val < node->val) &&
			(!node->right || node->right->val > node->val) &&
			f(node->left, mn, node->val) && f(node->right, node->val, mx);
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,1,3},
		{5,1,4,NULL,NULL,3,6}
	};
};