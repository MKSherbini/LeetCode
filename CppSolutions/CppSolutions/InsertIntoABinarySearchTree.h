#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/insert-into-a-binary-search-tree/

class InsertIntoABinarySearchTree
{
public:
	// 72 ms, faster than 99.96% : 56.8 MB, less than 99.03%
	TreeNode* solution(TreeNode* root, int val) {
		auto node = new TreeNode(val);
		if (!root) return node;
		f(root, node);
		return root;
	}

	void f(TreeNode* tree, TreeNode*& node) {
		if (!tree || !node) return;

		if (node->val > tree->val)
			if (!tree->right)
				tree->right = node, node = NULL;
			else
				return f(tree->right, node);
		if (!tree->left)
			tree->left = node, node = NULL;
		else
			return f(tree->left, node);
	}
	vector<vector<int>> output = {
		{4,2,7,1,3,5},
		{40,20,60,10,30,50,70,NULL,NULL,25},
		{4,2,7,1,3,5}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{4,2,7,1,3},
		{40,20,60,10,30,50,70},
		{4,2,7,1,3,NULL,NULL,NULL,NULL,NULL,NULL}
	};
	vector<int> input2 = {
		5,
		25,
		5
	};
};