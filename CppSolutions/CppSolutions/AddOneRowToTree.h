#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/add-one-row-to-tree/

class AddOneRowToTree
{
public:
	// 14 ms, faster than 98.53% : 24.7 MB, less than 98.26%
	TreeNode* solution(TreeNode* root, int val, int depth) {
		if (depth == 1)
			return new TreeNode(val, root, NULL);
		f(root, depth - 2, val);
		return root;
	}
	void f(TreeNode* node, int depth, int val) {
		if (!node) return;

		if (depth == 0) {
			node->left = new TreeNode(val, node->left, NULL);
			node->right = new TreeNode(val, NULL, node->right);
			return;
		}
		f(node->right, depth - 1, val);
		f(node->left, depth - 1, val);
	}
	vector<vector<int>> output = {
		{4,1,1,2,NULL,NULL,6,3,1,5},
		{4,2,NULL,1,1,3,NULL,NULL,1}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{4,2,6,3,1,5},
		{4,2,NULL,3,1}
	};
	vector<int> input2 = {
		1,
		1
	};
	vector<int> input3 = {
		2,
		3
	};
};