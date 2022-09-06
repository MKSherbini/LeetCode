#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-pruning/

class BinaryTreePruning
{
public:
	// 0 ms, faster than 100% : 8.5 MB, less than 100%
	TreeNode* solution(TreeNode* root) {
		return f(root) ? root : NULL;
	}
	bool f(TreeNode* node) {
		if (!node) return 0;

		bool l = f(node->left), r = f(node->right);

		if (!l) node->left = NULL;
		if (!r) node->right = NULL;

		return l || r || node->val;
	}
	vector<vector<int>> output = {
		{1,NULL,0,NULL,1},
		{1,NULL,1,NULL,1},
		{1,1,0,1,1,NULL,1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,NULL,0,0,1},
		{1,0,1,0,0,0,1},
		{1,1,0,1,1,0,1,0}
	};
};