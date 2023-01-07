#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/search-in-a-binary-search-tree/

class SearchInABinarySearchTree
{
public:
	// 27 ms, faster than 99.79% : 34.6 MB, less than 94.42%
	TreeNode* solution(TreeNode* root, int val) {
		return f(root, val);
	}

	TreeNode* f(TreeNode* node, int val) {
		if (!node) return node;

		if (node->val == val) return node;

		if (val > node->val) return f(node->right, val);

		return f(node->left, val);
	}
	vector<vector<int>> output = {
		{2,1,3},
		{}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{4,2,7,1,3},
		{4,2,7,1,3}
	};
	vector<int> input2 = {
		2,
		5
	};
};