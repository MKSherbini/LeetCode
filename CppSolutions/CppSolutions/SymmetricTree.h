#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/symmetric-tree/

class SymmetricTree
{
public:
	// 5 ms, faster than 72.71% : 16.2 MB, less than 94.82%
	bool solution(TreeNode* root) {
		return f(root->left, root->right);
	}
	bool f(TreeNode* l, TreeNode* r) {
		if (!l ^ !r) return false;
		if (!l) return true;

		return l->val == r->val && f(l->left, r->right) && f(l->right, r->left);
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,3,4,4,3},
		{1,2,2,NULL,3,NULL,3}
	};
};